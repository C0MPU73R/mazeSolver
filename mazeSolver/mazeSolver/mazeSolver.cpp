#include "mazeSolver.h"
#include <iostream>
using namespace std;
mazeSolver::mazeSolver(const vector<vector<char>>& rhsMaze)
{
	this->maze = rhsMaze;
	counter = 0;
	min = INT_MAX;
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
	//rewritten
	for (int index = 0; index < maze.size(); index++)
	{
		for (int index2 = 0; index2 < maze[index].size(); index2++)
		{
			if (maze[index][index2] == 'S')
			{
				x = index;
				break;
			}
		}
	}
	return x;
}
int mazeSolver::findStartY()
{
	int y = -1;
	//rewritten
	for (int index = 0; index < maze.size(); index++)
	{
		for (int index2 = 0; index2 < maze[index].size(); index2++)
		{
			if (maze[index][index2] == 'S')
			{
				y = index2;
				break;
			}
		}
	}
	return y;
}
int mazeSolver::shortestPath(int row, int col)
{
	//check up, down, left, right
	if (row - 1 >= 0)
	{
		if (maze[row - 1][col] == 'O' || maze[row - 1][col] == 'E') // check up
		{
			maze[row - 1][col] = maze[row][col]; //s moved up
			maze[row][col] = ' ';
			shortestPath(row - 1, col); //pass in new pos of s
			counter++; //increment once
			if (counter < min)
			{
				min = counter;
			}
			//put back
			
			maze[row][col] = 'S';
			counter--; //decrement once
		}
	}
	if (row + 1 <= maze[0].size() - 1)
	{


		if (maze[row + 1][col] == 'O') //check down, all rows are same size PER matrix
		{
			maze[row + 1][col] = maze[row][col]; //s moved down
			maze[row][col] = ' ';
			counter++;
			if (counter < min)
			{
				min = counter;
			}
			shortestPath(row + 1, col);
			maze[row + 1][col] = 'O';
			maze[row][col] = 'S';
			counter--;
		}
	}
	if (col - 1 >= 0)
	{
		if (maze[row][col - 1] == 'O') //check left
		{
			maze[row][col - 1] = maze[row][col]; //s moved left
			maze[row][col] = ' ';
			counter++;
			if (counter < min)
			{
				min = counter;
			}
			shortestPath(row, col - 1);
			maze[row][col - 1] = 'O';
			maze[row][col] = 'S';
			counter--;
		}
	}
	if (col + 1 <= maze.size() - 1)
	{
		if (maze[row][col + 1] == 'O')
		{
			maze[row][col + 1] = maze[row][col]; //s moved right
			maze[row][col] = ' ';
			counter++;
			if (counter < min)
			{
				min = counter;
			}
			shortestPath(row, col + 1);
			maze[row][col + 1] = 'O';
			maze[row][col] = 'S';
			counter--;

		}
	}
	return min;
}


