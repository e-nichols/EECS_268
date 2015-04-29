lab7: main.o NumberFileGenerator.o NumberFileDriver.o SortsDriver.o 
	g++ -g -std=c++11 -Wall main.o SortsDriver.o NumberFileGenerator.o NumberFileDriver.o -o lab7

main.o: main.cpp SortsDriver.cpp NumberFileDriver.cpp NumberFileGenerator.cpp 
	g++ -g -std=c++11 -Wall -c main.cpp

SortsDriver.o: SortsDriver.h SortsDriver.cpp sorts.h sorts.hpp
	g++ -g -std=c++11 -Wall -c SortsDriver.cpp

NumberFileGenerator.o: NumberFileGenerator.h NumberFileGenerator.cpp
	g++ -g -std=c++11 -Wall -c NumberFileGenerator.cpp

NumberFileDriver.o: NumberFileDriver.h NumberFileDriver.cpp
	g++ -g -std=c++11 -Wall -c NumberFileDriver.cpp

clean:
	rm *.o lab7
	echo clean done
