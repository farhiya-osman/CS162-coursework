CC=g++
EXE_FILE=application

$(EXE_FILE): application.cpp shape.o rectangle.o circle.o square.o 
	$(CC) application.cpp shape.o rectangle.o circle.o square.o -o $(EXE_FILE)
shape.o: shape.cpp
	$(CC) -c shape.cpp
rectangle.o: rectangle.cpp
	$(CC) -c rectangle.cpp
circle.o:circle.cpp  
	$(CC) -c circle.cpp
square.o:square.cpp 
	$(CC) -c square.cpp 
