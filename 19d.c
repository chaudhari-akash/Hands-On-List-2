/*
============================================================================
Name : 19d.c
Author : Akash Chaudhari
Description : Create a FIFO file by
                a. mknod command
                b. mkfifo command
                c. use strace command to find out, which command (mknod or mkfifo) is better.
                c. mknod system call
                d. mkfifo library function
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    mkfifo(argv[1], S_IRWXU);

    return 0;
}

/*
============================================================================
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ cc 19d.c -o 19d
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ./19d pipe2
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ls -l | grep ^p
prwxr--r-- 1 akash akash     0 Sep 21 16:31 pipe1
prwxr--r-- 1 akash akash     0 Sep 21 16:33 pipe2
============================================================================
*/