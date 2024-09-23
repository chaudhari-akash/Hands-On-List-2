/*
============================================================================
Name : 31a.c
Author : Akash Chaudhari
Description : Write a program to create a semaphore and initialize value to the semaphore.
                a. create a binary semaphore
                b. create a counting semaphore
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main()
{
    key_t key = ftok(".", 2);

    int semaphoreId = semget(key, 1, IPC_CREAT | 0770);

    union semun
    {
        int val;
    } arg;

    arg.val = 10;

    semctl(semaphoreId, 0, SETVAL, arg);

    return 0;
}

/*
============================================================================
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ cc 31b.c -o 31b
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ./31b
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ipcs -s

------ Semaphore Arrays --------
key        semid      owner      perms      nsems
0x010753eb 0          akash      666        1
0x4f0753eb 1          akash      770        1
============================================================================
*/