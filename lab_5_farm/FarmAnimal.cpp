/**
*	@file : FarmAnimal.cpp
*	@author :  Evan Nichols
*	@date : 2015.2.24
*	Purpose: Header file of FarmAnimal Class. 
*/

#include "FarmAnimal.h"
#include <iostream>
#include <string>

FarmAnimal::FarmAnimal(){

	m_name = "unset";
	m_sound = "unset";
}

//GET AND SET METHODS FOR NAME AND SOUND

void FarmAnimal::setName(std::string name) 
	{m_name = name;}

std::string FarmAnimal::getName() const 
	{return m_name;}

void FarmAnimal::setSound(std::string sound) 
	{m_sound = sound;}

std::string FarmAnimal::getSound() const 
	{return m_sound;}
