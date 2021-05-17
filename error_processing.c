#include "err_processing.h"
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>

int Socket(int domain, int type, int protocol) {
    int socket_res = socket(domain, type, protocol);
    if (socket_res == -1) {
        perror("Socket error!");
        exit(EXIT_FAILURE);
    }
    return socket_res;
}

void Bind(int socketId, const struct sockaddr *addr, socklen_t addrlen) {
    int bind_res = bind(socketId, addr, addrlen);
    if (bind_res == -1) {
        perror("Bind error!");
        exit(EXIT_FAILURE);
    }
}

int Listen(int socket, int backlog) {
    int listen_res = listen(socket, backlog);
    if (listen_res == -1) {
        perror("Listen error");
        exit(EXIT_FAILURE);
    }
    return listen_res;
}

int Accept(int socket, struct sockaddr *restrict address, socklen_t *restrict address_len) {
    int accept_res = accept(socket, address, address_len);
    if (accept_res == -1) {
        perror("Accept error");
        exit(EXIT_FAILURE);
    }
    return accept_res;
}