/*
============================================================================
Name : 32b.c
Author : Akash Chaudhari
Description : Write a program to implement semaphore to protect any critical section.
                a. rewrite the ticket number creation program using semaphore
                b. protect shared memory from concurrent write access
                c. protect multiple pseudo resources ( may be two) using counting semaphore
                d. remove the created semaphore
Date: 22th Sep, 2024.
============================================================================
*/

#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int shmSize = 20;
    union semun
    {
        int val;
        struct semid_ds *buf;
        unsigned short *array;
        struct seminfo *__buf;
    } u;
    int semKey = ftok(".", 363);
    int id = semget(semKey, 1, 0);
    if (id == -1)
    {
        id = semget(semKey, 1, IPC_CREAT | 0700);
        u.val = 1;
        semctl(id, 0, SETVAL, u);
    }
    int shmKey = ftok(".", 3322);
    int shmId = shmget(shmKey, shmSize, IPC_CREAT | 0770);
    char *shrd = shmat(shmId, (void *)0, 0);
    struct sembuf op;
    op.sem_num = 0;
    op.sem_flg = 0;

    printf("Press enter to lock the critical section!\n");
    getchar();

    op.sem_op = -1;
    int opStatus = semop(id, &op, 1);

    printf("Critical Section is now locked!\n");
    printf("Start of the critical section!\n");
    sprintf(shrd, "Hello There");
    printf("Press enter to read from the shared memory!\n");
    getchar();

    printf("%s\n", shrd);
    printf("Press enter to exit the critical section!\n");
    getchar();

    op.sem_op = 1;
    opStatus = semop(id, &op, 1);

    printf("Critical section is now unlocked!\n");

    return 0;
}

/*
============================================================================
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ cc 32b.c -o 32b
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ./32b
Press enter to lock the critical section!

Critical Section is now locked!
Start of the critical section!
Press enter to read from the shared memory!

Hello There
Press enter to exit the critical section!

Critical section is now unlocked!
============================================================================
*/