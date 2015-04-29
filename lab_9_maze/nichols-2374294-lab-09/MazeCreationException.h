/**
*	@file : MazeCreationException.h
*	@author : Evan Nichols
*	@date : 2015.4.10
*	Purpose: Header file for the MazeCreationException class
*/

#ifndef _MazeCreationException
#define _MazeCreationException

#include <stdexcept>

class MazeCreationException: public std::runtime_error {

public:

MazeCreationException(const char* msg = "");

};

#endif