/**
*	@file : SortsDriver.cpp
*	@author :  Evan Nichols
*	@date : 2015.4.8
*	Purpose: Implementation file of Sorts Driver Class. 
*/
#include <string>
#include <iostream>
#include <fstream>
#include <functional>

#include "SortsDriver.h"
#include "sorts.h"


//helper method to help stupid user get through their error
void SortsDriver::printHelpMenu()
{
	std::cout << "\nSorting is done one of the following ways:\n\n"
			<< "./prog -sort -bubble inputFile outputFile\n"
			<< "./prog -sort -selection inputFile outputFile\n"
			<< "./prog -sort -insertion inputFile outputFile\n"
			<< "./prog -sort -quick inputFile outputFile\n"
			<< "./prog -sort -quick3 inputFile outputFile\n"
			<< "./prog -sort -merge inputFile outputFile\n"
			<< "./prog -sort -all inputFile outputFile\n"
			<< "Option explanations:\n"
			<< "\t-bubble to time bubble sort and store all timing results in outputFile\n"
			<< "\t-selection to time selection sort and store all timing results in outputFile\n"
			<< "\t-insertion to time insertion sort and store all timing results in outputFile\n"
			<< "\t-quick to time quick sort and store all timing results in outputFile\n"
			<< "\t-quick3 to time quick3 sort  and store all timing results in outputFile\n"
			<< "\t-merge to time merge sort  and store all timing results in outputFile\n"
			<< "\t-all to time all of the sorts and store all timing results in outputFile\n"
			<< "\tinputFile must be file created by a NumberFileGenerator\n"
			<< "\toutputFile must be to a valid path. It will hold the timing results\n";

}

void SortsDriver::run(int argc, char** argv) {

	//create new input stream based off third argument, which is the input file name
	std::ifstream input(argv[3]);
	int size = getFileCount(input);
	int* arr = createArray(input, size);

	int* arr2 = new int[size];
	copyArray(arr, arr2, size);

	//create a new output stream based on the output file name, which is fourth argument
	std::ofstream outputFile(argv[4]);

	//sortType is saved as a string based off argument 2
	std::string sortType = argv[2];

	//input fileName saved from argument 3
	std::string inputFileName = argv[3];


	if(areParametersValid(sortType, inputFileName)){

		if(sortType == "-bubble") {

			outputFile << "Bubble Sort sorted " << size << " numbers in ";
			sorts<int>::sortTimer(sorts<int>::bubbleSort, arr2, size);
			outputFile << " seconds\n";
		}

		else if(sortType == "-insertion") {

			outputFile << "Insertion Sort sorted " << size << " numbers in ";
			outputFile << sorts<int>::sortTimer(sorts<int>::insertionSort, arr2, size);
			outputFile << " seconds\n";

		}

		else if(sortType == "-selection") {

			outputFile << "Selection Sort sorted " << size << " numbers in ";
			outputFile << sorts<int>::sortTimer(sorts<int>::selectionSort, arr2, size);
			outputFile << " seconds\n";

		}

		else if(sortType == "-quick") {

			outputFile << "Quick Sort sorted " << size << " numbers in ";
			outputFile << sorts<int>::sortTimer(sorts<int>::quickSort, arr2, size);
			outputFile << " seconds\n";

		}

		else if(sortType == "-quick3") {

			outputFile << "Quick Sort Median sorted " << size << " numbers in ";
			outputFile << sorts<int>::sortTimer(sorts<int>::quickSortMedian, arr2, size);
			outputFile << " seconds\n";

		}

			else if(sortType == "-merge") {

			outputFile << "Merge Sort sorted " << size << " numbers in ";
			outputFile << sorts<int>::sortTimer(sorts<int>::mergeSort, arr2, size);
			outputFile << " seconds\n";

		}

			else if(sortType == "-all") {

			outputFile << "Bubble Sort sorted " << size << " numbers in ";
			outputFile << sorts<int>::sortTimer(sorts<int>::bubbleSort, arr2, size);
			outputFile << " seconds\n";
			outputFile << "Selection Sort sorted " << size << " numbers in ";
			outputFile << sorts<int>::sortTimer(sorts<int>::selectionSort, arr2, size);
			outputFile << " seconds\n";
			outputFile << "Insertion Sort sorted " << size << " numbers in ";
			outputFile << sorts<int>::sortTimer(sorts<int>::insertionSort, arr2, size);
			outputFile << " seconds\n";
			outputFile << "Quick Sort sorted " << size << " numbers in ";
			outputFile << sorts<int>::sortTimer(sorts<int>::quickSort, arr2, size);
			outputFile << " seconds\n";
			outputFile << "Quick Sort Median sorted " << size << " numbers in ";
			outputFile << sorts<int>::sortTimer(sorts<int>::quickSortMedian, arr2, size);
			outputFile << " seconds\n";
			outputFile << "Merge Sort sorted " << size << " numbers in ";
			outputFile << sorts<int>::sortTimer(sorts<int>::mergeSort, arr2, size);
			outputFile << " seconds\n";

		}

		std::cout << "Calculating sort timing information...\n";
		std::cout << "Calculations finished. Results stored in " << argv[4] << "\n";
		std::cout << "Exiting...\n";
}
		else {
			printHelpMenu();
		}

outputFile.close();
delete[] arr;
delete[] arr2;

}
//end run


bool SortsDriver::isFileAccessible(std::string fileName) {

	std::ifstream file(fileName);

	//checks whether or not the file is "good" AKA whether it exists and is readable
	return(file.good());


}

bool SortsDriver::isSortValid(std::string sortParameter){

	//checks to make sure a valid sort type was passed by user
	if (sortParameter == "-bubble" || "-selection" || "-insertion" || "-quick" || "-quick3" || "-merge" || "-all"){
		
		return(true);
	}

	else {
		return false;
	}
}

bool SortsDriver::areParametersValid(std::string sortName, std::string inputFileName){

	if (isFileAccessible(inputFileName) && isSortValid(sortName)){

		return(true);

	}
	else{

		return(false);
	}
} 

int SortsDriver::getFileCount(std::ifstream& inputFile){

	int count;
	inputFile >> count;

	return(count);


}

int* SortsDriver::createArray(std::ifstream& inputFile, int size){

	int* arr = new int[size];

	for(int i = 0; i < size; i++) {
		inputFile >> arr[i];
	}

	return(arr);


}

void SortsDriver::copyArray(int original[], int copy[], int size){

	for(int i = 0; i < size; i++) {

		copy[i] = original[i];
	}


}


