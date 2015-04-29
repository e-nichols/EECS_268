/**
*	@file : PreconditionViolationException.cpp
*	@author :  Evan Nichols
*	@date : 2015.3.3
*	Purpose: implementation file for PreconditionViolationException class. 
*/

#include <stdexcept>
#include <iostream>
#include "PreconditionViolationException.h"

PreconditionViolationException::PreconditionViolationException(const char* msg): std::runtime_error(msg) {

}


