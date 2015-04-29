/**
*	@file : MazeCreationException.h
*	@author : Evan Nichols
*	@date : 2015.4.10
*	Purpose: Implementation file for the MazeCreationException class
*/

#include "MazeCreationException.h"

MazeCreationException::MazeCreationException(const char* msg): std::runtime_error(msg) {

} 


