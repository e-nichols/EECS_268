/**
*	@file : Main.cpp
*	@author : Evan Nichols
*	@date : 2015.3.3
*	Purpose: Main.cpp is a driver Stack class, allowing comparison and interaction with 2 stacks 
*/

#include <iostream>
#include <string>
#include <stdexcept>
#include "Stack.h"
#include "Node.h"
#include "PreconditionViolationException.h"


//compare Stacks method (from Wiki)
template <typename T>
void compareStacks(const StackInterface<T>& s1, const StackInterface<T>& s2)
{
	std::cout 	<< "\nComparison of stacks:\n"
			<< "lane 1 < lane 2: " <<  (s1 <  s2) 	<< " \n"
			<< "lane 1 > lane 2: " <<  (s1 >  s2) 	<< " \n"
			<< "lane 1 >= lane 2: " << (s1 >= s2) 	<< " \n"
			<< "lane 1 <= lane 2: " << (s1 <= s2) 	<< " \n"
			<< "lane 1 == lane 2: " << (s1 == s2) 	<< " \n"
			<< "lane 1 != lane 2: " << (s1 != s2) 	<< " \n";
}

//printMenu helper method
void printMenu() {

std::cout << "Select an Action:\n"
		<< "1) Add Something to Stack 1\n"
		<< "2) Add Something to Stack 2\n"
		<< "3) See what is at the top of Stack 1\n"
		<< "4) See what is at the top of Stack 2\n"
		<< "5) Print Contents of Stack 1\n"
		<< "6) Print Contents of Stack 2\n"
		<< "7) Remove Something from Stack 1\n"
		<< "8) Remove Something from Stack 2\n"
		<< "9) Compare Stacks \n"
		<< "10) Quit \n"
		<< "Enter your Choice: \n";
};

//MAIN METHOD
int main () {

//declare and instantiate two Stack objects


StackInterface<std::string>* lane1 = new Stack<std::string>();
StackInterface<std::string>* lane2 = new Stack<std::string>();

int choice = 0;

std::string user_value;

	while(choice != 10) {
	
printMenu();
std::cin >> choice;
std::cout << " You chose: " << choice << "\n";

		if(choice == 1) { //Add Something to Stack 1

			std::cout << "What is going in Stack 1?: \n";
			std::cin >> user_value;
			lane1 -> push(user_value);
			std::cout<< user_value << " successfully added to Stack 1. \n";

		}

		else if (choice == 2) { //Add Something to Stack 2

			std::cout << "What is going in Stack 2?: \n";
			std::cin >> user_value;
			lane2 -> push(user_value);
			std::cout<< user_value << " successfully added to Stack 2. \n";

		}

		else if (choice == 3) { //Peek Stack 1

			std::cout << "Attempting to see what is at the top of Stack 1...\n";

			try {

			std::cout << lane1 -> peek()<<"\n";

			}

			catch (const std::runtime_error& e) {

			//does it need to be exception here, or runtime error?
			
				std::cout << e.what() << std::endl;
			}

		}

		else if (choice == 4) { //Peek Stack 2

			std::cout << "Attempting to see what is at the top of Stack 2...\n";

			try {
				std::cout << lane2 -> peek() << "\n";
			}

			catch (const std::runtime_error& e) {
				std::cout << e.what() << std::endl;
			}
		}

		else if (choice == 5) { //Print All Stack 1

			lane1 -> print();
		}

		else if (choice == 6) { //Print All Stack 2
		
			lane2 -> print();
		}

		else if (choice == 7) { //Pop Stack 1

			try {
				std::string removedItem = lane1 -> pop();
				std::cout << removedItem << " removed from Stack 1. \n";
			}

			catch (const std::runtime_error& e) {
				std::cout << e.what() << std::endl;
			}
		}

		else if (choice == 8) { //Pop Stack 2

			try {
				std::string removedItem = lane2 -> pop();
				std::cout << removedItem << " removed from Stack 1. \n";
			}

			catch (const std::runtime_error& e) {
				std::cout << e.what() << std::endl;
			}
		}

		else if (choice == 9) { //Compare Stacks
			//run the compare stacks function from wiki
			compareStacks(*(lane1), *(lane2));
			std::cout<< "\n";
	
		}

		else if (choice == 10) {

			//terminate the program.
			std::cout << "Program Ending....\n";
		}
	
	}//end while

delete lane1;
delete lane2;

return(0);
}//end main
