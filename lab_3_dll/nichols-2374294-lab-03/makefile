lab3: main.o
	g++ -g -std=c++11 main.o -o lab3

main.o: DoubleLinkedList.h DoubleLinkedList.hpp Node.h Node.hpp
	g++ -g -std=c++11 -c main.cpp

clean:
	rm *.o lab3
	echo clean done
