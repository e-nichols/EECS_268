/**
*	@file : Cow.h
*	@author :  Evan Nichols
*	@date : 2015.2.24
*	Purpose: Header file of Cow Class. 
*/

#include "FarmAnimal.h"

#ifndef _Cow
#define _Cow

class Cow: public FarmAnimal {

public:

/**
*  @pre None
*  @post Sets name to "Cow" and sound to "Moo"
*  @return Cow object, child of FarmAnimal
*/
Cow();
 
/**
*  @pre must pass in double if gallons is > 0, assigns the value to m_milkProduced. Set to 0 otherwise
*  @post none
*  @return None (setter)
*/    
void setMilkProduced(double gallons);

/**
*  @pre None
*  @post None
*  @return milkProduced
*/        
double getMilkProduced() const;

protected:
    double m_milkProduced;
};

#endif