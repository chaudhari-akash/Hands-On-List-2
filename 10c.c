/*
============================================================================
Name : 10c.c
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
    printf("SIGFPE Caught \n");
}
void main()
{
    struct sigaction act;

    act.sa_handler = handler;

    int status = sigaction(SIGFPE, &act, NULL);

    if (status == -1)
    {
        perror("Some Error Occured ");
    }
    else
    {
        raise(SIGFPE);
    }
}

/*
============================================================================
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ cc 10c.c -o 10c
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ./10c
SIGFPE Caught
============================================================================
*/