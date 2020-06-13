lab2:
	g++ lab2.cpp prog.cpp -o lab2
CC=g++
EXE_FILE=lab2

all: $(EXE_FILE)

$(EXE_FILE): lab2.o lab2.h prog.cpp
	$(CC) lab2.o prog.cpp -o $(EXE_FILE)

lab2.o: lab2.h lab2.cpp
	$(CC) -c lab2.cpp
