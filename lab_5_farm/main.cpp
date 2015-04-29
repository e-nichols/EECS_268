/**
*	@file : Main.cpp
*	@author : Evan Nichols
*	@date : 2015.3.4
*	Purpose: Main.cpp allows users to interact with FarmAnimals and FarmAnimal Pen
*/

#include <iostream>
#include <string>
#include <stdexcept>
#include "Stack.h"
#include "Node.h"
#include "PreconditionViolationException.h"
#include "AnimalPen.h"
#include "FarmAnimal.h"
#include "CyberChicken.h"
#include "Chicken.h"
#include "Cow.h"


void goodbyeMessage(const FarmAnimal& animal) {

	std::cout << "Upon release the " << animal.getName() << " said " << animal.getSound() << "\n";
}

void printMenu() {

std::cout 	<< "1.) Cow (produces milk) \n"
			<< "2.) Chicken (cannot lay eggs) \n"
			<< "3.) Cyber Chicken (seems dangerous, but lays eggs) \n";
}

//MAIN METHOD
int main () {

std::cout << "Welcome to the Farm. \n";

//Declare and Instantiate FarmAnimal Pen
AnimalPen* myPen = new AnimalPen();

//Declare variables for user input 
std::string user_choice = "n";

int animal_choice = 0;
double gallons = 0;
int eggs = 0;

double total_gallons = 0;
int total_eggs = 0;

while(user_choice == "n" || user_choice == "N") {
	
printMenu();
std::cin >> animal_choice;
std::cout << "Choice: " << animal_choice << "\n";

		if(animal_choice == 1) { //Cow selected

			FarmAnimal* newCow = new Cow();

                std::cout << "How many gallons of milk did this cow produce? \n";

                std::cin >> gallons;

			Cow* tempCow = static_cast<Cow*>(newCow);

			tempCow -> setMilkProduced(gallons);

				try{

                    myPen -> addAnimal(newCow);
					total_gallons = total_gallons + gallons;

				}
				catch (const std::runtime_error& e) {
					std::cout << e.what() << std::endl;
				}
		}

		else if (animal_choice == 2) { //Chicken selected

			FarmAnimal* newChicken = new Chicken();

                std::cout << "Add an eggless chicken to the pen? OK. You're the boss. \n";

				try{

                    myPen -> addAnimal(newChicken);

				}
				catch (const std::runtime_error& e) {
					std::cout << e.what() << std::endl;
				}

		}

		else if (animal_choice == 3) { //Cyber Chicken selected

			FarmAnimal* newCyber = new CyberChicken();

                std::cout << "How many eggs did this cyber chicken produce? \n";

                std::cin >> eggs;

			CyberChicken* tempCyber = static_cast<CyberChicken*>(newCyber);

			tempCyber->setCyberEggs(eggs);


			try {

                myPen -> addAnimal(newCyber);
				total_eggs = total_eggs + eggs;

			}

			catch (const std::runtime_error& e) {
				std::cout << e.what() << std::endl;
			}

            //delete newCyber;

		}

		//Done adding FarmAnimals
		std::cout << "Done adding Animals? y/n: ";
		std::cin >> user_choice;
	
	}//end while

	std::cout << "\n \n Releasing All FarmAnimals! \n";
	std::cout << "-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-\n";

	while(!(myPen -> isPenEmpty())){

		FarmAnimal* next = myPen -> peekAtNextAnimal();
		std::string name = next -> getName();

		if(name == "Cow") {

			Cow* tempCow = static_cast<Cow*>(next);

                std::cout << "This cow produced " << tempCow ->getMilkProduced() << " gallons of milk.\n";
				goodbyeMessage(*next);

                std::cout << "Cow Destructor Called \n";
                myPen -> releaseAnimal();
		}

        else if (name == "Cyber Chicken"){

            CyberChicken* tempCyber = static_cast<CyberChicken*>(next);

                std::cout << "This Cyber Chicken laid " << tempCyber->getCyberEggs() << " cyber eggs. Humanity is in trouble.\n";
                goodbyeMessage(*next);

                std::cout << "Cyber Chicken Destructor Called \n";
                myPen -> releaseAnimal();
        }

		else if(name =="Chicken") {

            //Chicken* tempChicken = static_cast<Chicken*>(next);

                std::cout << "Chicken unable to lay eggs. Perhaps cybornetic implants will help? \n";
				goodbyeMessage(*next);

                std::cout << "Chicken Destructor Called \n";
                myPen -> releaseAnimal();
		}
		
		delete next;
	}//end while

	//Final Message displaying totals
	std::cout << "Your farm is awesome. It produced " << total_gallons << " gallons of milk and " << total_eggs << " eggs. Goodbye!\n";

delete myPen;

return(0);

}//end main




















