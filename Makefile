CC = gcc
CFLAGS = -Wall -g

all = main

main: main.c
		$(CC) $(CFLAGS) main.c -o main

clean:
		rm -f main
		rm -f main.exe