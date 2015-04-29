//Colosseum.h
//Evan Nichols
//2.3.15

#ifndef COLOSSEUM_H
#define COLOSSEUM_H

#include <iostream>
#include <string>
#include "Pokemon.h"
#include "Dice.h"

class Colosseum {

public:

/*
* @pre: none
* @post: intializes Dice to appropriate sizes
* @return: no return but dice are usable 
*/
Colosseum();

/*
* @pre: hp must be between 1-50, attackLevel + defenseLevel must be between 1-50
* @post: "builds" the pokemon, setting values for name, hp, atkpts, defpts
* @return: void
*/
void userBuild(Pokemon& p);

/*
* @pre: need two valid Pokemon, attacker and defender
* @post: determines if attack hits and how much damage taken
* @return: information about the attack AND a boolean -- did the opponent die from the attack?
*/
bool attack(const Pokemon& attacker, Pokemon& defender);

/*
* @pre: need valid Pokemon, p1 and p2
* @post: handles the 10 round fight, determines when match is over
* @return: displays round information and calls attack to display attack information
*/
void play(Pokemon& p1, Pokemon& p2);

private:

Dice d20;
Dice d6;

};

#endif
