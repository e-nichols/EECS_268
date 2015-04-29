MazeLab: main.o MazeCreationException.o MazeReader.o Position.o MazeWalker.o
	g++ -g -std=c++11 -Wall main.o MazeReader.o Position.o MazeCreationException.o MazeWalker.o -o MazeLab

main.o: main.cpp MazeCreationException.h MazeCreationException.cpp Position.h Position.cpp
	g++ -g -std=c++11 -Wall -c main.cpp

MazeCreationException.o: MazeCreationException.h MazeCreationException.cpp
	g++ -g -std=c++11 -Wall -c MazeCreationException.cpp

MazeReader.o: MazeReader.h MazeReader.cpp
	g++ -g -std=c++11 -Wall -c MazeReader.cpp

MazeWalker.o: MazeWalker.h MazeWalker.cpp
	g++ -g -std=c++11 -Wall -c MazeWalker.cpp

Position.o: Position.h Position.cpp
	g++ -g -std=c++11 -Wall -c Position.cpp

clean:
	rm *.o MazeLab
	echo clean done
