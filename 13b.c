/*
============================================================================
Name : 13b.c
Author : Akash Chaudhari
Description : Write two programs: first program is waiting to catch SIGSTOP signal, the second program will send the signal (using kill system call). Find out whether the first program is able to catch the signal or not.AL
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char *argv[])
{
    int process_no = atoi(argv[1]);
    kill(process_no, SIGSTOP);
    return 0;
}

/*
============================================================================
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ cc 13b.c -o 13b
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ./13b 22972
============================================================================
*/