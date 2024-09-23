/*
============================================================================
Name : 21b.c
Author : Akash Chaudhari
Description : Write two programs so that both can communicate by FIFO -Use two way communications.
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    char buf[1024];
    int fd = open("pipe_1", O_WRONLY);
    int fd2 = open("pipe_2", O_RDONLY);
    printf("Writing...\n");
    write(fd, "Hi there \n", 10);
    int s_r = read(fd2, &buf, sizeof(buf));
    printf("Reading...\n");
    write(1, &buf, s_r);
}

/*
============================================================================
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ cc 21b.c -o 21b
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ./21b
writing...
reading...
How are you?
============================================================================
*/