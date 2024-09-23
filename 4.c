/*
============================================================================
Name : 4.c
Author : Akash Chaudhari
Description : Write a program to measure how much time is taken to execute 100 getppid ( ) system call. Use time stamp counter.
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

unsigned long long rdtsc()
{
    unsigned long long dst;
    __asm__ __volatile__("rdtsc" : "= A"(dst));
    return dst;
}

int main()
{
    unsigned long long start, end;

    start = rdtsc();

    for (int i = 0; i < 100; i++)
    {
        getppid();
    }

    end = rdtsc();

    unsigned long long time_taken = end - start;

    printf("Time taken to execute 100 getppid() calls: %llu clock cycles\n", time_taken);

    return 0;
}

/*
============================================================================
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ cc 4.c -o 4
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ./4
Time taken to execute 100 getppid() calls: 98816 clock cycles
============================================================================
*/
