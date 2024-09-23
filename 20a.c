/*
============================================================================
Name : 20a.c
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
    int fd = open("myfifo", O_RDONLY);
    int read_s = read(fd, &buf, sizeof(buf));
    write(1, &buf, read_s);
    return 0;
}

/*
============================================================================
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ cc 20a.c -o 20a
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ mkfifo myfifo
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ./20a
Hello
============================================================================
*/