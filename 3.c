/*
============================================================================
Name : 3.c
Author : Akash Chaudhari
Description : Write a program to set (any one) system resource limit. Use setrlimit system call.
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/resource.h>

int main()
{
    struct rlimit limit;

    getrlimit(RLIMIT_MSGQUEUE, &limit);
    printf("Soft Limit : %ld\n", limit.rlim_cur);
    printf("Hard Limit : %ld\n", limit.rlim_max);

    limit.rlim_cur = 819000;

    setrlimit(RLIMIT_MSGQUEUE, &limit);
    getrlimit(RLIMIT_MSGQUEUE, &limit);
    printf("Soft Limit : %ld\n", limit.rlim_cur);

    return 0;
}

/*
============================================================================
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ cc 3.c -o 3
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ./3
Soft Limit : 819200
Hard Limit : 819200
Soft Limit : 819000
============================================================================
*/