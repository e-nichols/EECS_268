/**
*	@file : Stack.hpp
*	@author : Evan Nichols
*	@date : 2015.3.3
*	Purpose: Implementation of the Stack Class. 
*/

#include <iostream>
#include <string>
#include <stdexcept>
#include "Stack.h"

//CONSTRUCTOR
template <typename T>
Stack<T>::Stack(){

m_size = 0;
m_top = NULL;

}

//DESTRUCTOR
template <typename T>
Stack<T>::~Stack(){

Node<T>* temp = m_top;
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

//IS IT EMPTY
template <typename T>
bool Stack<T>::isEmpty() const{

	bool isEmpty = false;

	if(m_size == 0) {isEmpty = true;}

	return(isEmpty);
}


//PUSH A NODE ONTO THE STACK
template <typename T>
void Stack<T>::push(const T newEntry) {

Node<T>* temp = new Node<T>();
temp -> setValue(newEntry);
temp -> setBelow(m_top);
	if(m_size == 0) {
		m_top = temp;
	}
	else {
		m_top = temp;
	}
m_size++;
}

//POP A NODE OFF THE STACK
template <typename T>
T Stack<T>::pop() throw(PreconditionViolationException) {



	if(isEmpty()) {
		throw(PreconditionViolationException("Pop attempted on an empty stack."));
	}

	else {
		
	
		T myVal = m_top->getValue();
		//temp pointer now pointing at what m_top was pointing at
		Node<T>* temp = m_top-> getBelow();
		

		//whatever node m_top is pointing to, set it's Below pointer to null. 
		m_top -> setBelow(NULL);
		//then delete, and move m_top to point at temp, our new top object.
		delete m_top;
		m_top = temp;
		m_size--;
		std::cout << "Removal Successful. \n";
	
		return(myVal);
	}

m_size--;

}//end pop

//PEEK AT THE TOP NODE OF THE STACK
template <typename T>
T Stack<T>::peek() const throw(PreconditionViolationException) {

	if(isEmpty()) {
		throw(PreconditionViolationException("Peek attempted on an empty stack."));
	}

	else {
		return(m_top -> getValue());
	}



}

//FIND THE SIZE OF THE STACK
template <typename T>
int Stack<T>::size() const {

return(m_size);

}

//PRINT THE STACK
template <typename T>
void Stack<T>::print() const {

Node<T>* curPtr = m_top;

	if(curPtr == nullptr) {
		std::cout << "List Empty. \n";
	}
	else {
		//while loop to print all Node Values
		while(curPtr != nullptr) {

			std::cout << curPtr -> getValue() << ", ";

			//advance the curPtr to next Node
			curPtr = curPtr -> getBelow();

		}
	}
}//end printList

//LESS THAN
template <typename T>
bool Stack<T>::operator< (const StackInterface<T>& rhs) const {

//true if this stacks size is less than rhs size

if(m_size < rhs.size()) {return true;}

else {return false;}
}

//LESS THAN OR EQUAL TO
template <typename T>
bool Stack<T>::operator<= (const StackInterface<T>& rhs) const {

if(m_size <= rhs.size()) {return true;}

else {return false;}

}

//GREATER THAN
template <typename T>
bool Stack<T>::operator> (const StackInterface<T>& rhs) const {

if(m_size > rhs.size()) {return true;}

else {return false;}

}

//GREAT THAN OR EQUAL TO
template <typename T>
bool Stack<T>::operator>= (const StackInterface<T>& rhs) const {

if(m_size >=rhs.size()) {return true;}

else {return false;}

}

//EQUALS
template <typename T>
bool Stack<T>::operator== (const StackInterface<T>& rhs) const {

if(m_size == rhs.size()) {return true;}

else {return false;}


}

//NOT EQUAL
template <typename T>
bool Stack<T>::operator!= (const StackInterface<T>& rhs) const {

if(m_size == rhs.size()) {return false;}

else {return true;}

}



