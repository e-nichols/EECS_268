/**
*	@file : Stack.h
*	@author :  Evan Nichols
*	@date : 2015.3.03
*	Purpose: Header file of Stack Class, extension of StackInterface 
*/

#include <iostream>
#include "StackInterface.h"
#include "PreconditionViolationException.h"
#include "Node.h"

#ifndef _Stack
#define _Stack

template <typename T>
class Stack: public StackInterface<T> {

public:

/**
*  @pre None
*  @post None
*  @return Creates a new Stack object
*/
Stack();

/**
*  @pre None
*  @post None
*  @return destructor method
*/
~Stack();

/**
*  @pre None
*  @post pushes a new node onto the top of the stack
*  @return None
*/
void push(const T newEntry);

/**
*  @pre None
*  @post checks if stack is Empty by checking m_size
*  @return boolean, true if empty
*/
bool isEmpty() const;

/**
*  @pre must not be an empty stack for pop to work
*  @post removes the top node from the stack
*  @return the value of the node that was removed from the stack.
*/
T pop() throw(PreconditionViolationException);

/**
*  @pre must not be an empty stack for peek to work
*  @post none
*  @return the value of the node that is at the top of the stack
*/
T peek() const throw(PreconditionViolationException);

/**
*  @pre None
*  @post None
*  @return integer indicating the current size of the stack.
*/
int size() const;

/**
*  @pre None
*  @post None
*  @return prints the stack values to the console.
*/
void print() const;

/**
*  @pre Need to reference another valid Stack object
*  @post None
*  @return True if the stack's size is less than the rhs's size
*/
bool operator< (const StackInterface<T>& rhs) const;

/**
*  @pre Need to reference another valid Stack object to compare to.
*  @post None
*  @return True if the this stack's size is less than or equal to the rhs's size
*/	
bool operator<= (const StackInterface<T>& rhs) const;
        
/**
*  @pre Need to reference another valid Stack object to compare to.
*  @post None
*  @return True if the this stack's size is greater than the rhs's size
*/
bool operator> (const StackInterface<T>& rhs) const;
        
/**
*  @pre Need to reference another valid Stack object to compare to.
*  @post None
*  @return True if this stack's size is greater than or equal to the size of the rhs
*/
bool operator>= (const StackInterface<T>& rhs) const;

/**
*  @pre Need to reference another valid Stack object to compare to.
*  @post None
*  @return True if the sizes of stacks are equal
*/
bool operator== (const StackInterface<T>& rhs) const;
        
/**
*  @pre Need to reference another valid Stack object to compare to.
*  @post None
*  @return True if the sizes of stacks are not equal
*/
bool operator!= (const StackInterface<T>& rhs) const;

private:

int m_size;
Node<T>* m_top;

};

#include "Stack.hpp"
#endif


