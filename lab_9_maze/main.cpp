/**
*	@file : Main.cpp
*	@author : Evan Nichols
*	@date : 2015.4.20
*	Purpose: Main.cpp lets users interact and navigate different inputted maze files.
*/


#include <iostream>
#include <cstdlib>
#include <string>
#include <functional>
#include <fstream>
#include <random>

#include "MazeReader.h"
#include "MazeWalker.h"
#include "Position.h"
#include "MazeCreationException.h"

int main (int argc, char** argv) {

	std::cout << "Maze Walker Program\n";
	std::cout << "Evan Nichols, EECS 268\n\n";
	std::string mazeFile;
	std::string searchString;
	bool searchType;
	MazeReader* myReader = nullptr;
	MazeWalker* myWalker = nullptr;

	if(argc > 1) 
	{
		if(argc == 1)
		{
			std::cout << "Error: no search type flag. Program terminating\n";
			return(-1);
		}

		mazeFile = argv[1];
		searchString = argv[2];

		if(searchString == "-bfs")
		{
			searchType = false;
			std::cout << "Running breadth first search on " << mazeFile << "\n";
		}
		
		else if(searchString == "-dfs")
		{
			searchType = true;
			std::cout << "Running depth first search on " << mazeFile << "\n";
		}

		try 
		{
			//create new MazeReader
			myReader = new MazeReader(mazeFile);

		}
		
		catch (MazeCreationException e) 
		{
			 std::cout << e.what();
		}
	}

	try 
	{
		//creating MazeWalker
		myWalker = new MazeWalker(myReader -> getMaze(), myReader -> getStartRow(), myReader -> getStartCol(), myReader -> getRows(), myReader -> getCols(), searchType);
	}

	catch(MazeCreationException e) 
	{
		std::cout << e.what();
	}

	myWalker -> walkMaze();

	std::cout << "Thanks for Playing!\n"
		<<"\nEvan Nichols, C. 2015\n";

delete myWalker;
delete myReader;

	return(0);

}
