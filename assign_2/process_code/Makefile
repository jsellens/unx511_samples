CC=g++
CFLAGS=-I
CFLAGS+=-Wall
FILES=Logger.cpp
FILES+=Automobile.cpp
FILES+=TravelSimulator.cpp
LIBS=-lpthread

all: travel

travel: $(FILES)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

clean:
	rm -f *.o travel
