CC=gcc
CFLAGS=-Wall -O
LDFLAGS=
EXEC=<exec>
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

all: $(EXEC)

tokenizer: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

main.o: <exec>.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f *.o $(EXEC)

mrproper: clean
	rm -f $(EXEC)
