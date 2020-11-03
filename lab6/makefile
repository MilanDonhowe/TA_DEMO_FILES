CC=g++
CFLAGS=-Wall -O3 -g
PROG=pokemon_demo

all: $(PROG)

$(PROG): driver.cpp Pokemon.o Pikachu.o
	$(CC) $^ $(CFLAGS) -o $(PROG)

Pikachu.o: Pikachu.cpp Pikachu.h
	$(CC) -c $<

Pokemon.o: Pokemon.cpp Pokemon.h
	$(CC) -c $<

clean:
	rm -f $(PROG) *.o
