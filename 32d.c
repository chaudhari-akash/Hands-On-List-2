/*
============================================================================
Name : 32d.c
Author : Akash Chaudhari
Description : Write a program to implement semaphore to protect any critical section.
                a. rewrite the ticket number creation program using semaphore
                b. protect shared memory from concurrent write access
                c. protect multiple pseudo resources ( may be two) using counting semaphore
                d. remove the created semaphore
Date: 20th Sep, 2024.
============================================================================
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    key_t semKey;
    int semIndentifier;
    int semctlStatus;

    semKey = ftok(".", 6);

    semIndentifier = semget(semKey, 1, IPC_CREAT | 0777);

    printf("Deleting the semaphore : Press Enter \n");
    getchar();

    semctlStatus = semctl(semIndentifier, 0, IPC_RMID);

    return 0;
}

/*
============================================================================
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ cc 32d.c -o 32d
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ./32d
Deleting the semaphore : Press Enter
============================================================================
*/