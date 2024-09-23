/*
============================================================================
Name : 20b.c
Author : Akash Chaudhari
Description :  Write two programs so that both can communicate by FIFO -Use one way communication.
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
    int fd = open("myfifo", O_WRONLY);
    int read_s = write(fd, "Hello \n", 7);
}

/*
============================================================================
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ cc 20b.c -o 20b
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ./20b
============================================================================
*/