/**
*	@file : Node.h
*	@author :  Evan Nichols
*	@date : 2015.2.5
*	Purpose: Header file of Node Class. 
*/

#include <iostream>
#ifndef _NODE
#define _NODE

class Node {

public:

/**
*  @pre None
*  @post Creates and initializes a Node instance
*  @return m_value set to 0 and m_next set to nullptr
*/
Node(); 

/**
*  @pre value must be of type int
*  @post sets a Node's m_value to val
*  @return none (setter)
*/
void setValue(int val);

/**
*  @pre must refer to a valid Node
*  @post none
*  @return a node's m_value
*/
int getValue();

/**
*  @pre value must be of type pointer
*  @post sets a Node's m_next pointer
*  @return none (setter)
*/
void setNext(Node* prev);

/**
*  @pre must not be a nullptr!
*  @post none
*  @return returns a pointer to the next Node in the list
*/
Node* getNext();

private:

int m_value;
Node* m_next;

};

//#include "Node.cpp"
#endif






