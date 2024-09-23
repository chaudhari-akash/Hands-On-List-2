/*
============================================================================
Name : 30b.c
Author : Akash Chaudhari
Description : Write a program to create a shared memory.
                a. write some data to the shared memory
                b. attach with O_RDONLY and check whether you are able to overwrite.
                c. detach the shared memory
                d. remove the shared memory
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main()
{
    key_t key = ftok(".", 1);
    int sharedMmyId = shmget(key, 256, IPC_CREAT | 0744);
    char *data;

    data = shmat(sharedMmyId, 0, SHM_RDONLY);

    printf("Data to add in shared memory: ");

    scanf("%s", data);
}
