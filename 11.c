/*
============================================================================
Name : 11.c
Author : Akash Chaudhari
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal use sigaction system call.
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main()
{
    struct sigaction act;

    printf("Ignoring the SIGINT signal for 5 seconds.\n");

    act.sa_handler = SIG_IGN; // Ignoring SIGINT
    sigaction(SIGINT, &act, NULL);
    sleep(5);

    printf("Default action for SIGINT\n");

    act.sa_handler = SIG_DFL; // setting default SIGINT
    sigaction(SIGINT, &act, NULL);
    sleep(5);
    printf("No SIGINT within 5 seconds\n");

    return 0;
}

/*
============================================================================
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ cc 11.c -o 11
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ./11
Ignoring the SIGINT signal for 5 seconds.
^C
Default action for SIGINT
^C
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ./11
Ignoring the SIGINT signal for 5 seconds.
^C
Default action for SIGINT
No SIGINT within 5 seconds
============================================================================
*/