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
*  @post sets a Node's m_above pointer
*  @return none (setter)
*/
void setBelow(Node<T>* below);

/**
*  @pre must not be a nullptr!
*  @post none
*  @return returns a pointer to the above Node in the list
*/
Node<T>* getBelow();

private:

T m_value;
Node<T>* m_below;

};

#include "Node.hpp"
#endif






