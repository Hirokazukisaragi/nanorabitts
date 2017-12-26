CC=gcc
TARGET=rabbit.c
CFLAGS=-std=c99 -o rabbit -Wall
rabbit: rabbit.c
	$(CC) $(TARGET) $(CFLAGS)
