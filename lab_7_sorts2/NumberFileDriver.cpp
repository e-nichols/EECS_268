/**
*	@file : NumberFileDriver.cpp
*	@author : Evan Nichols
*	@date : 2015.3.25
*	Purpose: Implementation File of the NumberFileDriver class.
*/

#include "NumberFileDriver.h"
#include "NumberFileGenerator.h"

#include <string>
#include <iostream>
#include <fstream>

void NumberFileDriver::run(int argc, char** argv){

//save order as string from second passed argument
std::string order = argv[2];

	if (isValidOption(order)){
		
		if (order == "-a"){

			NumberFileGenerator::ascending(argv[3], atoi(argv[4]));	
			std::cout << argv[4] << " numbers stored in " << argv[3] << "\n";
		}

		else if (order == "-d"){

			NumberFileGenerator::descending(argv[3], atoi(argv[4]));
			std::cout << argv[4] << " numbers stored in " << argv[3] << "\n";
		}

		else if (order == "-s"){

			if (argc == 6){
				NumberFileGenerator::singleValue(argv[3], atoi(argv[4]), atoi(argv[5]));
				std::cout << argv[4] << " numbers stored in " << argv[3] << "\n";
			}

			else {
				printHelpMenu();
			}
		}

		else if (order == "-r"){
			
			if (argc == 7){
				NumberFileGenerator::random(argv[3], atoi(argv[4]), atoi(argv[5]), atoi(argv[6]));
				std::cout << argv[4] << " numbers stored in " << argv[3] << "\n";
			}
			else{
				printHelpMenu();
			}
		} 
	}

	else{
		
		printHelpMenu();
	}
}

    
//helper method
void NumberFileDriver::printHelpMenu(){
	std::cout << "\nUse Number File Generator in one of the following ways:\n\n"
			<< "./prog -create -a filename amount\n"
			<< "./prog -create -d filename amount\n"
			<< "./prog -create -s filename amount value\n"
			<< "./prog -create -r filename amount min max\n"
			<< "Option explainations:\n"
			<< "\t-a for ascending\n"
			<< "\t-d for descending\n"
			<< "\t-s for a single value\n"
			<< "\t-r for random values\n"
			<< "\tfilename is the ouput file name\n"
			<< "\tamount is the amount of random numbers to place in the file\n"
			<< "\tvalue is the single number that will be written to file in -s mode\n"
			<< "\tmin is the low end of the range of random numbers\n"
			<< "\tmax is the high end (non-inclusive) of the range of random numbers\n";

}

//private method to check for valid file specification
bool NumberFileDriver::isValidOption(std::string option){

	if(option == "-a" || "-d" || "-r" || "-s"){

		return(true);
	}
	else {

		printHelpMenu();
		return (false);
	}
}