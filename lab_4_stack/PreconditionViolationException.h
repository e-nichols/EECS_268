/**
*	@file : PreconditionViolationException.h
*	@author :  Evan Nichols
*	@date : 2015.3.3
*	Purpose: header file for PVE class. 
*/

#ifndef _PreconditionViolationException
#define _PreconditionViolationException

#include <stdexcept>

class PreconditionViolationException: public std::runtime_error {

public:

PreconditionViolationException(const char* msg = "");

};

#endif

