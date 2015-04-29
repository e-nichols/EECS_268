/**
*	@file : Node.h
*	@author :  Evan Nichols
*	@date : 2015.4.10
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
*  @post Sets m_left and m_right to nullptr (leaves m_value alone bc this is templated class)
*  @return an instance of Node 
*/
Node();

/**
*  @pre None
*  @post creates deep copy of other node (meaning it creates copies of any nodes being pointed to by other)
*  @return an instance of Node 
*/
Node(const Node<T>& other); 

//Get and Set Methods for: m_value, m_left and m_right
void setValue(T val);
void setLeft(Node<T>* left);
void setRight(Node<T>* right);

T getValue();
Node<T>* getLeft();
Node<T>* getRight();

private:

//points to the left subtree
    Node<T>* m_left;
//points to the right subtree
    Node<T>* m_right;
//value stored in the node
    T m_value;
};

#include "Node.hpp"
#endif






