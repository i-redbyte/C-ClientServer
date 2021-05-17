#include "err_processing.h"
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int fd = Socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in adr = {0};
    adr.sin_family = AF_INET;
    adr.sin_port = htons(25664);
    Inet_pton(AF_INET, "127.0.0.1", &adr.sin_addr);
    Connect(fd, (struct sockaddr *) &adr, sizeof adr);
    write(fd, "Hello C!\n", 9);
    ssize_t nread;
    char buf[256];
    nread = read(fd, buf, 256);
    if (nread == -1) {
        perror("Read error!");
        exit(EXIT_FAILURE);
    }
    if (nread == 0) {
        printf("End of file!");
    }
    write(STDOUT_FILENO, buf, nread);
    close(fd);
    return 0;
}