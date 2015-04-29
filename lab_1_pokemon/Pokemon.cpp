/**
*	@file : Pokemon.cpp
*	@author : Evan Nichols
*	@date : 1/28/14
*	Purpose: Implementation of Pokemon Class
*/

#include "Pokemon.h"

//constructor class
Pokemon::Pokemon()
{

//initialize hp and levels to 0, name to empty string
m_hp = 0;
m_atkpts = 0;
m_defpts = 0;
m_name = "";
}

//reduceHP method
void Pokemon::reduceHP(int amount)
{m_hp = m_hp - amount;}

//getHP method
int Pokemon::getHP() const
{return(m_hp);}

//setHP method
void Pokemon::setHP(int amount)
{m_hp = amount;}

// getAtkPts method
int Pokemon::getAtkPts() const
{return(m_atkpts);}

// setAtkPts method
void Pokemon::setAtkPts(int amount)
{m_atkpts = amount;}

// getDefPts method
int Pokemon::getDefPts() const
{return(m_defpts);}

// setDefPts method
void Pokemon::setDefPts(int amount)
{m_hp = amount;}

// getName method
std::string Pokemon::getName() const
{return(m_name);}

// setName method
void Pokemon::setName(std::string name)
{m_name = name;}


