/**
*	@file : ValueNotFoundExeception.h
*	@author : Evan Nichols
*	@date : 2015.4.10
*	Purpose: Header file for the ValueNotFoundException class
*/

#ifndef _ValueNotFoundExeception
#define _ValueNotFoundExeception

#include <stdexcept>

class ValueNotFoundException: public std::runtime_error {

public:

ValueNotFoundException(const char* msg = "");

};

#endif