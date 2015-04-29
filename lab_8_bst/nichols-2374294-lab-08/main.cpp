/**
*	@file : Main.cpp
*	@author : Evan Nichols
*	@date : 2015.3.25
*	Purpose: Main.cpp allows users to interact with the Binary Search Tree and run various operations on it.
*/

//Things to Fix
//Trying to Print Empty Tree Segfaults
//Ordered Prints aren't working

#include "BSTI.h"
#include "BinarySearchTree.h"

#include <iostream>
#include <cstdlib>
#include <string>
#include <functional>
#include <fstream>
#include <random>


//print menu helper method
void printMenu(){

std::cout << "Input a selection.\n\n"
<< "1) Add more values to original tree \n"
<< "2) Copy the original tree \n"
<< "3) Delete the original tree (one time only) \n"
<< "4) Print original tree \n"
<< "5) Print copy \n"
<< "6) Search original tree \n"
<< "7) Search copy \n"
<< "8) Exit \n"
<< "\nYour choice:";
} 

int main(int argc, char** argv) {

	std::cout << "\nWelcome to Binary Tree Search Program.\n\n";

	//Instantiate new BinarySearch Tree
	BSTI<int>* myBST = new BinarySearchTree<int>();
	BSTI<int>* myCopy = nullptr;

	int user_choice;
	int value;
	int randomNumber;

	if(argc == 2) {

		int tree_size = atoi(argv[1]);

		if(tree_size < 0) {
			std::cout << "Cannot make tree of negative size.\n";
		}

		else {

			//Code to Create a BST of size tree_size
			std::cout << "Node Count: " << tree_size << ". \n";
			std::cout << "Adding " << tree_size << " values to the tree.\n";

			//intialize the random engine, create a uniform distribution of numbers between min and max
			std::default_random_engine generator(time(nullptr));
			std::uniform_int_distribution<int> distribution(-32000, 32000);

			for (int i=0; i<tree_size; i++)
			{
				//create a random number and populate BST with it
				randomNumber = distribution(generator);
				myBST -> add(randomNumber);
			}

			std::cout << "BST of size " << tree_size << " created succesfully.\n";

			printMenu();

			std::cin >> user_choice;	
		}	
	}

	else if(argc > 2) {

		std::cout << "Invalid Number of Arguments. Program Terminating.\n";
		user_choice = 8;
	}

	//Begin Main Program Loop - Let user interact with tree.
	while(user_choice != 8) {

		printMenu();
		std::cin >> user_choice;

		if(user_choice == 1) 
		{
			//add values to original

			if(myBST == nullptr){
				std::cout << "Tree does not exist -- can't add value.\n";
			}

			else {

			std::cout << "Input Value to add to Tree: ";

			std::cin >> value;

			std::cout << "\n";

			myBST -> add(value);

			std::cout << value << " successfully added.\n";
			}
		}

		else if(user_choice == 2) 
		{
			myCopy = myBST -> clone();

			std::cout << "Copy successful.\n";
		}

		else if(user_choice == 3) 
		{
			//Delete Original Tree (One Time Only)
			delete myBST;
			myBST = nullptr;
			std::cout << "Original Deleted.\n";
		}

		else if(user_choice == 4) 
		{ 
			//Print Original Tree

			if(myBST == nullptr || myBST -> isEmpty())
			{
				std::cout << "Tree is Empty -- nothing to print.\n";
			}

			else 
			{

			int print_type;

			std::cout << "\nIn what order shall we print the tree? \n"
					<<"1) Pre Order \n"
					<<"2) In Order \n"
					<<"3) Post Order \n"
					<<"\nYour Choice: ";

			std::cin >> print_type;

			std::cout << "\n";

			if(print_type == 1) {

				//Pre Order Print Code
				std::cout << "Printing in Pre Order...\n\n";
				myBST -> printTree(PRE_ORDER);
				std::cout << "\n";

			}

			else if(print_type == 2) {

				//In Order Print Code
				std::cout << "Printing In Order...\n\n";
				myBST -> printTree(IN_ORDER);
				std::cout << "\n";
			}

			else if(print_type == 3) {

				//Post Order Print Code
				std::cout << "Printing in Post Order...\n\n";
				myBST -> printTree(POST_ORDER);
				std::cout << "\n";
			}
		}
	}

		else if(user_choice == 5) {

			//Print Copy Tree

			if(myCopy == nullptr || myCopy -> isEmpty())
			{
				std::cout << "Tree is Empty -- nothing to print.\n";
			}

			else 
			{

			int print_type;

			std::cout << "\nIn what order shall we print the tree? \n"
					<<"1) Pre Order \n"
					<<"2) In Order \n"
					<<"3) Post Order \n"
					<<"\nYour Choice: ";

			std::cin >> print_type;

			std::cout << "\n";

			if(print_type == 1) 
			{
				//Pre Order Print Code
				std::cout << "Printing in Pre Order...\n\n";
				myCopy -> printTree(PRE_ORDER);
				std::cout << "\n";

			}

			else if(print_type == 2) 
			{
				//In Order Print Code
				std::cout << "Printing In Order...\n\n";
				myCopy -> printTree(IN_ORDER);
				std::cout << "\n";
			}

			else if(print_type == 3) 
			{
				//Post Order Print Code
				std::cout << "Printing in Post Order...\n\n";
				myCopy -> printTree(POST_ORDER);
				std::cout << "\n";
			}
		}
	}

		else if(user_choice == 6) {

			//Search Original
			int search_val;

			std::cout << "Enter Value to Search for: ";

			std::cin >> search_val;

			std::cout << "Searching for " << search_val << " in the original tree...\n\n";
			
			try 
			{
				int foundVal = myBST -> search(search_val);
				std::cout << "success! " << search_val << " is in the tree.\n";
			}
			catch (ValueNotFoundException e)
			{
				std::cout << e.what();
			}

			

		}

		else if(user_choice == 7) {

			//Search Copy
			int search_val;

			std::cout << "Enter Value to Search for: ";

			std::cin >> search_val;

			std::cout << "Searching for " << search_val << " in the copied tree...\n\n";

			try 
			{
				int foundVal = myCopy -> search(search_val);
				std::cout << "success! " << search_val << " is in the tree.\n";
			}
			catch (ValueNotFoundException e)
			{
				std::cout << e.what();
			}
			
		}

//Print Menu Again, gather next input
		//printMenu();
		//std::cin >> user_choice;


	}//end while

std::cout << "Exiting Program... Goodbye\n\n";

delete myBST;
delete myCopy;

return 0;

};

