#ifndef ERPROC_H
#define ERPROC_H

#include <sys/socket.h>

int Socket(int domain, int type, int protocol);

void Bind(int socketId, const struct sockaddr *addr, socklen_t addrlen);

int Listen(int socket, int backlog);

int Accept(int socket, struct sockaddr *restrict address, socklen_t *restrict address_len);

#endif