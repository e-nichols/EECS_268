/**
*	@file : ValueNotFoundExeception.h
*	@author : Evan Nichols
*	@date : 2015.4.10
*	Purpose: Implementation file for the ValueNotFoundException class
*/

#include "ValueNotFoundException.h"
#include <stdexcept>

ValueNotFoundException::ValueNotFoundException(const char* msg): std::runtime_error(msg) {

} 


