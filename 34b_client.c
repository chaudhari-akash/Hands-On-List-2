/*
============================================================================
Name : 34b_client.c
Author : Akash Chaudhari
Description : Write a program to create a concurrent server.
                a. use fork
                b. use pthread_create
Date: 22th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <fcntl.h>
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
    write(sd, "Hello server\n", 13);
    read(sd, &buf, sizeof(buf));
    printf("Received from server : %s\n", buf);

    while (1)
    {
    }
    close(sd);

    return 0;
}

/*
============================================================================
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ cc 34b_client.c -o 34bc
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ./34bc
Received from server : Fine, will acknowledge you
============================================================================
*/
