/**
*	@file : Chicken.h
*	@author :  Evan Nichols
*	@date : 2015.2.24
*	Purpose: Header file of Chicken Class. 
*/

#include <iostream>
#include <string>
#include "FarmAnimal.h"

#ifndef _Chicken
#define _Chicken


class Chicken: public FarmAnimal {

public:
/**
*  @pre None
*  @post sets name to "Chicken" and sound to "Cluck"
*  @return Chicken object, child of FarmAnimal
*/
    Chicken();
        
protected:
/**
*  @pre None
*  @post None
*  @return number of eggs for this Chicken
*/
    int getEggs() const;

/**
*  @pre None
*  @post sets m_eggs to eggs
*  @return None (setter)
*/
    void setEggs(int eggs);

    int m_eggs;
};

#endif