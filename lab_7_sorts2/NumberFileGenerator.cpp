/**
*	@file : NumberFileDriver.cpp
*	@author : Evan Nichols
*	@date : 2015.3.25
*	Purpose: Implementation File of the NumberFileDriver class.
*/

#include "NumberFileGenerator.h"

#include <string>
#include <random>
#include <ctime>
#include <fstream>
#include <iostream>

void NumberFileGenerator::ascending(std::string fileName, int amount){

	//open new output stream
	std::ofstream file(fileName);
	
	//write to the output file the count
	file << amount << "\n";

	//populate output file with ascending numbers starting at 0
	for (int i=0; i<amount; i++){

		file << i << "\n";
	}
}

void NumberFileGenerator::descending(std::string fileName, int amount){

	std::ofstream file(fileName);

	file << amount << "\n";

	//populate output file with descending numbers starting at amount -1 (so as to end at 0)
	for (int i=amount-1; i>=0; i--){

		file << i << "\n";
	}
}

void NumberFileGenerator::random(std::string fileName, int amount, int min, int max){

	std::ofstream file(fileName);

	//intialize the random engine, create a uniform distribution of numbers between min and max
	std::default_random_engine generator(time(nullptr));
	std::uniform_int_distribution<int> distribution(min, max);

	int randomNumber;

	if (min < max){

	file << (amount) << "\n";

		for (int i=0; i<(amount); i++){

			//create a random number and populate file with it
			randomNumber = distribution(generator);
			file << randomNumber << "\n";
		}	
	}
	
	else{

		//error with min and max
		std::cout << "Sorry, Min and Max values are not valid.\n";
	}
}

void NumberFileGenerator::singleValue(std::string fileName, int amount, int value){

	std::ofstream file(fileName);

	//populate the array with a single value however many times specified by amount
	file << amount << "\n";

		for (int i=0; i<(amount); i++){

			file << value << "\n";
		}
}