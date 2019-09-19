#include <vector>
using namespace std;
class mazeSolver
{
	public:
		mazeSolver(const vector<vector<char>>& maze);
		void deepCopy(const vector<vector<char>>& rhsMaze);
		int shortestPath();

	private:
		vector<vector<char>> maze;
		char* sP;
};