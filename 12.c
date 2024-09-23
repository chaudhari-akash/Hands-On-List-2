/*
============================================================================
Name : 12.c
Author : Akash Chaudhari
Description : Write a program to create an orphan process. Use kill system call to send SIGKILL signal to the parent process from the child process.
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main()
{
    int pid = fork();

    if (pid < 0)
    {
        perror("fork");
    }

    if (pid == 0)
    {
        printf("Child Process (PID: %d) sending SIGKILL to Parent Process (PID: %d)\n", getpid(), getppid());

        kill(getppid(), SIGKILL);

        printf("Child Process (PID: %d) is now an orphan.\n", getpid());

        sleep(1);

        printf("Parent PID : %d\n", getppid());
    }
    else
    {
        printf("Parent Process (PID: %d) is running.\n", getpid());
        while (1)
        {
        }
    }

    return 0;
}

/*
============================================================================
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ cc 12.c -o 12
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ./12
Parent Process (PID: 21722) is running.
Child Process (PID: 21723) sending SIGKILL to Parent Process (PID: 21722)
Child Process (PID: 21723) is now an orphan.
Killed
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ Parent PID : 19171
============================================================================
*/
