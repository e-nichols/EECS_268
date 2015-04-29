/**
*	@file : MazeWalker.cpp
*	@author : Evan Nichols
*	@date : 2015.4.20
*	Purpose: Implementation file for the MazeWalker class
*/

#include "MazeWalker.h"
#include "Position.h"

 MazeWalker::MazeWalker(char** mazePtr, int startRow, int startCol, int rows, int cols, bool dfs): m_curPos(Position(startRow, startCol)), m_startPos(Position(startRow, startCol))
 {

 	//initialize member variables
	m_rows = rows;
	m_cols = cols;

	m_maze = mazePtr;
	m_visited = nullptr;
	m_isDFS = dfs;

 	//initialize the bool 2D array m_visited
 	//std::cout << "Initializing Boolean Visited array... \n \n";

		m_visited = new bool*[m_rows];

		//create the rows of arrays
		for(int k = 0; k < m_rows; k++) 
		{
			m_visited[k] = new bool[m_cols];
		}

		//populate array with bools 
		for(int i = 0; i < m_rows; i++)
		{
			for(int j = 0; j < m_cols; j++)
			{
				m_visited[i][j] = false;
				//std::cout << m_visited[i][j];
			}

			//std::cout<<"\n";
		}

		//std::cout << "\n";

		//initialize starting point in m_visited to true
		m_visited[m_startPos.getRow()][m_startPos.getCol()] = true;
}

MazeWalker::~MazeWalker()
{
	//for loop to delete each array in MazeArray
	for(int i = 0; i < m_cols; i++)
	{
		delete[] m_visited[i];
	}

	delete[] m_visited;
} 


void MazeWalker::walkMaze()
{
	/**
	*	@pre The maze is a valid maze.
	*	@post The maze is traversed until (either dfs or bfs) the end is reached or all moves are exhausted. 
	*	The visited array printed during the traversal.
	*/

	if(m_isDFS == true) 
 	{
 		std::cout << "Depth First Search Beginning... \n";

 		storeValidMoves();

 		while(!m_moveStack.empty())
 		{
 			//visit that location
 			std::cout << "Visiting Position (" << m_curPos.getRow() << ", " << m_curPos.getCol() << ")\n";
 			std::cout << "---------------------------\n\n";

 			//print out the m_visited
 			printVisited();

 			//store valid moves from it
 			storeValidMoves();

 			//move on
 			move(m_moveStack.top());

 			//remove that Position from stack
 			m_moveStack.pop();

 			if(isGoalReached())
 			{
 				std::cout << "Exit found!\n";
 				return;
 			}
 		}
 		//stack is empty, not exit found
 		std::cout << "No Exit, what bastards!\n";

		//deleteVisitedArray();
 	}



 	else 
 	{
 		std::cout << "Breadth First Search Beginning... \n";
 		
 	 	storeValidMoves();

 		while(!m_moveQueue.empty())
 		{
 			//visit that location
 			std::cout << "Visiting Position (" << m_curPos.getRow() << ", " << m_curPos.getCol() << ")\n";
 			std::cout << "---------------------------\n\n";

 			//print out the m_visited
 			printVisited();

 			//store valid moves from it
 			storeValidMoves();

 			//move on
 			move(m_moveQueue.front());

 			//remove that Position from stack
 			m_moveQueue.pop();

 			if(isGoalReached())
 			{
 				std::cout << "Exit found!\n";
 				return;
 			}
 		}
 		//stack is empty, not exit found
 		std::cout << "No Exit, what bastards!\n";
}
}

