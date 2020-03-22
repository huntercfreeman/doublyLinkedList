CC=gcc
CFLAGS=-Wall -g

all: mainapp

mainapp: main.o doublyLinkedList.o
	$(CC) $(CFLAGS) main.o doublyLinkedList.o -o mainapp

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

doublyLinkedList.o: doublyLinkedList.c
	$(CC) $(CFLAGS) -c doublyLinkedList.c

clean:
	rm a.out *.o mainapp
