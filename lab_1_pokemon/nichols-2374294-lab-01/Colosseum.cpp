/**
*	@file : Colosseum.cpp
*	@author :  Evan Nichols
*	@date : 2.3.2015
*	Purpose: Implementation of Colosseum Class
*/

#include <string>
#include <iostream>
#include "Colosseum.h"
#include "Pokemon.h"
#include "Dice.h"

//CONSTRUCTOR METHOD
Colosseum::Colosseum(){

//initialize Dice to proper sizes
 d20= Dice(20);
 d6 = Dice(6);
}


//USERBUILD METHOD
void Colosseum::userBuild(Pokemon& p) {

//initalize vars to be used during Pokemon set methods
int hp=0;
int atkpts=0;
int defpts=0;
std::string name;

//get Pokemon name
std::cout << "Please name your Pokemon: ";
std::cin >> name;

//check validity of name
while(name.length() == 0){
std::cout << "Sorry, name must be 1 letter or longer. Try again: ";
std::cin >> name;
}

//set name
p.setName(name);

//get Pokemon HP
std::cout << "How many hit points will it have? (1-50): ";
std::cin >> hp;

//check validity of HP
while(hp < 1 || hp > 50){
std::cout << "Sorry, HP must be between 1 and 50. Try again: ";
std::cin >> hp;
}

//set hp
p.setHP(hp);

//Attack and Defense Levels//

//initial prompt
std::cout << "Split 50 points between attack level and defense level.";

//get attack level
std::cout << "Enter your attack level (1-49): ";

std::cin >> atkpts;

//check validity of attack level
while(atkpts < 1 || atkpts > 50) {
std::cout << "Sorry, attack level must be between 1-50. Try again: ";
std::cin >> atkpts;
}

//set atkpts once valid
p.setAtkPts(atkpts);

//get defense level (based off points left over after atkpts was set)
std::cout << "Enter your defense level (1-" << 50-p.getAtkPts() << "): ";
std::cin >> defpts;

while(defpts < 1 || defpts > (50-p.getAtkPts())) {
std::cout << "Sorry, defense level must be between 1 and "<< 50-p.getAtkPts() << ". Try again: ";
std::cin >> defpts;
}

//set defpts once valid
p.setDefPts(defpts);
}

//ATTACK METHOD
bool Colosseum::attack(const Pokemon& p1, Pokemon& p2) {

//init Dice, declare isGameOver var
bool isGameOver;
//Dice d20 = Dice(20);
//Dice d6 = Dice(6);

//Announce Attacker
std::cout << p1.getName() << " is attacking " << p2.getName();


//Get attack and defense rolls
int attackbonus = d20.roll();
std::cout << p1.getName() << " rolls an attack bonus of " << attackbonus;

int defensebonus = d20.roll();
std::cout << p2.getName() << " rolls a defense bonus of " << defensebonus;

//Logic to see if attack lands

if(p1.getAtkPts()+attackbonus > p2.getDefPts()+defensebonus) {

//attack lands, display to user
std::cout << "The attack hits, dealing 3-D6 damage!";

	//calculate 3 D-6 rolls, reduce damage to user
	int roll1 = d6.roll();
	int roll2 = d6.roll();
	int roll3 = d6.roll();

	int totaldamage = roll1+roll2+roll3;

	//display rolls to user
	std::cout << "The rolls are: " << roll1 << ", " << roll2 << ", and " << roll3 << ", totaling: " << totaldamage << "!";

	//reduce opponent HP, display to user
	p2.reduceHP(totaldamage);

		//check to see if opponent HP <=0, update isGameOver accordingly
		if(p2.getHP() <= 0){
		std::cout << p2.getName() << " has been defeated!"; 
		isGameOver = true;
		}
		else {
		//player still alive, display current HP
		std::cout << p2.getName() << " has " << p2.getHP() << " hit points left";
		isGameOver = false;}

}

else {
//attack misses, display to user
std::cout << "The attack missed!";
}

//return isGameOver
return(isGameOver);
}

void Colosseum::play(Pokemon& p1, Pokemon& p2) {

int whoGoesFirst;
Dice d2 = Dice(2);

whoGoesFirst = d2.roll();

std::cout << "Choosing which player to go first:";

	if(whoGoesFirst == 1) {

	//player 1 will go first
	std::cout << "Player 1 will go first.";

		//Enter 10 Round fight, or until one of the players dies
		for(int i = 1; i <= 10; i++) {

		//two attack vars
		bool atk1;
		bool atk2;

		//Round Number
		std::cout<<"Round " << i << "!";

		//player 1 attacks first
		atk1 = attack(p1, p2);

			if(atk1 == true) {

			//break the loop if defender died
			break;
			}

			atk2 = attack(p2,p1);

			if(atk2 == true) {

			//break the loop if defender died
			break;
			}
	}//end for loop
}//end if statement

else if(whoGoesFirst == 2) {

std::cout << "Player 2 will go first.";

//Enter 10 Round fight, or until one of the players dies
		for(int i = 1; i <= 10; i++) {

		//two attack vars
		bool atk1;
		bool atk2;

		//Round Number
		std::cout<<"Round " << i << "!";

		//player 2 attacks first
		atk1 = attack(p2, p1);

			if(atk1 == true) {

			//break the loop if defender died
			break;
			}

			atk2 = attack(p1,p2);

			if(atk2 == true) {

			//break the loop if defender died
			break;
			}
		}//end for loop

	}//end else if

}//play method closer








 




