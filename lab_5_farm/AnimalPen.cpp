/**
*	@file : AnimalPen.cpp
*	@author : Evan Nichols
*	@date : 2015.3.4
*	Purpose: Implementation file for AnimalPen class
*/

#include "AnimalPen.h"
#include "FarmAnimal.h"
#include "Stack.h"
#include <iostream>
#include <string>

AnimalPen::AnimalPen() {

}

AnimalPen::~AnimalPen() {

	Node<FarmAnimal*>* temp = m_top;
	while(m_top != nullptr) {

		//temp now pointing to item below m_top 
		temp = m_top -> getBelow();

		m_top -> setBelow(NULL);
		delete m_top;
		m_top = temp;
}

//do I need these lines?
delete temp;
delete m_top;
}

void AnimalPen::addAnimal(FarmAnimal* animal) {

	push(animal);
}

FarmAnimal* AnimalPen::peekAtNextAnimal() {

	return(peek());
}

void AnimalPen::releaseAnimal() {

	pop();

}

bool AnimalPen::isPenEmpty() {

return isEmpty();
}
