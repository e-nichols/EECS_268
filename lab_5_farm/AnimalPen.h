/**
*	@file : AnimalPen.n
*	@author : Evan Nichols
*	@date : 2015.3.4
*	Purpose: Header file for AnimalPen class
*/

#include "Stack.h"
#include "FarmAnimal.h"
#include <iostream>
#include <string>

#ifndef _AnimalPen
#define _AnimalPen

class AnimalPen: public Stack<FarmAnimal*> {

//note: class does not create any animals. Just the storage.

//Implement all methods here using existing stack methods (push, pop, top, empty)
//It's important to note here that the AnimalPen does not have a stack member, it is a specialized stack

public: 

/**
*  @pre None
*  @post None, empty constructor
*  @return 
*/
AnimalPen();

/**
*  @pre None
*  @post deletes all the animals in the stack
*  @return none (destructor)
*/
~AnimalPen();

//deletes all the animal in the stack
//(Yes, the stack class does have a build in destructor, but implement this anyway)

/**
*  @pre None
*  @post pushes the animal pointer onto the stack
*  @return none
*/
void addAnimal(FarmAnimal* animal);

/**
*  @pre None
*  @post None
*  @return a pointer to the next animal in the stack, does NOT remove it
*/
FarmAnimal* peekAtNextAnimal();

/**
*  @pre None
*  @post deletes animal and removes from stack
*  @return None
*/
void releaseAnimal();

/**
*  @pre None
*  @post None
*  @return boolean, treu if pen is empty
*/
bool isPenEmpty();

    //returns true is the pen is empty

};

#endif