/*
 *Filename:pipe.c
 *
 *Description:parent and child process communication
 *
 *Author:rutk1t0r
 *
 *Date:2016.10.07
 *
 *GPL
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

#define STRING "hello world!!"

int main(int argc, char const *argv[])
{
	pid_t pid;
	int pipe_fd[2];
	char buf[BUFSIZ];
	if(pipe(pipe_fd) == -1)
	{
		perror("pipe()");
		exit(1);
	}
	pid = fork();
	if(pid < 0)
	{
		perror("fork()");
		exit(2);
	}
	if(pid == 0)
	{
		printf("child pid is :%d\n", getpid());
		if((read(pipe_fd[0], buf, BUFSIZ)) < 0)
		{
			perror("read()");
			exit(3);
		}
		printf("child read a %s\n", buf);
		bzero(buf, BUFSIZ);
		snprintf(buf, BUFSIZ, "Message from child :My pid is :%d\n", getpid());
		if((write(pipe_fd[1], buf, BUFSIZ)) < 0)
		{
			perror("write()");
			exit(4);
		}
	}
	else if(pid > 0)
	{
		printf("parent pid is :%d\n", getpid());
		snprintf(buf, BUFSIZ, "Message from parent:My pid is:%d\n", getpid());
		if((write(pipe_fd[1], buf, BUFSIZ)) < 0)
		{
			perror("write()");
			exit(1);
		}
		sleep(1);
		bzero(buf, BUFSIZ);
		if((read(pipe_fd[0], buf, BUFSIZ)) < 0)
		{
			perror("read()");
			exit(1);
		}
		printf("Parent read:%s\n", buf);
		wait(NULL);
	}
	return 0;
}