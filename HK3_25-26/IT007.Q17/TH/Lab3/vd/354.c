#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>

#define SIZE 4
#define NAME "shm"

int fd;
char *ptr;

int
main(void)
{
#ifdef PRODUCER
	srand(time(NULL));

#elif CONSUMER
#endif
