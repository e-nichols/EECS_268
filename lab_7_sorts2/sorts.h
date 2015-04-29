/**
*	@file : Sorts.h
*	@author :  Evan Nichols
*	@date : 2015.2.24
*	Purpose: Header file of sorts Class. 
*/

#ifndef SORTS_H
#define SORTS_H

#include <random>
#include <ctime>
#include <cassert>
#include <functional>
#include <chrono>

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
*  @post sorts the array in ascending order using Insertion Sort implementation
*  @return None (static void)
*/    
    static void insertionSort(T arr[], int size);

/**
*  @pre array and array size must match for function to run
*  @post sorts the array in ascending order using Merge sort implementation
*  @return None (static void)
*/
    static void mergeSort(T arr[], int size);

/**
*  @pre array and array size must match for function to run
*  @post sorts the array in ascending order using quickSort implementation
*  @return None (static void)
*/
    static void quickSort(T arr[], int size);

/**
*  @pre array and array size must match for function to run
*  @post sorts the array in ascending order using quickSortMedian implementation with median flag set to false
*  @return None (static void)
*/
    static void quickSortMedian(T arr[], int size);


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

/**
*  @pre arr is valid array of T size elements, and the < operator is overloaded for T.
*  @post sort must be capable of sorting arr in ascending order, or asset ends program
*  @return returns the time, in secs, the sort required to arr
*/  

	double sortTimer(std::function<void(T[], int)> sort, T arr[], int size);


private:

/**
*  @pre used by merge sort to two sorted combine arrays (which are actually two halved of a single array) 
*  @post none
*  @return into a single sorted array
*/

	static void merge(T* left, T* right, int leftSize, int rightSize);

/**
*   @pre sorts array by partitioning the array, quick sorting every left val of the pivot
*   @post
*   @return sorts the array (static)
*/

     static void quickSortRec(T arr[], int first, int last, bool median);

/**
*	@pre being used by QuickSort
*	@post puts median of the array in the last position
*	@return none (static)
*/

	 static void setMedianPivot(T arr[], int first, int last);


/**
*	@pre used by quickSort
*	@post partitions the array
*	@return none (static)
*/

	static int partition(T arr[], int first, int last, bool median);

/**
*	@pre valid array and size 
*	@post shuffles each index in the array with another random index
*	@return none (static)
*/

	static void shuffle(T arr[], int size, std::default_random_engine& generator);

};

#include "sorts.hpp"

#endif
