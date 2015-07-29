#all:
#	g++ -std=c++11 main.cpp -o main
#clean:
#	rm -rf generated.* *~ *.swp *.out

CC=g++
CFLAGS=-Wall -c -std=c++11 -O0 -g
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
	rm -rf *~ *.swp *.o generated.* main
add:
	git add -A
push:
	git push
gdb:
	gdb ./main
compile:
	pdflatex generated.tex
