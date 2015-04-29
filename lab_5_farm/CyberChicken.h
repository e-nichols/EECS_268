/**
*	@file : CyberChicken.h
*	@author :  Evan Nichols
*	@date : 2015.2.24
*	Purpose: Header file of CyberChicken Class. 
*/

#include "Chicken.h"

#ifndef _CyberChicken
#define _CyberChicken

class CyberChicken: public Chicken {

public:
/**
*  @pre None
*  @post sets m_name to "Cyber Chicken" and m_sound to "Resistance is futile"
*  @return Chicken object, child of FarmAnimal
*/
    CyberChicken();

/**
*  @pre None
*  @post sets m_name to "Cyber Chicken" and m_sound to "Resistance is futile"
*  @return the inherited member variable, m_eggs
*/
    int getCyberEggs() const;

/**
*  @pre None
*  @post sets the inherited member variable, m_eggs
*  @return the inherited member variable, m_eggs
*/
    void setCyberEggs(int eggs);

};

#endif