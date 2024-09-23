/*
============================================================================
Name : 27b.c
Author : Akash Chaudhari
Description : Write a program to receive messages from the message queue.
                a. with 0 as a flag
                b. with IPC_NOWAIT as a flag
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct mbuffer
{
    long mtype;
    char mtext[100];
};

int main()
{
    struct mbuffer message;
    key_t key;
    int msgid;
    key = ftok(".", 'O');
    msgid = msgget(key, 0);
    msgrcv(msgid, &message, sizeof(message), 1, IPC_NOWAIT);
    printf("Data Received : %s\n", message.mtext);
}

/*
============================================================================
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ cc 27b.c -o 27b
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ./27b
Data Received : First message.
============================================================================
*/
