/*
============================================================================
Name : 34b_server.c
Author : Akash Chaudhari
Description : Write a program to create a concurrent server.
                a. use fork
                b. use pthread_create
Date: 22th Sep, 2024.
============================================================================
*/

#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void *handle_client(void *arg)
{
    int sd1 = *(int *)arg;
    char buf[1000];

    printf("Connected to client\n");
    int s = read(sd1, buf, sizeof(buf) - 1);
    buf[s] = '\0';
    printf("Received your message client: %s\n", buf);
    write(sd1, "Fine, will acknowledge you\n", 27);
    close(sd1);
    return NULL;
}

int main()
{
    struct sockaddr_in sv, cl;
    int sd, sd1;
    sd = socket(AF_INET, SOCK_STREAM, 0);
    sv.sin_family = AF_INET;
    sv.sin_addr.s_addr = INADDR_ANY;
    sv.sin_port = htons(6006);
    bind(sd, (struct sockaddr *)&sv, sizeof(sv));
    listen(sd, 5);
    while (1)
    {
        int size = sizeof(cl);
        sd1 = accept(sd, (struct sockaddr *)&cl, &size);
        pthread_t id;
        pthread_create(&id, NULL, handle_client, (void *)&sd1);
        pthread_detach(id);
    }
    close(sd);
    return 0;
}

/*
============================================================================
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ cc 34b_server.c -o 34bs
akash@akash-Inspiron-16-5630:~/Hands On List/Hands On List 2$ ./34bs
Connected to client
Received your message client: Hello server


Connected to client
Received your message client: Hello server
============================================================================
*/
