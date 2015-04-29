/**
*	@file : LinkedList.h
*	@author :  Evan Nichols
*	@date : 2015.2.5
*	Purpose: Implementation file of LinkedList Class. 
*/

#include <iostream>
#include "LinkedList.h"
#include "Node.h"


//CONSTRUCTOR CLASS
LinkedList::LinkedList() {

m_front = nullptr;
m_size = 0;

}

//DESTRUCTOR CLASS 
LinkedList:: ~LinkedList(){

//declare temporary pointer which points at m_front
Node* temp = m_front;

//while loop to delete all elements
while(m_front != nullptr) {

	//that temp pointer is now pointing at what m_front was pointing at
	temp = m_front->getNext();

	//dereference m_front's pointer, setting it to null
	m_front -> setNext(nullptr);

	//delete the actual node instance m_front
	delete m_front;

	//m_front is now equal to the object at which temp was pointing, our new first node.
	m_front = temp;

}//end while

m_size=0;

}


//IS THE LIST EMPTY
bool LinkedList::isEmpty() const {

bool isEmpty;

	if (m_size == 0) {isEmpty = true;}
	else {isEmpty = false;}

return(isEmpty);
}

//WHAT IS THE SIZE OF THE LIST
int LinkedList::size() const {return(m_size);}

//SEARCH THE LIST FOR A VALUE
bool LinkedList::search(int value) const {

bool found = false;
Node* curPtr = m_front;

	while(found == false && (curPtr != nullptr)) {

		if(value == curPtr -> getValue()) {found = true;}
		else {curPtr = curPtr -> getNext();}

	}//end while

return(found);
}

//PRINT THE LIST VALUES
void LinkedList::printList() const {

Node* curPtr = m_front;

	if(curPtr == nullptr) {
	std::cout << "Nothing to Print. List Currently Empty. \n";
	}
	else {

	std::cout << "Printing List: \n";

		//while loop to print all Node Values
		while(curPtr != nullptr) {

		std::cout << curPtr -> getValue() << " ";

		//advance the curPtr to next Node
		curPtr = curPtr -> getNext();

		}//end while
	}//end else
}//end printList


//ADD NODE TO FRONT
	//make new ptr
	//set that ptr's value
	//new ptr -> setNext(headPtr)
	//headPtr = new ptr
	//itemcount ++

void LinkedList::addFront(int value) {

Node* n = new Node();
n -> setValue(value);
n -> setNext(m_front);

m_front = n;

m_size++;

}

//ADD NODE TO BACK
	//make new ptr
	//set that ptr's value
	//new ptr -> setNext(headPtr)
	//headPtr = new ptr
	//itemcount ++

void LinkedList::addBack(int value) {

Node* curPtr = m_front;

if(curPtr == nullptr) {

Node* n = new Node();
n -> setValue(value);
m_front = n;

}

else {

while((curPtr -> getNext()) != nullptr) {

	curPtr = curPtr -> getNext();
}

Node* n = new Node();
n -> setValue(value);

curPtr -> setNext(n);

}//end else
}


//REMOVE FRONT

void LinkedList::removeFront(){

//declare temporary pointer which points at m_front
Node* temp = m_front;

	if(temp == nullptr) {
		std::cout << "Removal unsuccessful. List already empty. \n";
	}
	else {
		//that temp pointer is now pointing at what m_front was pointing at
		temp = m_front->getNext();

		//dereference m_front's pointer, setting it to null
		m_front -> setNext(nullptr);

		//delete the actual node instance m_front
		delete m_front;

		//m_front is now equal to the object at which temp was pointing, our new first node.
		m_front = temp;

		m_size--;

		std::cout << "Removal Successful. \n";

	}//end else
}//end removeFront
 

//REMOVE BACK
void LinkedList:: removeBack() {

Node* prev;
Node* current = m_front;

	if(current == nullptr) {
	std::cout << "List Empty. Nothing to Remove. \n";
	}//end if
 
	else {
		while(current->getNext() != nullptr) {
		prev = current;
		current = current->getNext();
	}

//delete the item at which current was pointing to
delete current;

//set previous to now point to null as it is the last node in the list now.
prev -> setNext(nullptr);

//decrease size of list
m_size--;

std::cout << "Removal Successful. \n";

}//end else
}
//end Remove Back



