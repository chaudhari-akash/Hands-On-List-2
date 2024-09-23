/*
============================================================================
Name : 30a.c
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

    int sharedMmyId = shmget(key, 1024, IPC_CREAT | 0700);

    char *dt = (char *)shmat(sharedMmyId, NULL, 0);

    // ================================================
    strcpy(dt, "Welcome to IIITB!");

    // ================================================
    printf("Detaching pointer to shared memory\n");
    shmdt(dt);

    // ================================================
    printf("Deleting the shared memory\n");
    shmctl(sharedMmyId, IPC_RMID, NULL);

    return 0;
}

/*
============================================================================
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ cc 30a.c -o 30a
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ./30a
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ipcs -m

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status
0x010753eb 18         akash      700        1024       0

akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ cc 30a.c -o 30a
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ./30a
Detaching pointer to shared memory
Deleting the shared memory
============================================================================
*/
