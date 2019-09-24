#include <iostream>
#include "mazeSolver.h"
using namespace std;
int main()
{
	vector<vector<char>> mazeFromFile = {{ 'S', 'W', 'W', 'W' },
										  {'O', 'W', 'W', 'W' } ,
										  {'O', 'W', 'W', 'W' },
										  {'E', 'W', 'W', 'W'} };
	mazeSolver a(mazeFromFile);
	int startXLoc = a.findStartX();
	int startYLoc = a.findStartY();
	int min = a.shortestPath(startXLoc, startYLoc);
	cout << min << endl;
	a.printMaze();



	system("pause");
	return 0;
}