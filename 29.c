/*
============================================================================
Name : 29.c
Author : Akash Chaudhari
Description : Write a program to remove the message queue.
Date: 20th Sep, 2024.
============================================================================
*/

#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>

int main()
{
    key_t key = ftok(".", 'O');
    int msgqueid = msgget(key, 0);

    msgctl(msgqueid, IPC_RMID, NULL);

    return 0;
}

/*
============================================================================
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ cc 29.c -o 29
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ./29

akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages
============================================================================
*/
