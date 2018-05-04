CC = gcc

CFLAGS = -std=c99 -Wall -Wextra -Werror -Wfatal-errors -pedantic

INLCUDES = $(shell echo *.h)

all: unittests

## Compile step

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

## Make Unit Tests 

unittests: hashtable.o linkedlist.o unitmain.o hashunit.o listunit.o
	$(CC) $^ -o $@ 

clean: 
	-rm *.o hashunit
