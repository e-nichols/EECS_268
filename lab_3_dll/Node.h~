/**
*	@file : Node.h
*	@author :  Evan Nichols
*	@date : 2015.2.24
*	Purpose: Header file of Node Class. 
*/

#include <iostream>
#ifndef _NODE
#define _NODE

template <typename T>
class Node {

public:

/**
*  @pre None
*  @post Creates and initializes a Node instance
*  @return m_value set to T() and m_next and m_previous set to nullptr
*/
Node(); 

/**
*  @pre value must be of type int
*  @post sets a Node's m_value to val
*  @return none (setter)
*/
void setValue(T val);

/**
*  @pre must refer to a valid Node
*  @post none
*  @return a node's m_value
*/
T getValue();

/**
*  @pre value must be of type pointer
*  @post sets a Node's m_next pointer
*  @return none (setter)
*/
void setNext(Node<T>* next);

/**
*  @pre must not be a nullptr!
*  @post none
*  @return returns a pointer to the next Node in the list
*/
Node<T>* getNext();

/**
*  @pre value must be of type pointer
*  @post sets a Node's m_next pointer
*  @return none (setter)
*/
void setPrev(Node<T>* prev);

/**
*  @pre must not be a nullptr!
*  @post none
*  @return returns a pointer to the previous (or behind) Node in the list
*/
Node<T>* getPrev();

private:

T m_value;
Node<T>* m_next;
Node<T>* m_previous;

};

#include "Node.hpp"
#endif






