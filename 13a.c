/*
============================================================================
Name : 13a.c
Author : Akash Chaudhari
Description : Write two programs: first program is waiting to catch SIGSTOP signal, the second program will send the signal (using kill system call). Find out whether the first program is able to catch the signal or not.AL
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void my_handler(int sig)
{
    printf("Was able to catch SIGSTOP.\n");
    exit(0);
}

int main()
{
    struct sigaction act;
    act.sa_handler = my_handler;
    printf("pid : %d\n", getpid());

    sigaction(SIGSTOP, &act, NULL);

    printf("Waiting for SIGSTOP Signal.\n");
    while (1)
    {
    }
}

/*
============================================================================
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ cc 13a.c -o 13a
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ./13a
pid : 22972
Waiting for SIGSTOP Signal.

[1]+  Stopped                 ./13a
============================================================================
*/