/**
*	@file : Chicken.cpp
*	@author :  Evan Nichols
*	@date : 2015.3.4
*	Purpose: Implementation file of Chicken Class. 
*/

#include "Chicken.h"
#include <string>
#include <iostream>

Chicken::Chicken(){

    m_name = "Chicken";
    m_sound = "Cluck";
}

//GET AND SET METHOD FOR INHERITED VARIABLE, M_EGGS

void Chicken::setEggs(int eggs) 
	{m_eggs = eggs;}

int Chicken::getEggs() const 
	{return m_eggs;}
