CC=g++
EXE_FILE=prog

$(EXE_FILE): prog.cpp bats.o event.o gold.o pit.o room.o wumpus.o runboard.o normal.o
	$(CC) prog.cpp bats.o event.o gold.o pit.o room.o wumpus.o runboard.o normal.o -o$(EXE_FILE)
bats.o:bats.cpp 
	$(CC) -c bats.cpp
event.o:event.cpp 
	$(CC) -c event.cpp
gold.o:gold.cpp 
	$(CC) -c gold.cpp
pit.o:pit.cpp
	$(CC) -c pit.cpp
room.o:room.cpp
	$(CC) -c room.cpp
wumpus.o:wumpus.cpp 
	$(CC) -c wumpus.cpp
runboard.o:runboard.cpp
	$(CC) -c runboard.cpp
normal.o:normal.cpp
	$(CC) -c normal.cpp

