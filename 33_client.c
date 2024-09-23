/*
============================================================================
Name : 33_client.c
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
    char buf[1024];
    struct sockaddr_in serv;

    int sd = socket(AF_INET, SOCK_STREAM, 0);

    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons(6006);

    connect(sd, (void *)&serv, sizeof(serv));
    write(sd, "Hello server\n", 14);
    read(sd, &buf, sizeof(buf));
    printf("Received from server : %s\n", buf);

    close(sd);

    return 0;
}

/*
============================================================================
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ cc 33_client.c -o client
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ./client
Received from server : Fine will acknowledge you
============================================================================
*/