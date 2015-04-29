/*
 * main.cpp
 * Author: Evan
 * Created on: 2-3-15
 * Purpose: main cpp file driving pokemon game
 */

#include <iostream>
#include <string>
#include "Colosseum.h"
#include "Pokemon.h"
#include "Dice.h"


int main() 
{
	//declare variables and class objects
	Pokemon p1;
	Pokemon p2;
	Colosseum c;

	char playAgain = 'y';


	while(playAgain == 'y' || playAgain == 'Y')
	{

p1 = Pokemon();
p2 = Pokemon();
c = Colosseum();
		//Announce for players to build their Pokemon and build them
		std::cout << "Player 1, build your Pokemon!" << std::endl;
		std::cout << "=============================" << std::endl;
		c.userBuild(p1);

		std::cout << "Player 2, build your Pokemon!" << std::endl;
		std::cout << "=============================" << std::endl;
		c.userBuild(p2);
	
		//calls Colosseum method play
		c.play(p1, p2);

		//ask user if want to play again, if yes, continue loop. if no, exit loop
		std::cout << "Do you want to play again? (y/n): " << std::endl;
		std::cin >> playAgain;
	}

	//thank user for playing
	std::cout << "Thanks for playing!" << std::endl;

	return 0;
}
