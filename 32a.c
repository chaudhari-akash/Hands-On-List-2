/*
============================================================================
Name : 32a.c
Author : Akash Chaudhari
Description : Write a program to implement semaphore to protect any critical section.
                a. rewrite the ticket number creation program using semaphore
                b. protect shared memory from concurrent write access
                c. protect multiple pseudo resources ( may be two) using counting semaphore
                d. remove the created semaphore
Date: 20th Sep, 2024.
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
    char *tf = "db.txt";
    int fd = open(tf, O_CREAT | O_RDWR, 0700);
    if (fd == -1)
        _exit(1);
    union semun
    {
        int val;
        struct semid_ds *buf;
        unsigned short *array;
        struct seminfo *__buf;
    } s;

    int k = ftok(".", 331);
    int id = semget(k, 1, 0);
    if (id == -1)
    {
        id = semget(k, 1, IPC_CREAT | 0700);
        s.val = 1;
        semctl(id, 0, SETVAL, s);
    }
    struct sembuf op;
    op.sem_num = 0;
    op.sem_flg = 0;
    int i = 0;
    printf("Press 1 to obtain lock on the critical section\n");
    scanf("%d", &i);
    if (i == 1)
    {
        op.sem_op = -1;
        semop(id, &op, 1);
    }
    printf("Obtained lock on critical section!\n");
    printf("Now entering critical section!\n");
    int data;
    int r = read(fd, &data, sizeof(data));
    if (r == -1)
        _exit(1);
    else if (r == 0)
        data = 1;
    else
    {
        data += 1;
        lseek(fd, 0, SEEK_SET);
    }
    int w = write(fd, &data, sizeof(data));
    if (w == -1)
        _exit(1);
    printf("Your ticket number is:%d\n", data);
    printf("Press 2 to exit from critical section!\n");
    scanf("%d", &i);
    {
        op.sem_op = 1;
        semop(id, &op, 1);
    }
    close(fd);

    return 0;
}

/*
============================================================================
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ cc 32a.c -o 32a
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ./32a
Press 1 to obtain lock on the critical section
1
Obtained lock on critical section!
Now entering critical section!
Your ticket number is:1
Press 2 to exit from critical section!
2
============================================================================
*/