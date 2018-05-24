CC = gcc

CFLAGS = -std=c99 -Wall -Wextra -Werror -Wfatal-errors -pedantic

INLCUDES = $(shell echo *.h)

all: unittests movielist

## Compile step

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

## Make Unit Tests 

movielist: hashtable.o linkedlist.o movielist.o listmaker.o
	$(CC) $^ -o $@

unittests: hashtable.o linkedlist.o unitmain.o hashunit.o listunit.o \
		movielist.o movieunit.o
	$(CC) $^ -o $@ 

clean: 
	-rm *.o *.exe unittests movielist
