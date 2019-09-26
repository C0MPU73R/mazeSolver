#include <iostream>
#include <fstream>
#include <string>
#include "mazeSolver.h"
using namespace std;
int main()
{
	vector<string> linesFromFile;
	ifstream file;
	string fileName;
	cout << "Enter file name: ";
	cin >> fileName;
	file.open(fileName);
	if (file.is_open())
	{
		while (!file.eof())
		{
			getline(file, fileName);
			linesFromFile.push_back(fileName);
		}
	}
	file.close();
	for (int index = 0; index < linesFromFile.size(); index++)
	{
		cout << linesFromFile[index] << endl;
	}
	//test






	//mazeSolver a(mazeFromFile);
	//int startXLoc = a.findStartX();
	//int startYLoc = a.findStartY();
	//int min = a.shortestPath(startXLoc, startYLoc);
	//cout << min << endl;
	//a.printMaze();



	system("pause");
	return 0;
}