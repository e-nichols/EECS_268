/**
*	@file : Node.h
*	@author : Evan Nichols
*	@date : 2015.2.5
*	Purpose: Implementation of the Node Class. 
*/

#include <iostream>
#include <string>
#include <stdexcept>
#include "Node.h"

//CONSTRUCTOR
template <typename T>
Node<T>::Node(){

m_value = T();
m_next = nullptr;
m_previous = nullptr;

}

//SET VALUE
template <typename T>
void Node<T>::setValue(T val) 
{m_value = val;}

//GET VALUE
template <typename T>
T Node<T>:: getValue() 
{return(m_value);}

//SET NEXT NODE POINTER
template <typename T>
void Node<T>::setNext(Node<T>* next) 
{ m_next = next;}

//GET NODE POINTER
template <typename T>
Node<T>* Node<T>::getNext() 
{ return(m_next);}

//SET PREV NODE POINTER
template <typename T>
void Node<T>::setPrev(Node<T>* prev)
{ m_previous = prev; }

//GET PREV NODE POINTER
template <typename T>
Node<T>* Node<T>::getPrev()
 {return(m_previous);}
