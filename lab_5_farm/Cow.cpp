/**
*	@file : Cow.cpp
*	@author :  Evan Nichols
*	@date : 2015.2.24
*	Purpose: Implementation file of Cow Class. 
*/

#include "Cow.h"
#include <string>

Cow::Cow(){
	m_name = "Cow";
	m_sound = "Moo";
}

//GET AND SET METHODS FOR NAME AND SOUND
void Cow::setMilkProduced(double gallons) {

	if (gallons > 0){
		m_milkProduced = gallons;
	}
	else {
		m_milkProduced = 0;
	}
}

double Cow::getMilkProduced() const {return m_milkProduced;} 

