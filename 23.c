/*
============================================================================
Name : 23.c
Author : Akash Chaudhari
Description : Write a program to print the maximum number of files can be opened within a process and size of a pipe (circular buffer).
Date: 20th Sep, 2024.
============================================================================
*/

#include <unistd.h>
#include <stdio.h>

int main()
{
    long pipe_size, maxopenfiles;

    pipe_size = pathconf(".", _PC_PIPE_BUF);

    maxopenfiles = sysconf(_SC_OPEN_MAX);

    printf("Max size of pipe : %ld\n", pipe_size);
    printf("Max file can be opened : %ld\n", maxopenfiles);

    return 0;
}

/*
============================================================================
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ cc 23.c -o 23
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ./23
Max size of pipe : 4096
Max file can be opened : 1048576
============================================================================
*/
