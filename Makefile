# compiler
CC=gcc
# compiler flags
CFLAGS=-Wall -ansi -pedantic-errors
# link/load flags ex: "-lm" for math.h
LDFLAGS=

main:
	$(CC) $(CFLAGS) $(LDFLAGS) -o main main.c

clean:
	rm -rf main

all:
	rm -rf main
	$(CC) $(CFLAGS) $(LDFLAGS) -o main main.c
	sleep 0.25
	clear
	./main