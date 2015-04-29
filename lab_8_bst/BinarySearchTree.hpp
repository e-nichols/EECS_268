/**
*	@file : BinarySearchTree.h
*	@author : Evan Nichols
*	@date : 2015.4.10
*	Purpose: Implementation File for the BinarySearchTree class, which inherits from BSTI
*/


template <typename T>
BinarySearchTree<T>::BinarySearchTree(){

	m_root = nullptr;

}
  
template <typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& other){

	//Create a Deep copy, this method will be called through the BSTI clone method
	std::cout <<"Cloning the Original...\n";

	m_root = new Node<T>(*(other.m_root));

}

template <typename T>
BSTI<T>* BinarySearchTree<T>::clone(){

	BSTI<T>* myClone = new BinarySearchTree<T>(*(this));

	return myClone;

}
  
template <typename T>
BinarySearchTree<T>::~BinarySearchTree(){

	deleteTree(m_root);

}

template <typename T>
void BinarySearchTree<T>::deleteTree(Node<T>* ptr){

	if(ptr != nullptr) 
	{
		if(ptr->getLeft() != nullptr)
		{
			deleteTree(ptr->getLeft());
		}

		if(ptr->getRight() != nullptr) 
		{
			deleteTree(ptr->getRight());
		}

		//std::cout << "Deleting the node with value " << ptr->getValue() << "\n"; 
		delete ptr;
	}
}

template <typename T>
bool BinarySearchTree<T>::isEmpty() const {

	//check to see if m_root is point at anything
	if (m_root == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}

}

template <typename T>    
bool BinarySearchTree<T>::add(T value){

	//calls on private method, which handles recursive traversal of tree
	if(addPrivate(value, this -> m_root))
	{
		return true;
	}
	else 
	{
		return false;
	}
		
}

template <typename T>    
bool BinarySearchTree<T>::addPrivate(T value, Node<T>* ptr){

	if(isEmpty() == true) 
	{
		Node<T>* newNode = new Node<T>();
		newNode -> setValue(value);
		m_root = newNode;

		return true;
		std::cout << "Value successfully added.\n";
	}
	//value is SMALLER than root Val, thus going down left branch
	else if(value < ptr->getValue())
	{

		//check if there are any elements connected to m_roots left pointer
		if(ptr -> getLeft() == nullptr)
		{
			Node<T>* node = new Node<T>();
			node->setValue(value);
			ptr->setLeft(node);
			
			return true;
			std::cout << "Value successfully added.\n";
		}
		//else, continue the traverse down the left pointer recursively
		return addPrivate(value, ptr->getLeft());	
	}
	//value is LARGER than root Val, thus going down left branch
	else if(value > ptr->getValue())
	{

		//check if there are any elements connected to m_roots left pointer
		if(ptr -> getRight() == nullptr)
		{
			Node<T>* node = new Node<int>();
			node->setValue(value);
			ptr->setRight(node);
			return true;
			std::cout << "Value successfully added.\n";	
		}
		//continue the traverse down the right pointer recursively
		return addPrivate(value, ptr->getRight());
			
	}
	else
	{
		std::cout << "This value already exists within the tree.\n";
		return false;
	}
}


template <typename T>
void BinarySearchTree<T>::printTree(ORDER order) const {

	printTreePrivate(order, m_root);

	}
        
template <typename T>
void BinarySearchTree<T>::printTreePrivate(ORDER order, Node<T>* ptr) const{

		if(order == PRE_ORDER) 
		{
			if(ptr != nullptr) {

				std::cout << ptr -> getValue() << " ";
				printTreePrivate(order, ptr -> getLeft());
				printTreePrivate(order, ptr -> getRight());
			}
			else {
				return;
			}
		}
		
		else if(order == IN_ORDER) 
		{
			if(ptr != nullptr) 
			{
				printTreePrivate(order, ptr -> getLeft());
				std::cout << ptr -> getValue() << " ";
				printTreePrivate(order, ptr -> getRight());
			}
			else {
				return;
			}
		}

		else if(order == POST_ORDER) 
		{
			if(ptr != nullptr) 
			{
				printTreePrivate(order, ptr -> getLeft());
				printTreePrivate(order, ptr -> getRight());
				std::cout << ptr -> getValue() << " ";
			}
			else 
			{
				return;
			}
		}
	}//end prints

template <typename T>
void BinarySearchTree<T>::sortedPrint() const {

	std::cout <<"Sorted Print Beginning...\n";

	printTreePrivate(IN_ORDER, m_root);

}

template <typename T>
T BinarySearchTree<T>::search(T value) const throw (ValueNotFoundException){

	return searchPrivate(value, m_root);

}

template <typename T>
T BinarySearchTree<T>::searchPrivate(T value, Node<T>* subtree) const throw (ValueNotFoundException){

	if(subtree != nullptr) 
	{
		if(value == subtree -> getValue()) 
		{
			return (subtree->getValue());
		}

		else if(value < (subtree -> getValue()))
		{
			if((subtree -> getLeft()) != nullptr) 
			{
				//std::cout << "recursive search left\n";
				//recursively search for possible matches
				searchPrivate(value,subtree -> getLeft());	
			}
			else
			{
				throw(ValueNotFoundException("Value is not in tree.\n"));
			}
		}

		else if (value > (subtree -> getValue())) 
		{
			if(subtree -> getRight() != nullptr) 
			{
				//std::cout << "recursive search right\n";
				//recursively search for possible matches
				searchPrivate(value, subtree -> getRight());
			}
			else
			{
				throw(ValueNotFoundException("Value is not in tree.\n"));
			}
		}
	}
}


	/*
    check, whether value in current node and searched value are equal. If so, value is found. Otherwise,
    if searched value is less, than the node's value:
        if current node has no left child, searched value doesn't exist in the BST;
        otherwise, handle the left child with the same algorithm.
    if a new value is greater, than the node's value:
        if current node has no right child, searched value doesn't exist in the BST;
        otherwise, handle the right child with the same algorithm.
    */
