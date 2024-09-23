/*
============================================================================
Name : 21a.c
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
    int fd = open("pipe_1", O_RDONLY);
    int fd2 = open("pipe_2", O_WRONLY);
    int read_s = read(fd, &buf, sizeof(buf));
    printf("Reading... \n ");
    write(1, &buf, read_s);
    printf("Writing...\n");
    write(fd2, "How are you?\n", 13);
}

/*
============================================================================
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ cc 21a.c -o 21a
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ./21a
Reading...
Hi there
 writing...
============================================================================
*/