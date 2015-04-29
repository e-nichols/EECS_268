/**
*	@file : CyberChicken.cpp
*	@author :  Evan Nichols
*	@date : 2015.3.4
*	Purpose: Implementation file of CyberChicken Class. 
*/

#include "CyberChicken.h"
#include <string>
#include <iostream>

CyberChicken::CyberChicken(){

    m_name = "Cyber Chicken";
    m_sound = "Resistance is Futile!";
}

//GET AND SET METHOD FOR M_EGGS

void CyberChicken::setCyberEggs(int eggs) 
	{m_eggs = eggs;}

int CyberChicken::getCyberEggs() const 
	{return m_eggs;}
