/**
*	@file : DoubleLinkedList.h
*	@author :  Evan Nichols
*	@date : 2015.2.24
*	Purpose: Header file of DoubleLinkedList Class. 
*/

#include <iostream>
#include "Node.h"

#ifndef _DoubleLinkedList
#define _DoubleLinkedList



template <typename T>
class DoubleLinkedList {

public:

/**
*  @pre None
*  @post Creates and initializes a DoubleLinkedList instance
*  @return m_front, m_back to nullptr and m_size set to 0
*/
DoubleLinkedList();

/**
*  @pre None
*  @post None
*  @return deletes all nodes in the list and sets all pointers to null.
*/
~DoubleLinkedList();

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
*  @return returns a pointer to the node which contains the value T. If it fails to find a value, it will return a nullptr.
*/
Node<T>* find (T value) const;

/**
*  @pre must be called on a valid LinkedList object
*  @post none
*  @return prints the list to the console, "List empty" if it is empty
*/
void printList() const;

/**
*  @pre value must be of type int
*  @post one new node with value newVal is added to the list BEHIND the node which contains value listVal. 
*  @return none
*/
void insertBehind(T listVal, T newVal) throw(std::runtime_error);

/**
*  @pre value must be of type int
*  @post one new node with value newVal is added to the list AHEAD of the node which contains value listVal. 
*  @return none
*/
void insertAhead(T listVal, T newVal) throw(std::runtime_error);


/**
*  @pre value must be of type int
*  @post adds a new node to the list containing value to the back of the list.
*  @return none
*/
void pushBack(T value);

/**
*  @pre value must be of type int
*  @post adds a new node to the list containing value to the front of the list. 
*  @return none
*/
void pushFront(T value);

/**
*  @pre none
*  @post the node containing value will be deleted from the list. 
*  @return none
*/
bool remove(T value);

private:

Node<T>* m_front;
Node<T>* m_back;
int m_size;

};

#include "DoubleLinkedList.hpp"
#endif
