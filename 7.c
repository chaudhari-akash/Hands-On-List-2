/*
============================================================================
Name : 7.c
Author : Akash Chaudhari
Description : Write a simple program to print the created thread ids.
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void fun()
{
    printf("Printing from thread : %lu\n", pthread_self());
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
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ cc 7.c -o 7
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ./7
Printing from thread : 129969271342784
Printing from thread : 129969250371264
Printing from thread : 129969260857024
============================================================================
*/