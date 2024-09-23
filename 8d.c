/*
============================================================================
Name : 8d.c
Author : Akash Chaudhari
Description : Write a separate program using signal system call to catch the following signals.
                a. SIGSEGV
                b. SIGINT
                c. SIGFPE
                d. SIGALRM (use alarm system call)
                e. SIGALRM (use setitimer system call)
                f. SIGVTALRM (use setitimer system call)
                g. SIGPROF (use setitimer system call)
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void handler()
{
    printf("SIGALRM Caught\n");
    exit(0);
}

void main()
{
    __sighandler_t status;
    alarm(1);
    status = signal(SIGALRM, handler);

    if (status == SIG_ERR)
    {
        perror("Error Occured ");
    }
    else
    {
        while (1)
        {
        }
    }
}

/*
============================================================================
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ cc 8d.c -o 8d
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ./8d
SIGALRM Caught
============================================================================
*/
