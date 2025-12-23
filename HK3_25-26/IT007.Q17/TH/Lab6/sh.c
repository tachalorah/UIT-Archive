#include <sys/wait.h>

#include <err.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define HISTORY_DEFSIZE 32

typedef struct {
	size_t allocated, count, index;
	char **entries;
} History;

int history_add(History *, const char *);
void history_free(History *);
int history_init(History *, size_t);
char *history_parseback(History *);

void free_arguments(char **);
char **split_arguments(char *);
void handle_io_redirects(char **, int, int);
void parse_and_execute(char **);
void prompt(void);
void signal_handler(int);

int
main(void)
{
	History hist;

	if (history_init(&hist, HISTORY_DEFSIZE) == 0)
		errx(1, "cannot initialize history");
	signal(SIGINT, signal_handler);

	for (;;) {
		size_t linecap = 0;
		char **args, *line = NULL;

		prompt();

		if (getline(&line, &linecap, stdin) == -1) {
			printf("\n");
			free(line);
			break;
		}
		line[strlen(line) - 1] = '\0';
		if ((args = split_arguments(line)) == NULL) {
			free(line);
			continue;
		}
		if (args[0] == NULL) {
			free_arguments(args);
			free(line);
			continue;
		} else if (strcmp(args[0], "exit") == 0) {
			free_arguments(args);
			free(line);
			break;
		} else if (strcmp(args[0], "HF") == 0) {
			free_arguments(args);
			free(line);

			if ((line = history_parseback(&hist)) == NULL) {
				warnx("HF: cannot fetch backward");
				continue;
			}
			if ((args = split_arguments(line)) == NULL) {
				free(line);
				continue;
			}
		} else if (history_add(&hist, line) == 0)
			warnx("cannot add command to history\n");

		parse_and_execute(args);
		free_arguments(args);
		free(line);
	}

	history_free(&hist);
	return 0;
}

void
free_arguments(char **args)
{
	for (size_t i = 0; args[i] != NULL; i++)
		free(args[i]);
	free(args);
}

char **
split_arguments(char *line)
{
	size_t index = 0, maxargs = strlen(line) / 2 + 2;
	char **args, *dupline, *token;

	if ((args = malloc(maxargs * sizeof(char *))) == NULL)
		return NULL;
	if ((dupline = strdup(line)) == NULL) {
		free(args);
		return NULL;
	}

	token = strtok(dupline, " \t");
	while (token != NULL) {
		if ((args[index++] = strdup(token)) == NULL) {
			args[index] = NULL;
			free_arguments(args);
			free(dupline);
			return NULL;
		}
		token = strtok(NULL, " \t");
	}
	args[index] = NULL;
	free(dupline);
	return args;
}

void
handle_io_redirects(char **args, int isfirstcmd, int islastcmd)
{
	for (size_t i = 0; args[i] != NULL; i++) {
		int fd, flags, mode, target;

		if (strcmp(args[i], "<") == 0) {
			if (isfirstcmd == 0)
				errx(1, "invalid redirection");
			flags = O_RDONLY;
			mode = 0;
			target = STDIN_FILENO;
		} else if (strcmp(args[i], ">") == 0) {
			if (islastcmd == 0)
				errx(1, "invalid redirection");
			flags = O_CREAT | O_TRUNC | O_WRONLY;
			mode = 0644;
			target = STDOUT_FILENO;
		} else
			continue;

		if (args[i + 1] == NULL || strcmp(args[i + 1], "<") == 0 ||
		    strcmp(args[i + 1], ">") == 0 ||
		    strcmp(args[i + 1], "|") == 0)
			errx(1, "invalid argument after %s", args[i]);
		if ((fd = open(args[i + 1], flags, mode)) == -1)
			err(1, "%s", args[i + 1]);
		if (dup2(fd, target) == -1)
			err(1, "dup2");
		close(fd);

		free(args[i]);
		free(args[i + 1]);
		size_t j = i;
		for (; args[j + 2] != NULL; j++)
			args[j] = args[j + 2];
		args[j] = NULL;
		args[j + 1] = NULL;
		i--;
	}
}

int
history_add(History *hist, const char *line)
{
	if (hist->count >= hist->allocated) {
		size_t tsize = hist->allocated * 2;
		char **backup = hist->entries;
		char **tptr = realloc(hist->entries, tsize * sizeof(char *));
		if (tptr == NULL) {
			hist->entries = backup;
			return 0;
		}
		hist->allocated = tsize;
		hist->entries = tptr;
	}

	if ((hist->entries[hist->count] = strdup(line)) == NULL)
		return 0;
	hist->index = ++hist->count;
	return 1;
}

