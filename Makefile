CC=gcc
CFLAGS= -W -Wall -Werror -std=c99
SOURCES=$(wildcard *.c)
.PHONY: server client
all: server client

server:
		$(CC) $(CFLAGS) server.c error_processing.c -o server

client:
		$(CC) $(CFLAGS) client.c error_processing.c -o client
