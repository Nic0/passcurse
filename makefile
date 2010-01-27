#################################
#   Makefile
#################################

CC=gcc
CFLAGS=-g -W -Wall -ansi -pedantic -lncurses
LDFLAGS=-lncurses
EXEC=passcurse
SRC= $(wildcard src/*.c)
OBJ= $(SRC:.c=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)
	
%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf src/*.o
