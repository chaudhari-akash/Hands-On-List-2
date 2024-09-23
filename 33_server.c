/*
============================================================================
Name : 33_server.c
Author : Akash Chaudhari
Description : Write a program to communicate between two machines using socket.
Date: 22th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
    struct sockaddr_in sv, cl;
    int sd, size, sd1;
    char buf[1000];

    sd = socket(AF_INET, SOCK_STREAM, 0);

    sv.sin_family = AF_INET;
    sv.sin_addr.s_addr = INADDR_ANY;
    sv.sin_port = htons(6006);

    bind(sd, (void *)(&sv), sizeof(sv));
    listen(sd, 5);

    size = sizeof(cl);
    sd1 = accept(sd, (void *)(&cl), &size);

    printf("connected to one client\n");

    int s = read(sd1, buf, sizeof(buf));
    printf("Received your message client: %s\n", buf);
    write(sd1, "Fine will acknowledge you\n", 27);

    close(sd1);

    return 0;
}

/*
============================================================================
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ cc 33_server.c -o server
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ./server
connected to one client
Received your message client: Hello server
============================================================================
*/
