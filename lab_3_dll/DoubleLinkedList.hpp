/**
*	@file : LinkedList.h
*	@author :  Evan Nichols
*	@date : 2015.2.5
*	Purpose: Implementation file of DoubleLinkedList Class. 
*/

#include <iostream>
#include <string>
#include <stdexcept>
#include "DoubleLinkedList.h"
#include "Node.h"


//CONSTRUCTOR
template <typename T> 
DoubleLinkedList<T>::DoubleLinkedList() {

	//size is set to 0, front and back pointers set to null.
	m_size = 0;
	m_front = nullptr;
	m_back = nullptr;

}

//DESTRUCTOR
template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList() {

	Node<T>* temp = m_front;

	while(m_front != nullptr) {

		//Temp is now pointing at the node directly behind front.
		temp = m_front -> getNext();
		
		//setting the front node's m_previous pointer to null.
		m_front -> setPrev(nullptr);
		
		//setting temp's m_next (which was just pointing at front) to null.
		temp -> setNext(nullptr);
		
		//with all pointers taken care of, we can now delete the front node. 
		delete m_front;
		
		//advance front pointer. 
		m_front = temp;
	}

	//**IS IT NECESSARY TO DELETE TEMP HERE???
	//delete temp;
	m_back = nullptr;

}

//IS IT EMPTY
template <typename T>
bool DoubleLinkedList<T>::isEmpty() const {
	if(m_size == 0) {
		return(true);
	}
	else {
		return(false);
	}
}

//WHAT'S THE SIZE
template <typename T>
int DoubleLinkedList<T>::size() const {

	return(m_size);
}

// FIND THIS VALUE
template <typename T>
Node<T>* DoubleLinkedList<T>::find(T value) const {

Node<T>* temp = m_front;

	while(temp != nullptr) {
		
		if(temp -> getValue() == value) {
			return(temp);
		}
		temp = temp -> getNext();
	}

	return(nullptr);

}

//PRINT THE LIST
template <typename T>
void DoubleLinkedList<T>::printList() const {

	
Node<T>* curPtr = m_front;

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



//INSERT BEHIND
template <typename T>
void DoubleLinkedList<T>::insertBehind(T listVal, T newVal) throw(std::runtime_error) {

Node<T>* temp = new Node<T>();
temp -> setValue(newVal);
Node<T>* listValNode = find(listVal);

	if(listValNode -> getNext() == nullptr) {
	//indicates last element
		
		m_back -> setNext(temp);
		temp -> setNext(nullptr);
		temp -> setPrev(m_back);
		m_back = temp;
		temp = nullptr;

	}//end if

	else {

		Node<T>* secondtemp = listValNode -> getNext();

		temp -> setPrev(listValNode);
		
		listValNode -> setNext(temp);

		secondtemp -> setPrev(temp);

		temp -> setNext(secondtemp);

		//listValNode = listValNode -> getNext();

		//listValNode -> setPrev(temp);

		//temp -> setNext(listValNode);

		//temp = nullptr;

		//listValNode = nullptr;

	}//end else 

if(listValNode == nullptr || m_size == 0) { throw std::runtime_error("Could not insert behind.");}
}

//INSERT AHEAD
template <typename T>
void DoubleLinkedList<T>::insertAhead(T listVal, T newVal) throw (std::runtime_error) {

Node<T>* temp = new Node<T>();
temp -> setValue(newVal);
Node<T>* listValNode = find(listVal);

	if(listValNode -> getPrev() == nullptr) {
	//indicates the listValNode is at the front of the list

		m_front -> setPrev(temp);
		temp -> setPrev(nullptr);
		temp -> setNext(m_front);
		m_front = temp;
		temp = nullptr;
	
	} //end if
	else {
	//indicates anything else

		Node<T>* secondtemp = listValNode -> getPrev();
		listValNode -> setPrev(temp);

		temp -> setNext(listValNode);

		secondtemp -> setNext(temp);
		temp -> setPrev(secondtemp);

		//listValNode = listValNode -> getPrev();

		//temp -> setPrev(listValNode);

		//listValNode -> setNext(temp);

		//listValNode = nullptr;

		temp = nullptr;

	}//end else

//Not sure if this is the proper way to throw exception?
if(listValNode == nullptr || m_size == 0) { throw std::runtime_error("Could not insert ahead.");}



}

//PUSH BACK
template <typename T>
void DoubleLinkedList<T>::pushBack(T value) {

	Node<T>* temp = new Node<T>();
	temp -> setValue(value);
	//temp -> setPrev(nullptr);

	if(m_size == 0) {


		//temp -> setNext(nullptr);
		m_front = temp;
		m_back = temp;

	}
	else {		
		m_back -> setNext(temp);
		m_back = temp;

	}

	m_size++;
		
	}

//PUSH FRONT
template <typename T>
void DoubleLinkedList<T>::pushFront(T value) {

	Node<T>* temp = new Node<T>();
	temp -> setValue(value);
	//temp -> setNext(nullptr);

	if(m_size == 0 ) {

		//temp -> setPrev(nullptr);
		m_front = temp;
		m_back = temp;

	}
	else {
		m_front -> setPrev(temp);		
		temp -> setNext(m_front);
		m_front = temp;

	}

	m_size++;
}

template <typename T>
bool DoubleLinkedList<T>::remove(T value) {

	Node<T>* temp = find(value);

	if(m_size == 0 || temp == nullptr) {
		//indicates an empty list or the value doesn't exist in any of the nodes

		return(false);
	}
	else if (m_size == 1 && temp != nullptr) {
		m_back = nullptr;
		delete m_front;
		//m_front = nullptr;
		m_size--;
	}
	else {
		
		if(temp -> getPrev()==nullptr) {
			
			//indicates first element in the list
			m_front = temp -> getNext();
			
			m_front -> setPrev(nullptr);
			
			temp -> setNext(nullptr);
			
			delete temp;
			
			//temp = nullptr;

		}
		else if (temp -> getNext() == nullptr) {
			//indicates last node

			m_back = temp -> getPrev();
			temp -> setPrev(nullptr);
			m_back -> setNext(nullptr);
			delete temp;
			//temp = nullptr;
		}
		else {
			//indicates NOT front or back. Just a middle element
			Node<T>* skip = temp->getNext();
			skip -> setPrev(temp -> getPrev());
			skip = temp -> getPrev();
			skip -> setNext(temp -> getNext());
			
			temp -> setNext(nullptr);
			temp -> setPrev(nullptr);
			delete temp;
			temp = nullptr;
			skip = nullptr;
			//AGAIN, is it necessary for me to set temp and skip to null?
		}	
		m_size--;
return(true);
	}
}






/*
1. DoubleLinkedList(); CREATED!

2. ~DoubleLinkedList(); CREATED!

3. bool isEmpty() const; CREATED!

4. int size() const; CREATED!

5. Node<T>* find (T value) const; CREATED!

6. void printList() const; CREATED!

7. void insertBehind(T listVal, T newVal); NOT CREATED

8. void insertAhead(T listVal, T newVal); NOT CREATED

9. void pushBack(T value); CREATED!

10. void pushFront(T value); CREATED!

11. void remove(T value); CREATED!
*/


