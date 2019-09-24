#include "mazeSolver.h"
#include <iostream>
using namespace std;
mazeSolver::mazeSolver(const vector<vector<char>>& rhsMaze)
{
	this->maze = rhsMaze;
	counter = 0;
	min = 0;
}
void mazeSolver::printMaze()
{
	for (int index = 0; index < maze.size(); index++)
	{
		for (int index2 = 0; index2 < maze[index].size(); index2++)
		{
			cout << maze[index][index2];
		}
		cout << endl;
	}
}
int mazeSolver::findStartX()
{
	int x = -1; //returns -1 if not found
	for (int index = 0; index < maze.size(); index++)
	{
		for (int index2 = 0; index2 < maze[index].size(); index2++)
		{
			if (maze[index][index2] == 'S')
			{
				x = index;
				goto end;
			}
		}
	}
	end:
	return x;
}
int mazeSolver::findStartY()
{
	int y = -1;
	for (int index = 0; index < maze.size(); index++)
	{
		for (int index2 = 0; index2 < maze[index].size(); index2++)
		{
			if (maze[index][index2] == 'S')
			{
				y = index2;
				goto end;
			}
		}
	}
	end:
	return y;
}
int mazeSolver::shortestPath(int row, int col) 
{
	if (maze[row][col] == 'E')
	{
		return counter; //test to return max jumps
	}
	//check up, down, left, right
	if (row - 1 >= 0) // check up
	{
		if (maze[row - 1][col] == 'O') 
		{
			maze[row - 1][col] = 'X';
			counter++; //increment once
			shortestPath(row - 1, col);
			//put back
			maze[row - 1][col] = 'O';
			counter--; //decrement once
		}

		if (maze[row - 1][col] == 'E')
		{
			maze[row - 1][col] = 'X';
			counter++; //increment once
			shortestPath(row, col);
			//put back
			maze[row - 1][col] = 'E';
			counter--; //decrement once
		}
	}

	if (row + 1 <= maze.size() - 1) //check down
	{
		if (maze[row + 1][col] == 'O') //check down, all rows are same size PER matrix
		{
			maze[row + 1][col] = 'X';
			counter++;
			shortestPath(row + 1, col);
			maze[row + 1][col] = 'O';
			counter--;
		}
		if (maze[row + 1][col] == 'E')
		{
			maze[row + 1][col] = 'X';
			counter++; //increment once
			shortestPath(row, col);
			//put back
			maze[row + 1][col] = 'E';
			counter--; //decrement once
		}
	}
	if (col - 1 >= 0) //check left
	{
		if (maze[row][col - 1] == 'O') //check left
		{
			maze[row][col - 1] = 'X';
			counter++;
			shortestPath(row, col - 1);
			maze[row][col - 1] = 'O';
			counter--;
		}
		if (maze[row][col - 1] == 'E')
		{
			maze[row][col - 1] = 'X';
			counter++; //increment once
			shortestPath(row, col);
			//put back
			maze[row][col - 1] = 'E';
			counter--; //decrement once
		}
	}
	if (col + 1 <= maze[row].size() - 1) //check right
	{
		if (maze[row][col + 1] == 'O')
		{
			maze[row][col + 1] = 'X';
			counter++;
			shortestPath(row, col + 1);
			maze[row][col + 1] = 'O';
			counter--;
		}
		if (maze[row][col + 1] == 'E')
		{
			maze[row][col + 1] = 'X';
			counter++; //increment once
			shortestPath(row, col);
			//put back
			maze[row][col + 1] = 'E';
			counter--; //decrement once
		}
	}
}


