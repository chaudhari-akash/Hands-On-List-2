/*
============================================================================
Name : 15.c
Author : Akash Chaudhari
Description : Write a simple program to send some data from parent to the child process.
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{

    int fd[2];
    pipe(fd);
    if (!fork())
    {
        int k;
        close(fd[1]);
        read(fd[0], &k, sizeof(int));
        printf("Data Recieved Successfully : %d\n", k);
        close(fd[0]);
    }
    else
    {
        int i;
        close(fd[0]);
        printf("Enter Data to Send to Child : ");
        scanf("%d", &i);
        write(fd[1], &i, sizeof(int));
        close(fd[1]);
    }
}
/*
============================================================================
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ cc 15.c -o 15
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ./15
enter data to send to child : 6
data recieved successfully : 6
============================================================================
*/