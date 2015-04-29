/**
*	@file : Sorts.cpp
*	@author : Evan Nichols
*	@date : 2015.3.25
*	Purpose: Implementation File of the Sorts class.
*/

#include <random>
#include <ctime>
#include <cassert>
#include <iostream>
#include <functional>

//#include "sorts.h"

template <typename T>
void sorts<T>::bubbleSort(T arr[], int size) {

int i = 0;
//int j = 0;

/* while the array isn't sorted... */
	while(!isSorted(arr,size)) {

		for (i = 0; i < size - 1; i++) {

			if(arr[i+1] < arr[i]) {						
		
				/* Swap Code */
				int temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
			}
		}
	}

	assert(sorts<T>::isSorted(arr, size));
}

template <typename T>    
void sorts<T>::insertionSort(T arr[], int size) {

/*
Iterates through array, growing sorted list one element at a time
First element is skipped
*/

	for (int i = 1; i <= size; i++) {

		int j = i;

			while (j > 0 && arr[j-1] > arr[j]) {
		
				int temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
				//swap A[j] and A[j-1]

				j--;
			}
	}

	assert(sorts<T>::isSorted(arr, size));
}//end Insertion

template <typename T>   
void sorts<T>::mergeSort(T arr[], int size) {

	//size=1 case, just return the array as is
	if(size <=1) {
		return;
	}
	else {

		//partition the array into two, splitting evenly if possible
		int size1 = size/2;
		int size2 = size - size1;

		//pointers at the beginning of the two partitions, using pointer arithmetic to
		//specify the beginning indices
		T* leftArray = arr;
		T* rightArray = (arr+size1);

		//recursively mergeSort. Will keep partitioning until the size is 1.
		//once that is done, run merge to recursively "put the pieces back together"
		mergeSort(leftArray, size1);
		mergeSort(rightArray, size2);
		merge(leftArray, rightArray, size1, size2);
	}

assert(sorts<T>::isSorted(arr,size));

}//end merge

template <typename T>
void sorts<T>::quickSort(T arr[], int size){

  quickSortRec(arr, 0, (size-1), false);

}//end quickSort  

template <typename T>
void sorts<T>::quickSortMedian(T arr[], int size){

  quickSortRec(arr, 0, (size-1), true);

 }	//end quickSortMedian
   
template <typename T>   
void sorts<T>::selectionSort(T arr[], int size) {

/* a[0] to a[n-1] is the array to sort */
    int i = 0, j = 0;
    int iMin;

/* advance the position through the entire array */
/* could do j < n - 1 because single element is also the min element */

    for (j = 0; j < size - 1; j++) {

   		/* find the min element in the unsorted a[j....n-1] */

   		/* assume the min is the first element, note that this is not the actual value but the index it is located at */
    	iMin = j;

    	/* test against elements after j to find the smallest value */

    	for ( i = j+1; i < size; i++) {

    		/* if this element is less than j, then it will be the new minimum */

			if(arr[i] < arr[iMin]) {
				/* found new min, save the index as iMin */
    			iMin = i;
    		}
    	}

    	/* make the switch if a new min value was found that was NOT j */
    	if(iMin != j) {

   			/* temp value stores j while swap is made */
   			int temp = arr[j];
   			arr[j] = arr[iMin];
   			arr[iMin] = temp;
   		}
    }

    assert(sorts<T>::isSorted(arr, size)); 
}

template <typename T>  
bool sorts<T>::isSorted(T arr[], int size) {

	//check for ascending order

	for(int i = 1; i < size; i++) {

		if(arr[i-1] > arr[i]) {
			return false;
		}
	}

return true;

}

template <typename T>  
void sorts<T>::merge(T* left, T* right, int leftSize, int rightSize) {

	//create a temporary array to which to hold all values of merged array
	T* buffer = new T[leftSize+rightSize];

	int leftIndex,rightIndex,k = 0;

	while(leftIndex < leftSize && rightIndex < rightSize) {

		//If the left value is smaller than the right is goes into the cool array next
		if(left[leftIndex] <= right[rightIndex]) {

			buffer[k] = left[leftIndex];
			leftIndex++;
		}
		else {
			buffer[rightIndex] = right[rightIndex];
			rightIndex++;
		}
		k++;
	}

	//Push the remaining data from both arrays onto the Buffer Array

	while(leftIndex < leftSize) {

		buffer[k] = left[leftIndex];
		
		//increase counters
		leftIndex++;
		k++;
	}

	while (rightIndex < rightSize) {

		buffer[k] = right[rightIndex];
		k++;
		rightIndex++;

	}

	for (int c = 0; c<k; c++) {

		//copy the sorted values into the array
		left[c] = buffer[c];
	}

	delete[] buffer;

}//end merge

template <typename T>  
void sorts<T>::quickSortRec(T arr[], int first, int last, bool median){

int pivot;
int size = (last+1) - first;

	if(size <=1) {
		return;
	}

	else {

		pivot = partition(arr, first, last, median);
		quickSortRec(arr, first, pivot-1, median);
		quickSortRec(arr, pivot+1, last, median);
	}
} 

template <typename T>
double sorts<T>::sortTimer(std::function<void(T[], int)> sort, T arr[], int size){

	std::chrono::system_clock::time_point start;
	std::chrono::system_clock::time_point end;
	std::chrono::duration<double> elapsed;

	start = std::chrono::system_clock::now();
	sort(arr, size);
	end = std::chrono::system_clock::now();

	elapsed = end - start;
	return(elapsed.count());

}

template <typename T>  
void sorts<T>::setMedianPivot(T arr[], int first, int last){

	int pivot = (last+first)/2;
	T temp;

	temp = arr[pivot];
	arr[pivot] = arr[last];
	arr[last] = temp;


}

template <typename T>
int sorts<T>::partition(T arr[], int first, int last, bool median){

	int left = first;
	int right = last-1;
	int pivot = last;
	T temp;

	if (median){
		setMedianPivot(arr, first, last);
	}

	while (left != right){
	 
	  if (arr[left] <= arr[pivot]){

	    ++left;
	  }
	  else if (arr[right] > arr[pivot]){
	    
	    --right;
	  }
	  else{
	    temp = arr[left];
	    arr[left] = arr[right];
	    arr[right] = temp;
	  }
	}

	
	if (arr[left] > arr[pivot]){
	  temp = arr[pivot];
	  arr[pivot] = arr[left];
	  arr[left] = temp;
	  pivot = left;
	}

	return(pivot);
}

template <typename T>  
void sorts<T>::shuffle(T arr[], int size, std::default_random_engine& generator){

	int randIndex;
	int temp;

	//initialize generator
	std::uniform_int_distribution<int> distribution(0, (size-1));

	for(int i = 0; i<size; i++) {

		randIndex = distribution(generator);

		temp = arr[i];
		arr[i] = arr[randIndex];
		arr[randIndex] = temp;
	}
}

//end sorts class
