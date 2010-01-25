#################################
#   Makefile
#################################

CC=gcc
CFLAGS=-g -W -Wall -ansi -pedantic
LDFLAGS=
EXEC=passcurse
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)
	
	mkdir -p {obj,bin}
	mv *.o obj/
	mv $(EXEC) bin/

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf bin/*.o
