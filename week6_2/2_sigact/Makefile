CC=g++
CFLAGS=-I
CFLAGS+=-Wall
FILES=sigact.cpp
FILES2=processChild.cpp

all: sigact processChild

sigact: $(FILES)
	$(CC) $(CFLAGS) -o sigact $(FILES)

processChild: $(FILES2)
	$(CC) $(CFLAGS) -o processChild $(FILES2)

clean:
	rm -f *.o sigact processChild

