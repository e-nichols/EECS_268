/**
*	@file : FarmAnimal.h
*	@author :  Evan Nichols
*	@date : 2015.2.24
*	Purpose: Header file of FarmAnimal Class. 
*/

#include <iostream>
#include <string>

#ifndef _FarmAnimal
#define _FarmAnimal

class FarmAnimal {

public:

/**
*  @pre None
*  @post Sets name and sound to the string "unset" by default
*  @return Farm Animal object, parent object of all animals
*/
FarmAnimal();

/**
*  @pre must be called on FarmAnimal object or child class
*  @post none
*  @return name of the FarmAnimal
*/
std::string getName() const;


/**
*  @pre must be called on FarmAnimal object or child class
*  @post Sets name variable
*  @return none (Setter)
*/
void setName(std::string name);


/**
*  @pre must be called on FarmAnimal object or child class
*  @post Sets name and sound to the string "unset by default"
*  @return none (Setter)
*/
void setSound(std::string sound);

/**
*  @pre must be called on FarmAnimal object or child class
*  @post none
*  @return sound of the FarmAnimal
*/
std::string getSound() const;



protected:

	std::string m_name;
	std::string m_sound;


};

#endif