/**
*	@file : Node.h
*	@author : Evan Nichols
*	@date : 2015.2.5
*	Purpose: Implementation of the Node Class. 
*/

#include "Node.h"

//Constructor
template <typename T>
Node<T>::Node(){

	m_left = nullptr;
	m_right = nullptr;
}

//Copy Constructor
template <typename T>
Node<T>::Node(const Node<T>& other){

//create deep copy
	
	m_value = other.m_value;
	m_left = other.m_left;
	m_right = other.m_right;

	//recursively copy the entire tree, checking for nullptr

	if(other.m_left != nullptr) 
	{
		m_left = new Node<T>(*(other.m_left));
	}

	if(other.m_right != nullptr) 
	{
		m_right = new Node<T>(*(other.m_right));
	}

}

//Get and Set Methods for Value
	template <typename T>
	void Node<T>::setValue(T val) {m_value = val;}

	template <typename T>
	T Node<T>:: getValue() {return m_value;}

//Get and Set Methods for m_left
	template <typename T>
	void Node<T>::setLeft(Node<T>* left)
	{ m_left = left; }

	template <typename T>
	Node<T>* Node<T>::getLeft(){return m_left;}

//Get and Set Methods for m_left
	template <typename T>
	void Node<T>::setRight(Node<T>* right){m_right = right;}

	template <typename T>
	Node<T>* Node<T>::getRight(){return m_right;}


