#all:
#	g++ -std=c++11 main.cpp -o main
#clean:
#	rm -rf generated.* *~ *.swp *.out

CC=g++
CFLAGS=-Wall -c -std=c++11
LDFLAGS=
SOURCES=main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE) : $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *~ *.swp *.o generated.*
