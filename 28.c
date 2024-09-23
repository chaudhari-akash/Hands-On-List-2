/*
============================================================================
Name : 28.c
Author : Akash Chaudhari
Description : Write a program to change the exiting message queue permission. (use msqid_ds structure)
Date: 20th Sep, 2024.
============================================================================
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>

int main()
{
    key_t key = ftok(".", 'O');

    int msgQueId = msgget(key, 0);

    struct msqid_ds msgQueDataStruct;

    msgctl(msgQueId, IPC_STAT, &msgQueDataStruct);

    printf("Current permissions: %o\n", msgQueDataStruct.msg_perm.mode & 0777);

    msgQueDataStruct.msg_perm.mode = 0660;

    msgctl(msgQueId, IPC_SET, &msgQueDataStruct);

    printf("Updated permissions: %o\n", msgQueDataStruct.msg_perm.mode & 0777);

    return 0;
}

/*
============================================================================
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ cc 28.c -o 28
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ./28
Current permissions: 666
Updated permissions: 660

akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages
0x4f0753eb 2          akash      666        160          2

akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages
0x4f0753eb 2          akash      660        160          2

============================================================================
*/
