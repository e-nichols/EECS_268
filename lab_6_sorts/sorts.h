/**
*	@file : Sorts.h
*	@author :  Evan Nichols
*	@date : 2015.2.24
*	Purpose: Header file of sorts Class. 
*/

#ifndef _sorts
#define _sorts

template <typename T>
class sorts {

//Note: sorts class has no member variables as all methods are static.

public:

/**
*  @pre array and array size must match for function to run
*  @post sorts the array in ascending order using Bubble Sort implementation
*  @return None (static void)
*/
    static void bubbleSort(T arr[], int size);

/**
*  @pre array and array size must match for function to run
*  @post sorts the array in ascending order using Bogo Sort implementation
*  @return None (static void)
*/
	static void bogoSort(T arr[], int size);
  
/**
*  @pre array and array size must match for function to run
*  @post sorts the array in ascending order using Insertion Sort implementation
*  @return None (static void)
*/    
    static void insertionSort(T arr[], int size);

/**
*  @pre array and array size must match for function to run
*  @post sorts the array in ascending order using Selection Sort implementation
*  @return None (static void)
*/
    static void selectionSort(T arr[], int size);

/**
*  @pre array and array size must match for function to run
*  @post none
*  @return boolean, true if array is in ascending order, false otherwise
*/    
    static bool isSorted(T arr[], int size);
};

#include "sorts.hpp"

#endif