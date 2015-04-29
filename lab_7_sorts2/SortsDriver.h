/**
*	@file : SortsDriver.h
*	@author :  Evan Nichols
*	@date : 2015.4.8
*	Purpose: Implementation file of Sorts Driver Driver Class. 
*/

#ifndef SORTSDRIVER_H
#define SORTSDRIVER_H

#include <string>
#include <fstream>
#include "sorts.h"
//Note: SortsDriver class has no member variables as all methods are static

class SortsDriver {

public:

/**
*  @pre user had an input error
*  @post none
*  @return menu printed to console
*/
	static void run(int argc, char** argv);

/**
*  @pre user had an input error
*  @post none
*  @return menu printed to console
*/
	static void printHelpMenu();

private: 

/**
*  @pre the input file was created with the Number File Generator
*  @post none
*  @return true if the file exists, false otherwise
*/
	static bool isFileAccessible(std::string fileName);

/**
*  @pre user had an input error
*  @post none
*  @return bool, returns True if the sort parameter matches a valid one (see help menu). 
*/
	static bool isSortValid(std::string sortParameter);

/**
*  @pre none
*  @post none
*  @return returns true if the file specified by inputFileName exists and the sort parameter is valid, false otherwise
*/
	 static bool areParametersValid(std::string sortName, std::string inputFileName); 

/**
*  @pre the input file was created with the Number File Generator
*  @post the first line of the file is read in, containing the count
*  @return returns how many numbers are in the file
*/
	static int getFileCount(std::ifstream& inputFile); 

/**
*  @pre the input file was created with the Number File Generator, the size was read in, and that size if correct. 
*  @post the remainder of input file numbers are read in. File is NOT closed. 
*  @return returns a pointer to the new array containing the values from the input file
*/
	static int* createArray(std::ifstream& inputFile, int size); 

/**
*  @pre original and copy are valid arrays of correct size
*  @post all values from original are copied into copy 
*  @return none
*/
	static void copyArray(int original[], int copy[], int size); 


};

#endif
