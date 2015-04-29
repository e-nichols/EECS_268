lab8: main.o ValueNotFoundException.o
	g++ -g -std=c++11 -Wall main.o ValueNotFoundException.o -o lab8

main.o: main.cpp BinarySearchTree.h BinarySearchTree.hpp BSTI.h
	g++ -g -std=c++11 -Wall -c main.cpp

ValueNotFoundException.o: ValueNotFoundException.h ValueNotFoundException.cpp
	g++ -g -std=c++11 -Wall -c ValueNotFoundException.cpp

clean:
	rm *.o lab8
	echo clean done
