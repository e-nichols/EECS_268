lab5: main.o PreconditionViolationException.o AnimalPen.o FarmAnimal.o Chicken.o CyberChicken.o Cow.o
	g++ -g -std=c++11 main.o PreconditionViolationException.o AnimalPen.o FarmAnimal.o Chicken.o CyberChicken.o Cow.o -Wall -o lab5

main.o: main.cpp Node.h Node.hpp 
	g++ -g -std=c++11 -Wall -c main.cpp

PreconditionViolationException.o: PreconditionViolationException.h PreconditionViolationException.cpp
	g++ -g -std=c++11 -c PreconditionViolationException.cpp

AnimalPen.o: Stack.h Stack.hpp StackInterface.h Node.h Node.hpp AnimalPen.h AnimalPen.cpp
	g++ -g -std=c++11 -Wall -c AnimalPen.cpp

FarmAnimal.o: FarmAnimal.h FarmAnimal.cpp
	g++ -g -std=c++11 -c FarmAnimal.cpp

Chicken.o: Chicken.h Chicken.cpp
	g++ -g -std=c++11 -c Chicken.cpp

CyberChicken.o: Chicken.h Chicken.cpp CyberChicken.h CyberChicken.cpp
	g++ -g -std=c++11 -c CyberChicken.cpp

Cow.o: FarmAnimal.h FarmAnimal.cpp Cow.h Cow.cpp
	g++ -g -std=c++11 -c Cow.cpp

clean:
	rm *.o lab5
	echo clean done
