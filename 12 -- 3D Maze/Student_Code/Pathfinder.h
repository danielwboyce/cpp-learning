#include "PathfinderInterface.h"
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <istream>
//#include <ostream>

using namespace std;

class Pathfinder : public PathfinderInterface
{
public:
	Pathfinder();
	~Pathfinder();

	//Helper functions-------------------------------------------------------------------------
	//This function fills a 3D vector with 1s
	void generateEmptyMaze();
	//This function resets the contents of the current maze to be all 1s
	void resetCurrentMaze();
	//This function recursively calls itself to determine the path to exit the maze
	bool recursiveMazeSolver(int currentFloor, int currentRow, int currentColumn);

	//Part 1-----------------------------------------------------------------------------------
	/*
	* getMaze
	*
	* Returns a string representation of the current maze. Returns a maze of all 1s if no maze
	* has yet been generated or imported.
	*
	* A valid string representation of a maze consists only of 125 1s and 0s (each separated
	* by spaces) arranged in five 5x5 grids (each separated by newlines). A valid maze must
	* also have 1s in the entrance cell (0, 0, 0) and in the exit cell (4, 4, 4).
	*
	* Cell (0, 0, 0) is represented by the first number in the string representation of the
	* maze. Increasing in x means moving toward the east, meaning cell (1, 0, 0) is the second
	* number. Increasing in y means moving toward the south, meaning cell (0, 1, 0) is the
	* sixth number. Increasing in z means moving downward to a new grid, meaning cell
	* (0, 0, 1) is the twenty-sixth number. Cell (4, 4, 4) is represented by the last number.
	*
	* Returns:		string
	*				A single string representing the current maze
	*/
	string getMaze();

	/*
	* createRandomMaze
	*
	* Generates a random maze and stores it as the current maze.
	*
	* The generated maze must contain a roughly equal number of 1s and 0s and must have a 1
	* in the entrance cell (0, 0, 0) and in the exit cell (4, 4, 4).  The generated maze may be
	* solvable or unsolvable, and this method should be able to produce both kinds of mazes.
	*/
	void createRandomMaze();

	//Part 2-----------------------------------------------------------------------------------
	/*
	* importMaze
	*
	* Reads in a maze from a file with the given file name and stores it as the current maze.
	* Does nothing if the file does not exist or if the file's data does not represent a valid
	* maze.
	*
	* The file's contents must be of the format described above to be considered valid.
	*
	* Parameter:	file_name
	*				The name of the file containing a maze
	* Returns:		bool
	*				True if the maze is imported correctly; false otherwise
	*/
	bool importMaze(string file_name);

	//Part 3-----------------------------------------------------------------------------------
	/*
	* solveMaze
	*
	* Attempts to solve the current maze and returns a solution if one is found.
	*
	* A solution to a maze is a list of coordinates for the path from the entrance to the exit
	* (or an empty vector if no solution is found). This list cannot contain duplicates, and
	* any two consecutive coordinates in the list can only differ by 1 for only one
	* coordinate. The entrance cell (0, 0, 0) and the exit cell (4, 4, 4) should be included
	* in the solution. Each string in the solution vector must be of the format "(x, y, z)",
	* where x, y, and z are the integer coordinates of a cell.
	*
	* Understand that most mazes will contain multiple solutions
	*
	* Returns:		vector<string>
	*				A solution to the current maze, or an empty vector if none exists
	*/
	vector<string> solveMaze();

	const int SIZE = 5;
	const int BLOCKED = 0;
	const int UNBLOCKED = 1;
	const int VISITED = 2;
	const int PATH = 3;
	const int INITIAL_POSITION = 0;
	const int FINAL_POSITION = 4;
	int currentFloor;
	int currentRow;
	int currentColumn;
	vector<string> path;
	const vector<string> emptyVector;

private:
	vector<vector<vector<int>>> currentMaze;
};