/*
============================================================================
Name : 22.c
Author : Akash Chaudhari
Description : Write a program to wait for data to be written into FIFO within 10 seconds, use select system call with FIFO
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/select.h>
#include <stdlib.h>

int main()
{
    int fd;
    char buff[1000];
    fd_set fd2;
    struct timeval time;
    fd = open("pipe_3", O_RDONLY | O_NONBLOCK);

    FD_ZERO(&fd2);
    FD_SET(fd, &fd2);
    time.tv_sec = 10;
    time.tv_usec = 0;
    int res = select(fd + 1, &fd2, NULL, NULL, &time);
    if (res < 0)
    {
        perror("Error in select");
        close(fd);
        exit(1);
    }
    else if (res == 0)
    {
        printf("You didn't send any data for 10 seconds.\n");
    }
    else
    {
        if (FD_ISSET(fd, &fd2))
        {
            int sz = read(fd, buff, sizeof(buff) - 1);
            if (sz > 0)
            {
                buff[sz] = '\0';
                printf("Data received within 10s: %s\n", buff);
            }
        }
    }
    close(fd);
    return 0;
}

/*
============================================================================
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ cc 22.c -o 22
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ./22
Data received within 10s: Hi There
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ./22
You didn't send any data for 10 seconds.
============================================================================
*/