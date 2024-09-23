/*
============================================================================
Name : 25.c
Author : Akash Chaudhari
Description : Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
                a. access permission
                b. uid, gid
                c. time of last message sent and received
                d. time of last change in the message queue
                d. size of the queue
                f. number of messages in the queue
                g. maximum number of bytes allowed
                h. pid of the msgsnd and msgrcv
Date: 20th Sep, 2024.
============================================================================
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    key_t key = ftok(".", 'O');
    int message_queue_ID = msgget(key, 0);

    struct msqid_ds message_queue;

    msgctl(message_queue_ID, IPC_STAT, &message_queue);

    printf("Access Permissions: %03o\n", message_queue.msg_perm.mode);
    printf("Effective UID of Owner: %d\n", message_queue.msg_perm.uid);
    printf("Effective GID of Owner: %d\n", message_queue.msg_perm.gid);
    printf("Effective UID of Creator: %d\n", message_queue.msg_perm.cuid);
    printf("Effective GID of Creator: %d\n", message_queue.msg_perm.cgid);
    printf("Time of last msgsnd: %s", ctime(&message_queue.msg_stime));
    printf("Time of last msgrce: %s", ctime(&message_queue.msg_rtime));
    printf("Time of last change: %s", ctime(&message_queue.msg_ctime));
    printf("Current number of message in queue: %lu\n", message_queue.msg_qnum);
    printf("Maximum number of bytes allowed in queue:  %lu\n", message_queue.msg_qbytes);
    printf("PID of last msgsnd: %d\n", message_queue.msg_lspid);
    printf("PID of last msgrce: %d\n", message_queue.msg_lrpid);

    return 0;
}

/*
============================================================================
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ cc 25.c -o 25
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ./25
Access Permissions: 666
Effective UID of Owner: 1000
Effective GID of Owner: 1000
Effective UID of Creator: 1000
Effective GID of Creator: 1000
Time of last msgsnd: Mon Sep 23 09:01:12 2024
Time of last msgrce: Thu Jan  1 05:30:00 1970
Time of last change: Mon Sep 23 09:01:12 2024
Current number of message in queue: 2
Maximum number of bytes allowed in queue:  16384
PID of last msgsnd: 12290
PID of last msgrce: 0
============================================================================
*/
