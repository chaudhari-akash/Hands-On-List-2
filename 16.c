/*
============================================================================
Name : 16.c
Author : Akash Chaudhari
Description : Write a program to send and receive data from parent to child vice versa. Use two way communication.
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd1[2];
    int fd2[2];
    pipe(fd1);
    pipe(fd2);

    if (!fork())
    {
        int triple, val;
        close(fd1[1]);
        close(fd2[0]);
        read(fd1[0], &val, sizeof(val));
        printf("Received Val = %d From Parent, Now Tripling it...\n", val);
        triple = 3 * val;
        write(fd2[1], &triple, sizeof(triple));
        printf("Sending To Parent ...\n");
    }
    else
    {
        int val, triple;
        close(fd1[0]);
        close(fd2[1]);
        printf("Enter val to send to child : ");
        scanf("%d", &val);
        write(fd1[1], &val, sizeof(val));
        read(fd2[0], &triple, sizeof(triple));
        printf("Child Gives Ans : %d \n", triple);
    }
}

/*
============================================================================
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ cc 16.c -o 16
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ./16
Enter val to send to child : 45
Received Val = 45 From Parent, Now Tripling it...
Sending To Parent ...
Child Gives Ans : 135
============================================================================
*/