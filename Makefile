CC = gcc

CFLAGS = -std=c99 -Wall -Wextra -Werror -Wfatal-errors -pedantic

INLCUDES = $(shell echo *.h)

all: hashunit

## Compile step

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

## Make Unit Tests

hashunit: hashtable.o unitmain.o hashunit.o
	$(CC) $^ -o $@ 

clean: 
	-rm *.o *~ hashunit