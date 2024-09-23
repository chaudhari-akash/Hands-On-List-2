/*
============================================================================
Name : 2.c
Author : Akash Chaudhari
Description : Write a program to print the system resource limits. Use getrlimit system call
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/resource.h>

void print_limit(int resource)
{
    struct rlimit lim;
    if (getrlimit(resource, &lim) == 0)
    {
        printf("Resource: %d\n", resource);
        printf("  Soft limit: %lu\n", lim.rlim_cur);
        printf("  Hard limit: %lu\n", lim.rlim_max);
    }
    else
    {
        perror("getrlimit");
    }
}

int main()
{
    printf("System Resource Limits:\n\n");

    print_limit(RLIMIT_AS);      // Maximum size of the process's virtual memory
    print_limit(RLIMIT_CORE);    // Maximum size of core file
    print_limit(RLIMIT_CPU);     // Maximum CPU time in seconds
    print_limit(RLIMIT_DATA);    // Maximum size of the process's data segment
    print_limit(RLIMIT_FSIZE);   // Maximum file size
    print_limit(RLIMIT_LOCKS);   // Maximum number of file locks
    print_limit(RLIMIT_MEMLOCK); // Maximum size of locked memory
    print_limit(RLIMIT_NICE);    // Maximum nice priority
    print_limit(RLIMIT_NOFILE);  // Maximum number of open files
    print_limit(RLIMIT_NPROC);   // Maximum number of processes
    print_limit(RLIMIT_STACK);   // Maximum size of the process's stack

    return 0;
}

/*
============================================================================
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ cc 2.c -o 2
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ./2
System Resource Limits:

Resource: 9
  Soft limit: 18446744073709551615
  Hard limit: 18446744073709551615
Resource: 4
  Soft limit: 0
  Hard limit: 18446744073709551615
Resource: 0
  Soft limit: 18446744073709551615
  Hard limit: 18446744073709551615
Resource: 2
  Soft limit: 18446744073709551615
  Hard limit: 18446744073709551615
Resource: 1
  Soft limit: 18446744073709551615
  Hard limit: 18446744073709551615
Resource: 10
  Soft limit: 18446744073709551615
  Hard limit: 18446744073709551615
Resource: 8
  Soft limit: 2054713344
  Hard limit: 2054713344
Resource: 13
  Soft limit: 0
  Hard limit: 0
Resource: 7
  Soft limit: 1048576
  Hard limit: 1048576
Resource: 6
  Soft limit: 62426
  Hard limit: 62426
Resource: 3
  Soft limit: 8388608
  Hard limit: 18446744073709551615
============================================================================
*/