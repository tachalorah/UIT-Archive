#include <sys/wait.h>

#include <err.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void handle(int);

int
main(void)
{
	printf("Welcome to IT007, I am 24520346!\n");

	switch (fork()) {
	case -1:
		err(1, "fork");
	case 0:
		execl("./count.sh", "./count.sh", "120", NULL);
		err(2, "execl");
	default:
		signal(SIGINT, handle);
		wait(NULL);
	}

	exit(0);
}

void
handle(int __attribute__((unused)) signal)
{
	printf("count.sh has stopped.\n");
}
