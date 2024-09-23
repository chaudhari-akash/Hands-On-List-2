/*
============================================================================
Name : 6.c
Author : Akash Chaudhari
Description : Write a simple program to create three threads.
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void fun()
{
    printf("Printing from thread\n");
}

int main()
{
    pthread_t thread1, thread2, thread3;
    int status;
    status = pthread_create(&thread1, NULL, (void *)fun, NULL);
    if (status != 0)
    {
        perror("Error while creating thread");
        exit(1);
    }

    status = pthread_create(&thread2, NULL, (void *)fun, NULL);
    if (status != 0)
    {
        perror("Error while creating thread");
        exit(1);
    }

    status = pthread_create(&thread3, NULL, (void *)fun, NULL);
    if (status != 0)
    {
        perror("Error while creating thread");
        exit(1);
    }

    pthread_exit(NULL);
}

/*
============================================================================
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ cc 6.c -o 6
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ./6
Printing from thread
Printing from thread
Printing from thread
============================================================================
*/