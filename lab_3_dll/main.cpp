/**
*	@file : Main.cpp
*	@author : Evan Nichols
*	@date : 2015.2.24
*	Purpose: Main.cpp is a driver for the DoubleLinkedList and Node classes, giving users a set of options to interact with a DoubleLinkedList. 
*/

#include <iostream>
#include <string>
#include <stdexcept>
#include "DoubleLinkedList.h"
#include "Node.h"
#include "Stack.h"


//printMenu helper method
void printMenu() {

std::cout << "Make Choice:\n"
		<< "1) Push Value onto Front\n"
		<< "2) Push Value onto Back\n"
		<< "3) Insert Behind a Value\n"
		<< "4) Insert Ahead of a Value\n"
		<< "5) Remove Value\n"
		<< "6) Print List\n"
		<< "7) Quit\n"
		<< "Enter your choice: ";
};

//MAIN METHOD
int main () {

DoubleLinkedList<int> myLink;

//declare and instantiate new DoubleLinkedList object
myLink = DoubleLinkedList<int>(); 

int choice = 0;

int user_value;

int list_value;

	while(choice != 7) {
	
printMenu();
std::cin >> choice;
std::cout << " You chose: " << choice << "\n";

		if(choice == 1) {

			std::cout << "Input a value to add: ";
			std::cin >> user_value;
			std::cout << "Pushing " << user_value << " onto the front of the list \n \n";

			myLink.pushFront(user_value);

		}

//same goes for list value variable
		else if (choice == 2) {

			std::cout << "Input a value to add: ";
			std::cin >> user_value;
			std::cout << "Pushing " << user_value << " onto the back of the list \n \n";

			myLink.pushBack(user_value);

		}

		else if (choice == 3) {

			std::cout << "Give a value to insert: ";
			std::cin >> user_value;

			std::cout << "Pick a value to insert behind: ";
			std::cin >> list_value;

			std::cout << "Attempting to insert " << user_value << " behind " << list_value << "\n \n";

			try {

			myLink.insertBehind(list_value, user_value);

			std::cout << user_value << "inserted behind " << list_value << " \n \n";

			}

			catch (const std::runtime_error& e) {
			
				std::cout << e.what() << std::endl;
			}

		}

		else if (choice == 4) {

			std::cout << "Give a value to insert: ";
			std::cin >> user_value;

			std::cout << "Pick a value to insert ahead of: ";
			std::cin >> list_value;

			std::cout << "Attempting to insert " << user_value << " ahead of " << list_value << "\n \n";

			try {

			myLink.insertAhead(list_value, user_value);

			std::cout << user_value << "inserted ahead of " << list_value << " \n \n";

			}

			catch (const std::runtime_error& e) {
			
				std::cout << e.what() << std::endl;
			}

		}

		else if (choice == 5) { //remove value

			std::cout << "Give a value to remove ";
			std::cin >> user_value;

			bool wasItRemoved = myLink.remove(user_value);

			if(wasItRemoved == true) {
				std::cout << user_value << " removed from the list. \n \n";
			}

			else {
				std::cout << user_value << " could not be removed from the list. \n \n";
		}
}//end choice 5

		else if (choice == 6) { //print list
		
			myLink.printList();
			std::cout << "\n \n";
	
		}
		else if (choice == 7) {
			std::cout << "Exiting....\n";
		}
	
	}//end while

return(0);
}//end main
