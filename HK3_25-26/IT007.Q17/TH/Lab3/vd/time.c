#include <sys/mman.h>
#include <sys/time.h>
#include <sys/wait.h>

#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
	struct timeval *first, second;

	if (argc < 2)
		errx(0, "Cách dùng: %s <ctrinh> [tham số ...]", argv[0]);

	first = mmap(0, sizeof(struct timeval), PROT_READ | PROT_WRITE,
	    MAP_SHARED | MAP_ANON, -1, 0);
	if (first == MAP_FAILED)
		err(1, "mmap");

	switch (fork()) {
	case -1:
		err(2, "fork");
	case 0:
		gettimeofday(first, NULL);
		execvp(argv[1], &argv[1]);
		err(3, "%s", argv[1]);
	default:
		wait(NULL);
		gettimeofday(&second, NULL);
		timersub(&second, first, first);
		printf("Thời gian thực thi: %ld.%06ld giây.\n", first->tv_sec,
		    first->tv_usec);
	}

	munmap(first, sizeof(struct timeval));
	return 0;
}
