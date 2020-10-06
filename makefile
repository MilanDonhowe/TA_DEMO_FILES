CC=g++
CFLAGS=-g -Wall
FILENAME=greet

all: $(FILENAME)	

$(FILENAME): greet.cpp greet.h
	$(CC) greet.cpp -o $(FILENAME) $(CFLAGS)

clean:
	rm -f *.o $(FILENAME) names_sorted