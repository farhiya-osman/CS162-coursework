CC=g++
EXE_FILE=prog

$(EXE_FILE): prog.cpp animals.o monkeys.o seaotter.o sloth.o tiger.o zoo.o
	$(CC) prog.cpp animals.o monkeys.o seaotter.o sloth.o tiger.o zoo.o 
animals.o: animals.cpp animals.h
	$(CC) -c animals.cpp
monkeys.o: monkeys.cpp monkeys.h animals.h
	$(CC) -c monkeys.cpp
seaotter.o: seaotter.cpp seaotter.h animals.h
	$(CC) -c seaotter.cpp
sloth.o: sloth.cpp sloth.h animals.h 
	$(CC) -c sloth.cpp 
tiger.o: tiger.cpp tiger.o animals.h
	$(CC) -c tiger.cpp
zoo.o: zoo.cpp zoo.h animals.h monkeys.h seaotter.h sloth.o tiger.o

