/**
*	@file : MazeReader.cpp
*	@author : Evan Nichols
*	@date : 2015.4.20
*	Purpose: Header file for the MazeReader class
*/

#include "MazeReader.h"


MazeReader::MazeReader(std::string file) throw (MazeCreationException) {

	/**
	*	@post A MazeReader is created. A 2D char array is allocated with the maze information.
	*	@throws MazeCreationExecption if any of the following is true:
    *      -The file could not be opened
    *      -The rows or cols are zero or less
    *      -The start position listed is outside the ranges described by the rows and columns
    *      -You do NOT have to check each character for validity, only the rows, cols, and starting position.
	*
	*/

	//create istream to read input file
	filename = file;

	//read maze funciton to handle populating the 2D array
	try
	{
		readMaze();
	}
	catch (MazeCreationException e) 
	{
		std::cout << e.what();
	}
} 	

MazeReader::~MazeReader(){

	//for loop to delete each array in MazeArray
	for(int i = 0; i < m_columns; i++)
	{
		delete[] MazeArray[i];
	}

	delete[] MazeArray;
}

char** MazeReader::getMaze() const 
{
	return MazeArray;
}

int MazeReader::getCols() const
{
	return m_columns;
}

int MazeReader::getRows() const
{
	return m_rows;
}

int MazeReader::getStartCol() const
{
	return m_startCol;
}

int MazeReader::getStartRow() const
{
	return m_startRow;
}

void MazeReader::readMaze()	throw (MazeCreationException){

	std::ifstream myInput(filename);

	//check for validity of file 
	if(!(myInput.good()))
	{
		throw MazeCreationException("Error reading Maze file.\n");
	}
	else
	{
		myInput >> m_rows;
		myInput >> m_columns;
		myInput >> m_startRow;
		myInput >> m_startCol;

		//initialize MazeArray to proper size
		MazeArray = new char*[m_rows];

		//create the rows of arrays
		for(int k = 0; k< m_rows; k++) 
		{
			MazeArray[k] = new char[m_columns];
		}

		//populate array with characters 
		for(int i = 0; i < m_rows; i++)
		{
			//std::cout << "entered first loop\n";
			for(int j = 0; j < m_columns; j++)
			{
				//for each index of char array
				myInput >> MazeArray[i][j];
			}
		}
	}

	//check for valid size and starting position
	if(m_rows <= 0 || m_columns <= 0 || m_startCol < 0 || m_startCol > m_columns || m_startRow > m_rows || m_startRow < 0)
	{
		throw MazeCreationException("Error with Maze Size or Starting Position.\n");
	}

	//test output
		std::cout << "Maze Information: \n"
				<< "# rows: " << m_rows << "\n"
				<< "# cols: " << m_columns << "\n"
				<< "starting row:  " << m_startRow << "\n"
				<< "starting column: " << m_startCol << "\n";

}

