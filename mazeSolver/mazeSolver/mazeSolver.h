#include <vector>
using namespace std;
class mazeSolver
{
	public:
		mazeSolver(const vector<vector<char>>& maze);
		void printMaze();
		char* findStart();
		int shortestPath(int row, int col);

	private:
		vector<vector<char>> maze;
		char* sP;
};