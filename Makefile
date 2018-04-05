CC = gcc

CFLAGS = -std=c99 -Wall -Wextra -Werror -Wfatal-errors -pedantic

INLCUDES = $(shell echo *.h)

all: hashunit

## Compile step

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

## Make Unit Tests

hashunit: hashtable.o hashunit.o
	$(CC) -c hashtable.c hashunit.c 

clean: 
	-rm *.o 