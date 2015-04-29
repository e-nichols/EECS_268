/**
*	@file : LinkedList.h
*	@author :  Evan Nichols
*	@date : 2015.2.5
*	Purpose: Header file of LinkedList Class. 
*/

#include <iostream>
#include "Node.h"

#ifndef _LinkedList
#define _LinkedList




class LinkedList {

public:

/**
*  @pre None
*  @post Creates and initializes a LinkedList instance
*  @return m_front to nullptr and m_size set to 0
*/
LinkedList();

/**
*  @pre None
*  @post None
*  @return deletes all nodes in the list.
*/
~LinkedList();

/**
*  @pre None
*  @post None
*  @return returns true if the list is empty, false otherwise
*/
bool isEmpty() const;

/**
*  @pre None
*  @post None
*  @return returns the number of elements in the list
*/
int size() const;

/**
*  @pre value must be of type int
*  @post none
*  @return returns true if the value is in the list, false otherwise
*/
bool search (int value) const;

/**
*  @pre must be called on a valid LinkedList object
*  @post none
*  @return prints the list to the console, "List empty" if it is empty
*/
void printList() const;

/**
*  @pre value must be of type int
*  @post one new element with m_value set to value is added to the end of the list
*  @return none
*/
void addBack(int value);

/**
*  @pre value must be of type int
*  @post one new element with m_value set to value is added to the front of the list
*  @return none
*/
void addFront(int value);

/**
*  @pre none
*  @post one element is removed from the back of the list
*  @return true if the back element was removed, false if the list is empty.
*/
void removeBack();

/**
*  @pre none
*  @post one element is removed from the front of the list
*  @return true if the back element was removed, false if the list is empty.
*/
void removeFront();

private:

Node* m_front;
int m_size;

};

#endif
