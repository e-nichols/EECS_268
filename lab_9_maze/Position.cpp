/**
*	@file : Position.cpp
*	@author : Evan Nichols
*	@date : 2015.4.20
*	Purpose: Implementation file for the Position class
*/

#include "Position.h"

Position::Position(int row, int col)
{
	m_row = row;
	m_col = col;
}

int Position::getRow() const 
{
	return m_row;
}

int Position::getCol() const 
{
	return m_col;
}