/*######################################
# University of Information Technology
# IT007 Operating System
# Phạm Ngọc Dũng, 24520346
# File: test_system.c
#######################################*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int
main(int argc, char *argv[])
{
	printf("PARENTS | PID = %ld | PPID = %ld\n",
		(long)getpid(), (long)getppid());

	system("./count.sh 10");

	printf("PARENTS | List of arguments: \n");
	for (int i = 1; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}

	exit(0);
}
