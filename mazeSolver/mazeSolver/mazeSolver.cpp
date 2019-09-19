#include "mazeSolver.h"

mazeSolver::mazeSolver(const vector<vector<char>>& rhsMaze)
{
	deepCopy(rhsMaze);
}

void mazeSolver::deepCopy(const vector<vector<char>>& rhsMaze)
{
	for (int i = 0; i < rhsMaze.size(); i++)
	{
			this->maze.push_back(rhsMaze[i]);	
	}
}

int mazeSolver::shortestPath()
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
			else
			{
				sP = &maze[i][j];
			}
		}
	}
	//check up, down, left, right

}

