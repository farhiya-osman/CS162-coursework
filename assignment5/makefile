CC=g++
exe_file = assign5

exe_file: test_linked_list.cpp linked_list.o  
	$(CC) test_linked_list.cpp linked_list.o  -o $(exe_file)
linked_list.o: linked_list.cpp linked_list.h node.h
	$(CC) -c linked_list.cpp
clean: rm -f *.o $(exe_file)
