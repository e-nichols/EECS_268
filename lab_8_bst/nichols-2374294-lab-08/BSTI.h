/**
*	@file : BSTI.h
*	@author : Evan Nichols
*	@date : 2015.4.10
*	Purpose: Binary Search Tree Interface
*/

//This is an interface for a Binary Search Tree.

#ifndef _BSTI
#define _BSTI

#include "ValueNotFoundException.h"

//Above the BSTI class, we'll need an enumerated type
enum ORDER {PRE_ORDER, IN_ORDER, POST_ORDER};

template <typename T>
class BSTI {

public:

/**
*  @pre A BSTI exists
*  @post Deletes the entire tree.
*  @return none (destructor)
*/
    virtual ~BSTI(){};

/**
*  @pre This is in a valid state
*  @post Creates a deep copy of this
*  @return a pointer to a deep copy of this
*/
    virtual BSTI* clone() = 0;

/**
*  @pre None
*  @post Sets m_left and m_right to nullptr (leaves m_value alone bc this is templated class)
*  @return true if no nodes in the tree, otherwise returns false.
*/
    virtual bool isEmpty() const = 0;

/**
*  @pre value is a valid T
*  @post a new Node<T> is created and inserted into the tree based
*  @return false if the value could not be added (duplcates are NOT allowed)
*/
    virtual bool add(T value) = 0;

/**
*  @pre the type T is comparable by the == operator
*  @post None
*  @return value is returned if it is in the tree, otherwise, an exception is thrown. 
*/
    virtual T search(T value) const throw (ValueNotFoundException) = 0;

/**
*  @pre none
*  @post the contents of the tree are printed to the console in the specified order
*  @return none 
*/
    virtual void printTree(ORDER order) const = 0;


/**
*  @pre none
*  @post the contents of the tree are printed to the console in order
*  @return none 
*/
virtual void sortedPrint() const = 0; 

}; 

#endif