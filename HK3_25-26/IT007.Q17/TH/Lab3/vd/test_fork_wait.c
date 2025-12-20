/*######################################
# University of Information Technology
# IT007 Operating System
# Phạm Ngọc Dũng, 24520346
# File: test_fork_wait.c
######################################*/

#include <sys/wait.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main()
{
	pid_t pid;
	pid = fork();
	if (pid == 0)
		printf("Child process, pid=%d\n", pid);
	else {
		wait(NULL);
		printf("Parent process, pid=%d\n", pid);
	}
	exit(0);
}
