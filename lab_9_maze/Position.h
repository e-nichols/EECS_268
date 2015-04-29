/**
*	@file : Position.h
*	@author : Evan Nichols
*	@date : 2015.4.20
*	Purpose: Header file for the Position class
*/

#ifndef _POSITION
#define	_POSITION

class Position {

public:

/**
*	@post Position created with row and col values set.
*/
	Position(int row, int col);


/**
*	@return row value
*/
	int getRow() const;

/**
*	@return col value
*/
	int getCol() const;

private:
	int m_row;
	int m_col;

};

#endif


