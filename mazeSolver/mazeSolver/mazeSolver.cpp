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
	if (maze[row][col] == 'E') //base case
	{
		if (counter > min)
		{
			min = counter;
		}
		return min;
	}

	//check up, down, left, right
	if (row - 1 >= 0)
	{
		if (maze[row - 1][col] == 'O') // check up
		{
			maze[row - 1][col] = 'X';
			counter++; //increment once
			shortestPath(row - 1, col);
			//put back
			maze[row - 1][col] = 'O';
			counter--; //decrement once
		}
	}
	if (row + 1 <= maze.size() - 1)
	{
		if (maze[row + 1][col] == 'O') //check down, all rows are same size PER matrix
		{
			maze[row + 1][col] = 'X';
			counter++;
			shortestPath(row + 1, col);
			maze[row + 1][col] = 'O';
			counter--;
		}
	}
	if (col - 1 >= 0)
	{
		if (maze[row][col - 1] == 'O') //check left
		{
			maze[row][col - 1] = 'X';
			counter++;
			shortestPath(row, col - 1);
			maze[row][col - 1] = 'O';
			counter--;
		}
	}
	if (col + 1 <= maze[row].size() - 1)
	{
		if (maze[row][col + 1] == 'O')
		{
			maze[row][col + 1] = 'X';
			counter++;
			shortestPath(row, col + 1);
			maze[row][col + 1] = 'O';
			counter--;
		}
	}
}


