/*
============================================================================
Name : 9.c
Author : Akash Chaudhari
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal - Use signal system call.
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main(void)
{

    signal(SIGINT, SIG_IGN);
    printf("Ignoring SIGINT\n");
    sleep(5);

    signal(SIGINT, SIG_DFL);
    printf("Default action for SIGINT\n");
    sleep(5);
    printf("No SIGINT within 5 seconds\n");
    return 0;
}

/*
============================================================================
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ cc 9.c -o 9
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ./9
Ignoring SIGINT
^C
Default action for SIGINT
No SIGINT within 5 seconds
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ./9
Ignoring SIGINT
^C
Default action for SIGINT
^C
============================================================================
*/