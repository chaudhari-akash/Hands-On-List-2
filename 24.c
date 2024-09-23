/*
============================================================================
Name : 24.c
Author : Akash Chaudhari
Description : Write a program to create a message queue and print the key and message queue id.
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main()
{
    key_t key;
    int message_queue;

    key = ftok(".", 'O');

    message_queue = msgget(key, IPC_CREAT | 0777);
    printf("Message Queue Key: %d\n", key);
    printf("Message Queue ID: %d\n", message_queue);

    return 0;
}

/*
============================================================================
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ cc 24.c -o 24
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ./24
Message Queue Key: 1325888439
Message Queue ID: 1
============================================================================
*/
