CC=gcc
CFLAGS=-Wall -O
LDFLAGS=
EXEC=getopts
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

all: $(EXEC)

tokenizer: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

main.o: getopts.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f *.o $(EXEC)

mrproper: clean
	rm -f $(EXEC)

test: all
	./$(EXEC) --add toto
	./$(EXEC) --delete toto
	./$(EXEC) -a --append
