/**
*	@file : Main.cpp
*	@author : Evan Nichols
*	@date : 2015.4.08
*	Purpose: Main.cpp allows users to interact with different sorting methods and compare their completion times. 
*/

#include "NumberFileGenerator.h"
#include "NumberFileDriver.h"
#include "SortsDriver.h"

#include <iostream>
#include <string>
#include <functional>
#include <fstream>

/*
*	 PURPOSE OF MAIN
*    Verifies there are at least 5 command line arguments
*    Verifies the first parameter is either "-create" (for number file generation) or "-sort" (for sort timing)
*    Prints the help menus from both the NumberFileDriver and SortDriver class when problem is detected
*    If at least 5 command line arguments are passed in and the user chose to "-create" or "-sort", the argc and argv are then passed to the appropriate run method.
*/

int main(int argc, char** argv) {

	std::string mode = argv[1];

	if(argc >= 5) {

		if(mode == "-create") {

			//runs the number file generator

			NumberFileDriver::run(argc, argv);
		}
		else if(mode == "-sort") {

			//runs the sort driver
			SortsDriver::run(argc,argv);

		}
		else {
			NumberFileDriver::printHelpMenu();
			SortsDriver::printHelpMenu();
		}

		return(0);
	}
}


/*
	//two optional arguments for the main () -- argc and argv. Number of arguments and type of arguments and their list.

	//reading and writing to a file -- this actually works!!!

	//compile main only in terminal using g++ main.cpp -o main.o

	std::ofstream myOutputFile("numbers.dat");

	int nnum = 20;

	myOutputFile << nnum << "\n";

	for(int i = 0; i < nnum; i++) {

		myOutputFile << i << " ";
	}

	myOutputFile.close();

	//read from a file

	std::ifstream myInputFile("numbers.dat");

	if(!myInputFile.good()) {

		std::cout << "Input file read failure\n";
		return(-1);
	}

	int* arr = new int[nnum];
	int cnt = 0;
	while(myInputFile >> arr[cnt]) {

		cnt++;
	}

	for(int i = 0; i < cnt; i++) 
		std::cout << arr[i] << " ";
	std::cout << "\n";

	myInputFile.close();


}

*/
