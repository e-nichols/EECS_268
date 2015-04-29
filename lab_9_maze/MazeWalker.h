/**
*	@file : MazeWalker.h
*	@author : Evan Nichols
*	@date : 2015.4.20
*	Purpose: Header file for the MazeWalker class
*/

#include "Position.h"

#include <stack>
#include <queue>
#include <iostream>

#ifndef _MAZEWALKER
#define	_MAZEWALKER

class MazeWalker {

public:
	
	 /**
	*	@pre The mazePtr pointer is to a valid maze.
	*	@post A maze walker if created with all needed flags set and the visited array contains all false.
	*/
 	MazeWalker(char** mazePtr, int startRow, int startCol, int rows, int cols, bool dfs);

	 /**
	*	@pre The maze is a valid maze.
	*	@post The maze is traversed until (either dfs or bfs) the end is reached or all moves are exhausted. 
	*	The visited array printed during the traversal.
	*/
	 void walkMaze();

	~MazeWalker();

protected:

 	/**
	*	@pre The current position is valid.
	*	@post Either the stack (dfs) or queue (bfs) is loaded with valid moves from the current position.
	*/
	void storeValidMoves();


	/**
	*	@pre The position is valid.
	*	@post The current position is set to p and the position is updated as marked.
	*/
	void move(Position& p);


	/**
	*	@returns If the current position is the exit, true is returned. False is returned otherwise.
	*/		
	bool isGoalReached() const;

	//helper method to print visited array.
	void printVisited() const;

    //member variables
	bool m_isDFS;
	char** m_maze;
	bool** m_visited;
	int m_rows, m_cols;

	Position m_curPos;
	Position m_startPos;

	std::stack<Position> m_moveStack;
	std::queue<Position> m_moveQueue;

};

#endif

