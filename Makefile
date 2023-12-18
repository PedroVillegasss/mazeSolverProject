CC=g++
exec=solver

$(exec): main.o maze.o node.o linkedList.o stack.o queue.o  
	$(CC) main.o maze.o node.o linkedList.o stack.o queue.o -o $(exec)

run: $(exec)
	./$(exec)
	
all: clean $(exec)

main.o: main.cpp maze.hpp
	$(CC) -c main.cpp

maze.o: maze.cpp maze.hpp
	$(CC) -c maze.cpp

node.o: node.cpp node.hpp
	$(CC) -c node.cpp

linkedList.o: linkedList.cpp linkedList.hpp
	$(CC) -c linkedList.cpp

stack.o: stack.cpp stack.hpp
	$(CC) -c stack.cpp

queue.o: queue.cpp queue.hpp
	$(CC) -c queue.cpp

clean:
	rm -f *.o $(exec)
