/**
*	@file : Sorts.cpp
*	@author : Evan Nichols
*	@date : 2015.3.25
*	Purpose: Implementation File of the Sorts class.
*/

#include <string>
#include <iostream>
#include "sorts.h"

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
void sorts<T>::bogoSort(T arr[], int size) {

	while(!isSorted(arr,size)) {

	//Declare and seed a generator
	std::default_random_engine generator(time(nullptr));

	//Declare distribution and define the range of the random numbers -- min and max variables used
	std::uniform_int_distribution<int> distribution(0, size-1);

	//a single random generator is generated between 0 and size of array -1
	int myRandIndex = distribution(generator);

	if(arr[0]>arr[myRandIndex]) {

		int temp = arr[0];
		arr[0] = arr[myRandIndex];
		arr[myRandIndex] = temp;
	}

}


/*
Shuffle array
Check if sorted
Repeat until sorted
*/    	

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

		if(arr[i-1] > arr[i]) {return false;}
	}

return true;
    };

//end sorts class