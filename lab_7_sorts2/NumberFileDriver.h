/**
*	@file : NumberFileDriver.h
*	@author : Evan Nichols
*	@date : 2015.3.25
*	Purpose: Header File of the NumberFileDriver class.
*/

#ifndef NUMBERFILEDRIVER_H
#define NUMBERFILEDRIVER_H

#include <string>

class NumberFileDriver {

public: 
/**
*  @pre 2D array and the arguments contained within are valid, argc and agrv passed directly from main
*  @post none
*  @return file is created containing the timing information and chosen sort(s) on the supplied file
*/
	static void run(int argc, char** argv);
   

/**
*  @pre 2D array and the arguments contained within are valid, argc and agrv passed directly from main
*  @post none
*  @return file is created containing the timing information and chosen sort(s) on the supplied file
*/	
    static void printHelpMenu(); 

private:

/*
*   @pre None
*   @post Prints a menus to help the user use the NumberFileGenerator
*   @returns True is the option passed in is valid. Valid options are: "-a", "-d", "-r", and "-s". This is case sensitive.
*/
	static bool isValidOption(std::string option);

};

#endif