void MazeWalker::storeValidMoves()
{
	/**
	*	@pre The current position is valid.
	*	@post Either the stack (dfs) or queue (bfs) is loaded with valid moves from the current position.
	*/

	if(m_isDFS == true) 
	{
		//check for up move
		if(m_curPos.getRow()-1 >= 0)
		{
			if(m_maze[m_curPos.getRow()-1][m_curPos.getCol()] != 'W' && m_visited[m_curPos.getRow()-1][m_curPos.getCol()] != true)
			{
				//push the Position above current position onto stack
				//std::cout << "up move pushed";
				m_moveStack.push(Position(m_curPos.getRow()-1, m_curPos.getCol()));
			}
			
		}

		//check for down move
		if(m_curPos.getRow()+1 < m_rows)
		{
			if(m_maze[m_curPos.getRow()+1][m_curPos.getCol()] != 'W' && m_visited[m_curPos.getRow()+1][m_curPos.getCol()] != true)
			{
				//push the Position above current position onto stack
				m_moveStack.push(Position(m_curPos.getRow()+1, m_curPos.getCol()));
			}
		}

		//check for left move
		if(m_curPos.getCol()-1 >= 0)
		{
			if(m_maze[m_curPos.getRow()][m_curPos.getCol()-1] != 'W' && m_visited[m_curPos.getRow()][m_curPos.getCol()-1] != true)
			{
				//push the Position above current position onto stack
				m_moveStack.push(Position(m_curPos.getRow(), m_curPos.getCol()-1));
			}
		}

		//check for right move
		if(m_curPos.getCol()+1 < m_cols)
		{
			if(m_maze[m_curPos.getRow()][m_curPos.getCol()+1] != 'W' && m_visited[m_curPos.getRow()][m_curPos.getCol()+1] != true)
			{
				//push the Position above current position onto stack
				m_moveStack.push(Position(m_curPos.getRow(), m_curPos.getCol()+1));
			}		
		}
	}

	else //need to load queue, BFS
	{
		//check for up move
		if(m_curPos.getRow()-1 >= 0)
		{
			if(m_maze[m_curPos.getRow()-1][m_curPos.getCol()] != 'W' && m_visited[m_curPos.getRow()-1][m_curPos.getCol()] != true)
			{
				//push the Position above current position onto stack
				//std::cout << "up move pushed";
				m_moveQueue.push(Position(m_curPos.getRow()-1, m_curPos.getCol()));
			}
			
		}

		//check for down move
		if(m_curPos.getRow()+1 < m_rows)
		{
			if(m_maze[m_curPos.getRow()+1][m_curPos.getCol()] != 'W' && m_visited[m_curPos.getRow()+1][m_curPos.getCol()] != true)
			{
				//push the Position above current position onto stack
				m_moveQueue.push(Position(m_curPos.getRow()+1, m_curPos.getCol()));
			}
		}

		//check for left move
		if(m_curPos.getCol()-1 >= 0)
		{
			if(m_maze[m_curPos.getRow()][m_curPos.getCol()-1] != 'W' && m_visited[m_curPos.getRow()][m_curPos.getCol()-1] != true)
			{
				//push the Position above current position onto stack
				m_moveQueue.push(Position(m_curPos.getRow(), m_curPos.getCol()-1));
			}
		}

		//check for right move
		if(m_curPos.getCol()+1 < m_cols)
		{
			if(m_maze[m_curPos.getRow()][m_curPos.getCol()+1] != 'W' && m_visited[m_curPos.getRow()][m_curPos.getCol()+1] != true)
			{
				//push the Position above current position onto stack
				m_moveQueue.push(Position(m_curPos.getRow(), m_curPos.getCol()+1));
			}		
		}
	}
}

void MazeWalker::move(Position& p)
{
	//set current position, updated m_visited array
	m_curPos = p;
	m_visited[m_curPos.getRow()][m_curPos.getCol()] = true;
}

void MazeWalker::printVisited() const
{
		//populate array with bools 
		for(int i = 0; i < m_rows; i++)
		{
			for(int j = 0; j < m_cols; j++)
			{
				std::cout << m_visited[i][j];
			}

			std::cout<<"\n";
		}
		std::cout << "\n";
}
	
bool MazeWalker::isGoalReached() const 
{
	if(m_maze[m_curPos.getRow()][m_curPos.getCol()] == 'E')
	{
		return true;
	}
	else
	{
		return false;
	}
}


