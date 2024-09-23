/*
============================================================================
Name : 26.c
Author : Akash Chaudhari
Description : Write a program to send messages to the message queue. Check $ipcs -q
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

    int msg_id = msgget(key, IPC_CREAT | 0666);

    struct msgBuffer
    {
        long mtype;
        char mtext[80];
    };

    struct msgBuffer message1 = {1, "First message."};
    struct msgBuffer message2 = {2, "Second message."};

    msgsnd(msg_id, (void *)&message1, sizeof(message1.mtext), IPC_NOWAIT);

    msgsnd(msg_id, (void *)&message2, sizeof(message2.mtext), IPC_NOWAIT);

    return 0;
}

/*
============================================================================
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ cc 26.c -o 26
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ./26
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages
0x4f0753eb 0          akash      666        160          2
============================================================================
*/
