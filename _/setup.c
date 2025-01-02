#ifdef __linux__
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
typedef unsigned int SOCKET;

SOCKET setup(){
    SOCKET server_socket,client_socket;
    struct sockaddr_in server_address,client_address;
    socklen_t client_address_length;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Failed to create socket\n");
        exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    // port: 7077
    server_address.sin_port = htons(7077);
    server_address.sin_addr.s_addr = INADDR_ANY;
  
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Failed to bind socket\n");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 2) < 0) {
        printf("Failed to listen\n");
        exit(EXIT_FAILURE);
    }

    while (1) {
        client_address_length = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_length);
        if (client_socket < 0) {
            printf("Failed to accept\n");
            exit(EXIT_FAILURE);
        }
    }

    return client_socket;
}

#endif

#ifdef _WIN32
#include<winSock2.h>
#

#endif

