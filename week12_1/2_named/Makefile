CC=g++
CFLAGS=-I
CFLAGS+=-Wall
FILES1=client1.cpp
FILES2=client2.cpp
LIBS=-lpthread

all: client1 client2

client1: $(FILES1)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

client2: $(FILES2)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

clean:
	rm -f *.o client1 client2 FileSem.txt
