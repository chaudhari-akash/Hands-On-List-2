/*
============================================================================
Name : 14.c
Author : Akash Chaudhari
Description : Write a simple program to create a pipe, write to the pipe, read from pipe and display on the monitor.
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int fd[2];
	char buf[14];
	pipe(fd);
	if (!fork())
	{
		close(fd[0]);
		printf("Child writing...\n");
		write(fd[1], "Hello There", 11);
	}
	else
	{
		close(fd[1]);
		read(fd[0], buf, 11);
		printf("Parent Reading : %s\n", buf);
	}
}

/*
============================================================================
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ cc 14.c -o 14
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ./14
Child writing...
parent reading : Hello There
============================================================================
*/