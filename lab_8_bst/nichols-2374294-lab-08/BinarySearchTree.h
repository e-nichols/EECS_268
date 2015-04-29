/**
*	@file : BinarySearchTree.h
*	@author : Evan Nichols
*	@date : 2015.4.10
*	Purpose: Header File for the BinarySearchTree class, which inherits from BSTI
*/


#include <stdexcept>
#include <iostream>

#include "Node.h"
#include "BSTI.h"
#include "ValueNotFoundException.h"

#ifndef _BINARYSEARCHTREE
#define _BINARYSEARCHTREE

template <typename T>
class BinarySearchTree: public BSTI<T> {

private:

//Pointer always looking at root of the tree.
	Node<T>* m_root;

/**
*  @pre value must not already exist in the tree 
*  @post Adds a new node to tree in appropriate spot
*  @return bool, true if value successfully added, false otherwise
*/
    bool addPrivate(T value, Node<T>* ptr);

/**
*  @pre must be called on valid Node<T>* 
*  @post deletes tree, used in Destructor
*  @return note: none
*/
    void deleteTree(Node<T>* subTree);

/**
*  @pre called within PrintTree function
*  @post none
*  @return note: none
*/
    void printTreePrivate(ORDER order, Node<T>* ptr) const;

/**
*  @pre called within public search function
*  @post recurisvely searches tree for value
*  @return returns value if able to find, else throws exception.
*/
    T searchPrivate(T value, Node<T>* subtree) const throw(ValueNotFoundException);

public:

/**
*  @pre none
*  @post sets m_root to nullptr
*  @return BinarySearchTree of type T
*/
    BinarySearchTree();
        
/**
*  @pre Copy Constructor
*  @post creates a deep fopy of the other BST.
*  @return note: this method calls the clone() method.
*/
    BinarySearchTree(const BinarySearchTree<T>& other);
       
/**
*  @pre Destructor
*  @post calls private method, deleteTree(Node<T>* subTree) and passes in m_root as the starting point for deletion
*  @return none
*/
    ~BinarySearchTree();
       
/**
*  @pre none
*  @post creates a deep copy of this
*  @returns a pointer to a deep copy of this
*/
    BSTI<T>* clone();

/**
*  @pre none
*  @post none
*  @return true if no nodes in the tree, otherwise returns false.
*/
    bool isEmpty() const;

/**
*  @pre none
*  @post sets m_root to nullptr
*  @return BinarySearchTree of type T
*/
    bool add(T value);
        
/**
*  @pre Order must be of type Order, the enumerate type declared in BSTI.h
*  @post prints the tree in the specified order, else displays Tree Empty
*  @return
*/    
	void printTree(ORDER order) const;

/**
*  @pre none
*  @post the contents of the tree are printed to the consoloe in in-order
*  @return none
*/
    void sortedPrint() const;

/**
*  @pre none
*  @post throws ValueNotFoundException if the value is not in the tree
*  @return returns the result from search(T value, Node<T>* subtree)
*/

    T search(T value) const throw (ValueNotFoundException);

};

#include "BinarySearchTree.hpp"

#endif