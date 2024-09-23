/*
============================================================================
Name : 8b.c
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

void handler()
{
    printf("SIGINT Caught\n");
}

void main()
{
    __sighandler_t status;

    status = signal(SIGINT, handler);

    if (status == SIG_ERR)
    {
        perror("Error Occured ");
    }
    else
    {
        raise(SIGINT);
    }
}

/*
============================================================================
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ cc 8b.c -o 8b
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ./8b
SIGINT Caught
============================================================================
*/
