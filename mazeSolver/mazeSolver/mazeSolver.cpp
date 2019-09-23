#include "mazeSolver.h"
#include <iostream>
using namespace std;
mazeSolver::mazeSolver(const vector<vector<char>>& rhsMaze)
{
	sP = 0;
	this->maze = rhsMaze;
	counter = 0;
	max = 0;
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
char* mazeSolver::findStart()
{
	//find s
	sP = &maze[0][0];
	for (int i = 0; i < maze.size(); i++)
	{
		for (int j = 0; i < maze[i].size(); j++)
		{
			if (*sP == 'S')
			{
				break;
			}
			sP = &maze[i][j];
		}
	}
	return sP;
}
int mazeSolver::shortestPath(int row, int col)
{
	//check up, down, left, right
	if (maze[row - 1][col] == 'O')
	{
		maze[row - 1][col] = maze[row][col]; //s moved up
		maze[row][col] = ' ';
		shortestPath(row - 1, col); //pass in new pos of s
		counter++; //increment once
		if (counter > max)
		{
			max = counter;
		}
		//put back
		maze[row - 1][col] = 'O';
		maze[row][col] = 'S';
		counter--; //decrement once
	}

	if (maze[row + 1][col] == 'O')
	{
		maze[row + 1][col] = maze[row][col]; //s moved down
		maze[row][col] = ' ';
		counter++;
		if (counter > max)
		{
			max = counter;
		}
		shortestPath(row + 1, col);
		maze[row + 1][col] = 'O';
		maze[row][col] = 'S';
		counter--;
	}

	if (maze[row][col - 1] == 'O')
	{
		maze[row][col - 1] = maze[row][col]; //s moved left
		maze[row][col] = ' ';
		counter++;
		if (counter > max)
		{
			max = counter;
		}
		shortestPath(row, col - 1);
		maze[row][col - 1] = 'O';
		maze[row][col] = 'S';
		counter--;
	}

	if (maze[row][col + 1] == 'O')
	{
		maze[row][col + 1] = maze[row][col]; //s moved right
		maze[row][col] = ' ';
		counter++;
		if (counter > max)
		{
			max = counter;
		}
		shortestPath(row, col + 1);
		maze[row][col + 1] = 'O';
		maze[row][col] = 'S';
		counter--;

	}
}


