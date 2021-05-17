#include "err_processing.h"
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

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

void Connect(int socket, const struct sockaddr *addr, socklen_t address_len) {
    int connect_res = connect(socket, addr, address_len);
    if (connect_res == -1) {
        perror("Connect error");
        exit(EXIT_FAILURE);
    }
}

void Inet_pton(int af, const char *restrict src, void *restrict dst) {
    int inet_pton_res = inet_pton(af, src, dst);
    if (inet_pton_res == 0) {
        printf("inet_pton failed.");
        exit(EXIT_FAILURE);
    }
    if (inet_pton_res == -1) {
        perror("Inet pton error");
        exit(EXIT_FAILURE);
    }
}