CC=gcc
CFLAGS= -W -Wall -Werror -std=c99
SOURCES=$(wildcard *.c)
all: server client

server: $(SOURCES)
		$(CC) $(CFLAGS) server.c error_processing.c -o server

client: $(SOURCES)
		$(CC) $(CFLAGS) client.c error_processing.c -o client
