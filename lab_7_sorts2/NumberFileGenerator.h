/**
*	@file : NumberFileGenerator.h
*	@author : Evan Nichols
*	@date : 2015.3.25
*	Purpose: Header File of the NumberFileGenerator class.
*/

#ifndef NUMBERFILEGENERATOR_H
#define NUMBERFILEGENERATOR_H

#include <string>

//This class will contain all static method methods and hold no member variables. 

class NumberFileGenerator {

public:

/*
*	@prec fileName is valid path/filename. Amount is greater than zero
*	@post A file is created with the amount of number is ascending order. The amount of numbers in the file is the first entry in the file
*	@return none
*/
    static void ascending(std::string fileName, int amount);
    

/*
*	@prec fileName is valid path/filename. Amount is greater than zero
*	@post A file is created with the amount of number is descending order. The amount of numbers in the file is the first entry in the file
*	@return none
*/
    static void descending(std::string fileName, int amount);

/*
*	@prec fileName is valid path/filename. Amount is greater than zero
*	@post A file is created with the specified amount of numbers. All numbers are random and fall between min and max (inclusive)
*	@return none
*/
    static void random(std::string fileName, int amount, int min, int max);

/*
*	@prec fileName is valid path/filename. Amount is greater than zero
*	@post A file is created with a single number, specified by value, amount of times. The amount of numbers in the file is the first entry in the file
*	@return none
*/    
    static void singleValue(std::string fileName, int amount, int value);

};

#endif