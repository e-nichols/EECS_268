lab2: main.o LinkedList.o Node.o 
	g++ -std=c++11 -g main.o LinkedList.o Node.o -o lab2

main.o: main.cpp LinkedList.h Node.h
	g++ -std=c++11 -g -c main.cpp

LinkedList.o: LinkedList.h LinkedList.cpp
	g++ -std=c++11 -g -c LinkedList.cpp

Node.o: Node.h Node.cpp
	g++ -std=c++11 -g -c Node.cpp

clean:
	rm *.o lab2
