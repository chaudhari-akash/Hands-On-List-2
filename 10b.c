/*
============================================================================
Name : 10b.c
Author : Akash Chaudhari
Description : Write a separate program using sigaction system call to catch the following signals.
                a. SIGSEGV
                b. SIGINT
                c. SIGFPE
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handler()
{
    printf("SIGINT Caught \n");
}
void main()
{
    struct sigaction act;

    act.sa_handler = handler;

    int status = sigaction(SIGINT, &act, NULL);

    if (status == -1)
    {
        perror("Some Error Occured ");
    }
    else
    {
        raise(SIGINT);
    }
}

/*
============================================================================
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ cc 10b.c -o 10b
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ./10b
SIGINT Caught
============================================================================
*/