void
history_free(History *hist)
{
	for (size_t i = 0; i < hist->count; i++)
		free(hist->entries[i]);
	free(hist->entries);

	hist->allocated = 0;
	hist->count = 0;
	hist->index = 0;
}

int
history_init(History *hist, size_t size)
{
	if (size == 0)
		return 0;
	hist->entries = malloc(size * sizeof(char *));
	if (hist->entries == NULL)
		return 0;

	hist->allocated = size;
	hist->count = 0;
	hist->index = 0;
	return 1;
}

char *
history_parseback(History *hist)
{
	if (hist->count == 0 || hist->index == 0)
		return NULL;
	return strdup(hist->entries[--hist->index]);
}

void
parse_and_execute(char **args)
{
	size_t pcount = 0;
	for (size_t i = 0; args[i] != NULL; i++) {
		if (strcmp(args[i], "|") != 0)
			continue;

		if (i == 0 || args[i + 1] == NULL ||
		    strcmp(args[i + 1], "<") == 0 ||
		    strcmp(args[i + 1], ">") == 0 ||
		    strcmp(args[i + 1], "|") == 0) {
			warnx("invalid piping");
			return;
		}
		pcount++;
	}

	if (pcount == 0) {
		switch (fork()) {
		case -1:
			perror("fork");
			return;
		case 0:
			signal(SIGINT, SIG_DFL);
			handle_io_redirects(args, 1, 1);
			execvp(args[0], args);
			err(1, "%s", args[0]);
		default:
			wait(NULL);
		}
		return;
	}

	pid_t *pids = calloc(pcount + 1, sizeof(pid_t));
	if (pids == NULL) {
		perror("calloc");
		return;
	}
	char ***cmds = calloc(pcount + 1, sizeof(char **));
	if (cmds == NULL) {
		perror("calloc");
		free(pids);
		return;
	}
	size_t start = 0, index = 0;
	for (size_t end = 0;; end++) {
		if (args[end] != NULL && strcmp(args[end], "|") != 0)
			continue;

		size_t size = end - start;
		cmds[index] = malloc((size + 1) * sizeof(char *));
		if (cmds[index] == NULL) {
			perror("malloc");
			goto cleanup;
		}

		for (size_t i = 0; i < size; i++)
			cmds[index][i] = args[start + i];
		cmds[index++][size] = NULL;
		start = end + 1;
		if (args[end] == NULL)
			break;
	}

	for (size_t i = 0; i <= pcount; i++) {
		for (size_t j = 0; cmds[i][j] != NULL; j++) {
			if (strcmp(cmds[i][j], "<") == 0 && i != 0) {
				warnx("invalid redirection");
				goto cleanup;
			}
			if (strcmp(cmds[i][j], ">") == 0 && i != pcount) {
				warnx("invalid redirection");
				goto cleanup;
			}
		}
	}

	int prev_outpipe = -1;
	for (size_t i = 0; i <= pcount; i++) {
		int fildes[2] = { -1, -1 };
		if (i < pcount && pipe(fildes) == -1) {
			perror("pipe");
			goto cleanup;
		}

		pids[i] = fork();
		switch (pids[i]) {
		case -1:
			close(fildes[0]);
			close(fildes[1]);
			perror("fork");
			goto cleanup;
		case 0:
			signal(SIGINT, SIG_DFL);

			if (i == 0)
				handle_io_redirects(cmds[i], 1, 0);
			else {
				if (dup2(prev_outpipe, STDIN_FILENO) == -1)
					err(1, "dup2");
			}
			if (i == pcount)
				handle_io_redirects(cmds[i], 0, 1);
			else {
				if (dup2(fildes[1], STDOUT_FILENO) == -1)
					err(1, "dup2");
			}

			if (prev_outpipe != -1)
				close(prev_outpipe);
			close(fildes[0]);
			close(fildes[1]);

			execvp(cmds[i][0], cmds[i]);
			err(1, "%s", cmds[i][0]);
		default:
			if (prev_outpipe != -1)
				close(prev_outpipe);
			if (i < pcount) {
				close(fildes[1]);
				prev_outpipe = fildes[0];
			}
		}
	}

	for (size_t i = 0; i <= pcount; i++)
		waitpid(pids[i], NULL, 0);
cleanup:
	for (size_t i = 0; cmds[i] != NULL && i <= pcount; i++)
		free(cmds[i]);
	free(cmds);
	free(pids);
}

void
prompt(void)
{
	printf("it007sh> ");
	fflush(stdout);
}

void
signal_handler(int __attribute__((unused)) signal)
{
	printf("\n");
}
