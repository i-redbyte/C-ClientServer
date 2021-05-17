#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
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
};

int main() {
    int server = Socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in adr = {0};
    adr.sin_family = PF_INET;
    adr.sin_port = htons(25664);
    Bind(server, (const struct sockaddr *) &adr, sizeof adr);
    Listen(server, 5);
    socklen_t adrlen = sizeof adr;
    int file_descriptor = Accept(server, (struct sockaddr *) &adr, &adrlen);
    ssize_t nread;
    char buf[256];
    nread = read(file_descriptor, buf, 256);
    if (nread == -1) {
        perror("Read error!");
        exit(EXIT_FAILURE);
    }
    if (nread == 0) {
        printf("End of file!");
    }
    write(STDOUT_FILENO, buf, nread);
    write(file_descriptor, buf, nread);
//    close(file_descriptor);
//    close(listen())
    return 0;
}
