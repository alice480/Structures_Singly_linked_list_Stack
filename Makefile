CC = gcc
CFLAGS = -Wall -Wextra -Werror
DIR = ../build/

all: list_test stack_test

dmanager_module.o: dmanager_module.c
	$(CC) $(CFLAGS) -c dmanager_module.c

list_test.o: list_test.c
	$(CC) $(CFLAGS) -c list_test.c

list.o: list.c
	$(CC) $(CFLAGS) -c list.c

stack_test.o: stack_test.c
	$(CC) $(CFLAGS) -c stack_test.c

stack.o: stack.c
	$(CC) $(CFLAGS) -c stack.c

door_struct: dmanager_module.o
	$(CC) -o $(DIR)Quest_1 dmanager_module.o

list_test: list_test.o list.o
	$(CC) -o $(DIR)Quest_2 list_test.o list.o

stack_test: stack_test.o stack.o
	$(CC) -o $(DIR)Quest_3 stack_test.o stack.o

clean:
	rm -rf *.o
	rm -rf ../build/Quest_* 

rebuild: clean all
