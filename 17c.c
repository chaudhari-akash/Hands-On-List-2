/*
============================================================================
Name : 17a.c
Author : Akash Chaudhari
Description : Write a program to execute ls -l | wc.
                a. use dup
                b. use dup2
                c. use fcntl
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{

    int fd[2];
    pipe(fd);
    if (!fork())
    {
        close(1);
        close(fd[0]);
        fcntl(fd[1], F_DUPFD);
        execl("/bin/ls", "ls", "-l", NULL);
    }
    else
    {
        close(fd[1]);
        close(0);
        fcntl(fd[0], F_DUPFD);
        execl("/bin/wc", "wc", NULL);
    }
}

/*
============================================================================
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ cc 17c.c -o 17c
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ./17c
     59     524    2801
============================================================================
*/