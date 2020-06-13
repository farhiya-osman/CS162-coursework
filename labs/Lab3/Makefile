CC=g++
EXE_FILE=Pizza

$(EXE_FILE): Pizza.o  prog.o
	$(CC) Pizza.o prog.o -o $(EXE_FILE)

Pizza.o: Pizza.cpp
	$(CC) -c Pizza.cpp
prog.o: prog.cpp 
	$(CC) -c prog.cpp 
