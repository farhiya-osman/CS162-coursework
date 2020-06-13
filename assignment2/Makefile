CC=g++
EXE_FILE=prog

$(EXE_FILE): prog.cpp menu.o pizza.o restaurant.o
	$(CC) prog.cpp menu.o pizza.o restaurant.o
menu.o: menu.cpp menu.h
	$(CC) -c menu.cpp
pizza.o: pizza.cpp pizza.h
	$(CC) -c pizza.cpp
restaurant.o: restaurant.cpp restaurant.h emp_hours.h
	$(CC) -c restaurant.cpp

