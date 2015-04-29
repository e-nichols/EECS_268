//Evan Nichols
//2.3.15
//Pokemon.h

#include <iostream>
#include <string>

#ifndef Pokemon_H_
#define Pokemon_H_

class Pokemon {

public:

/*
* @pre: none
* @post: Creates and initializes all numeric data to zero and strings to ""
* @return: initialized Pokemon with no data or name
*/
Pokemon();

/*
* @pre: none
* @post: might reduceHP below zero, in which case the match must end
* @return: reduces m_hp by the amount
*/
void reduceHP(int amount);

/*
* @pre: none
* @post: none
* @return: Pokemon's current HP levels
*/
int getHP() const;

/*
* @pre: none
* @post: none
* @return: Pokemon's current HP levels
*/
void setHP(int amount);

/*
* @pre: none
* @post: none
* @return: Pokemon's attack points
*/
int getAtkPts() const;

/*
* @pre: none
* @post: none
* @return: sets Pokemon's attack points
*/
void setAtkPts(int amount);

/*
* @pre: none
* @post: none
* @return: Pokemon's defense points
*/
int getDefPts() const;

/*
* @pre: defense level will be dependent on how many atkpts were used, must be between 1 and (50-atkpts).
* @post: none
* @return: sets Pokemon's defense points
*/
void setDefPts(int amount);

/*
* @pre: none
* @post: none
* @return: gets the Pokemon's name
*/
std::string getName() const;

/*
* @pre: none
* @post: none
* @return: sets the Pokemon's name
*/
void setName(std::string name);

private:

int m_hp;
int m_atkpts;
int m_defpts;
std::string m_name;

};

#endif




