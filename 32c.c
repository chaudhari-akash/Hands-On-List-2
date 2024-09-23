/*
============================================================================
Name : 32c.c
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
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    char *tf = "temp.txt";
    int fd = open(tf, O_CREAT | O_RDONLY);
    if (fd == -1)
        _exit(1);
    int rb;
    char data[1000];
    int k;
    int id;
    int cs;
    union semun
    {
        int val;
    } s;
    k = ftok(".", 331);
    if (k == -1)
        _exit(1);
    id = semget(k, 1, 0);
    if (id == -1)
    {
        id = semget(k, 1, IPC_CREAT | 0700);
        s.val = 2;
        cs = semctl(id, 0, SETVAL, s);
    }
    struct sembuf op;
    op.sem_num = 0;
    op.sem_flg = IPC_NOWAIT;
    printf("Press enter to obtain lock for the critical section!\n");
    getchar();
    op.sem_op = -1;
    cs = semop(id, &op, 1);
    printf("\nGot lock on critical section\n");
    printf("\nEntering critical section\n");
    rb = read(fd, &data, 1000);
    if (rb == -1)
        _exit(0);
    else if (rb == 0)
        printf("\nNo data exists!\n");
    else
        printf("\nSample data: \n %s", data);
    printf("\n\nPress enter key to exit critical section!\n");
    getchar();
    op.sem_op = 1;
    cs = semop(id, &op, 1);
    close(fd);

    return 0;
}

/*
============================================================================
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ cc 32c.c -o 32c
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ./32c
Press enter to obtain lock for the critical section!


Got lock on critical section

Entering critical section

Sample data:
 Hello this is in File


Press enter key to exit critical section!
============================================================================
*/