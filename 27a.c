/*
============================================================================
Name : 27a.c
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
} message;

int main()
{
    key_t key;
    int msgid;
    key = ftok(".", 'O');
    msgid = msgget(key, 0);
    msgrcv(msgid, &message, sizeof(message), 1, 0);
    printf("Data Received : %s\n", message.mtext);
}

/*
============================================================================
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ cc 27a.c -o 27a
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ./27a
Data Received : First message.
============================================================================
*/
