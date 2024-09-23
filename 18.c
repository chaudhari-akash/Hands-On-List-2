/*
============================================================================
Name : 18.c
Author : Akash Chaudhari
Description : Write a program to find out total number of directories on the pwd. execute ls -l | grep ^d | wc ? Use only dup2.
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int fd1[2], fd2[2];
    pipe(fd1);
    pipe(fd2);

    if (!fork())
    {
        dup2(fd1[1], STDOUT_FILENO);
        close(fd1[0]);
        close(fd1[1]);
        execl("/bin/ls", "ls", "-l", NULL);
        perror("execl failed");
        exit(1);
    }
    if (!fork())
    {
        dup2(fd1[0], STDIN_FILENO);
        dup2(fd2[1], STDOUT_FILENO);
        close(fd1[1]);
        close(fd1[0]);
        close(fd2[0]);
        execl("/bin/grep", "grep", "^d", NULL);
        perror("execl failed");
        exit(1);
    }
    if (!fork())
    {
        dup2(fd2[0], STDIN_FILENO);
        close(fd1[0]);
        close(fd1[1]);
        close(fd2[1]);
        execl("/usr/bin/wc", "wc", NULL);
        perror("execl failed");
        exit(1);
    }
    close(fd1[0]);
    close(fd1[1]);
    close(fd2[0]);
    close(fd2[1]);
    wait(0);
    wait(0);
    wait(0);
    return 0;
}

/*
============================================================================
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ cc 18.c -o 18
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ./18
      1       9      52
============================================================================
*/