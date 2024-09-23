/*
============================================================================
Name : 8f.c
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
#include <sys/time.h>

void handler()
{
    printf("SIGPROF Caught\n");
    exit(0);
}

void main()
{
    __sighandler_t status;

    struct itimerval timer;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;
    timer.it_value.tv_sec = 5;
    timer.it_value.tv_usec = 0;
    int timerStatus = setitimer(ITIMER_PROF, &timer, 0);

    while (1)
    {
        signal(SIGPROF, handler);
    }
}

/*
============================================================================
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ cc 8g.c -o 8g
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ./8g
SIGPROF Caught
============================================================================
*/
