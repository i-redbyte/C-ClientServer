#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <unistd.h>
#include "err_processing.h"

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
    sleep(1);
    close(file_descriptor);
    close(server);
    return 0;
}
