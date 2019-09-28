#include "Pathfinder.h"

using namespace std;

Pathfinder::Pathfinder() : PathfinderInterface()
{
	this->generateEmptyMaze();

	currentFloor = INITIAL_POSITION;
	currentRow = INITIAL_POSITION;
	currentColumn = INITIAL_POSITION;
}
Pathfinder::~Pathfinder(){}

//Helper functions-------------------------------------------------------------------------
//This function fills a 3D vector with 1s
void Pathfinder::generateEmptyMaze()
{
	for (int floor = 0; floor < SIZE; floor++)
	{
		vector<vector<int>> floorvector;
		currentMaze.push_back(floorvector);
		for (int row = 0; row < SIZE; row++)
		{
			vector<int> rowvector;
			currentMaze[floor].push_back(rowvector);
			for (int column = 0; column < SIZE; column++)
			{
				currentMaze[floor][row].push_back(UNBLOCKED);
			}
		}
	}
}
//This function resets the contents of the current maze to be all 1s
void Pathfinder::resetCurrentMaze()
{
	for (int floor = 0; floor < SIZE; floor++)
	{
		for (int row = 0; row < SIZE; row++)
		{
			for (int column = 0; column < SIZE; column++)
			{
				currentMaze[floor][row][column] = UNBLOCKED;
			}
		}
	}

}
//This function recursively calls itself to determine the path to exit the maze
bool Pathfinder::recursiveMazeSolver(int currentFloor, int currentRow, int currentColumn)
{
	if (currentFloor < 0 || currentRow < 0 || currentColumn < 0
		|| currentFloor >= SIZE || currentRow >= SIZE || currentColumn >= SIZE)
	{
		return false;
	}
	else if (currentFloor == FINAL_POSITION && currentRow == FINAL_POSITION && currentColumn == FINAL_POSITION)
	{
		currentMaze[currentFloor][currentRow][currentColumn] = PATH;
		return true;
	}
	else if (currentMaze[currentFloor][currentRow][currentColumn] != UNBLOCKED)
	{
		return false;
	}
	else
	{
		currentMaze[currentFloor][currentRow][currentColumn] = PATH;
		if (recursiveMazeSolver((currentFloor + 1), currentRow, currentFloor)
			|| recursiveMazeSolver((currentFloor - 1), currentRow, currentFloor)
			|| recursiveMazeSolver(currentFloor, (currentRow + 1), currentFloor)
			|| recursiveMazeSolver(currentFloor, (currentRow - 1), currentFloor)
			|| recursiveMazeSolver(currentFloor, currentRow, (currentFloor + 1))
			|| recursiveMazeSolver(currentFloor, currentRow, (currentFloor - 1)))
		{
			return true;
		}
		else
		{
			currentMaze[currentFloor][currentRow][currentColumn] = VISITED;
			return false;
		}

	}


}

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
string Pathfinder::getMaze()
{
	stringstream mazeStream;
	
	for (int floor = 0; floor < SIZE; floor++)
	{
		for (int row = 0; row < SIZE; row++)
		{
			stringstream tempstream;
			for (int column = 0; column < SIZE; column++)
			{
				tempstream << currentMaze[floor][row][column] << " ";
			}
			string tempstring = tempstream.str();
			if (tempstring.back() == ' ')
			{
				tempstring.pop_back();
			}
			mazeStream << tempstring;
			mazeStream << "\n";
		}
		mazeStream << "\n";
	}
	string mazeString = mazeStream.str();
	if (mazeString.back() == '\n')
	{
		mazeString.pop_back();
	}
	return mazeString;
}

/*
* createRandomMaze
*
* Generates a random maze and stores it as the current maze.
*
* The generated maze must contain a roughly equal number of 1s and 0s and must have a 1
* in the entrance cell (0, 0, 0) and in the exit cell (4, 4, 4).  The generated maze may be
* solvable or unsolvable, and this method should be able to produce both kinds of mazes.
*/
void Pathfinder::createRandomMaze()
{
	//srand(time(NULL));

	for (int floor = 0; floor < SIZE; floor++)
	{
		for (int row = 0; row < SIZE; row++)
		{
			for (int column = 0; column < SIZE; column++)
			{
				currentMaze[floor][row][column] = rand() % 2;
			}
		}
	}

	currentMaze[0][0][0] = UNBLOCKED;
	currentMaze[4][4][4] = UNBLOCKED;

}

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
bool Pathfinder::importMaze(string file_name)
{
	//this->resetCurrentMaze();
	ifstream mazeInFile;
	mazeInFile.open(file_name);
	if (!mazeInFile.fail())
	{
		int zeroOrOne0 = 0;
		int zeroOrOne1 = 0;
		int zeroOrOne2 = 0;
		int zeroOrOne3 = 0;
		int zeroOrOne4 = 0;
		string runoff = "";
		
		string line;
		vector<vector<vector<int>>> newMaze;
		for (int floor = 0; floor < SIZE; floor++)
		{
			vector<vector<int>> floorvector;
			newMaze.push_back(floorvector);
			for (int row = 0; row < SIZE; row++)
			{
				if (getline(mazeInFile, line))
				{
					stringstream ss;
					ss << line;
					if (ss >> zeroOrOne0 && ss >> zeroOrOne1 && ss >> zeroOrOne2 && ss >> zeroOrOne3 && ss >> zeroOrOne4)
					{
						if (ss >> runoff)
						{
							//cout << "The program thought there was runoff on a line" << endl;
							//this->resetCurrentMaze();
							return false;
						}
						else
						{
							vector<int> rowvector;
							newMaze[floor].push_back(rowvector);
							
							newMaze[floor][row].push_back(zeroOrOne0);
							newMaze[floor][row].push_back(zeroOrOne1);
							newMaze[floor][row].push_back(zeroOrOne2);
							newMaze[floor][row].push_back(zeroOrOne3);
							newMaze[floor][row].push_back(zeroOrOne4);
							//cout << "The size of currentMaze[" << floor << "][" << row << "]" << "is " << currentMaze[floor][row].size() << endl;
							//cout << "I did add the row," << zeroOrOne0 << " " << zeroOrOne1 << " " <<
							//	zeroOrOne2 << " " << zeroOrOne3 << " "<< zeroOrOne4 << " though" <<
							//	endl;
						}
					}
					else
					{
						//cout << "The program thought that there was bad input on a particular line." << endl;
						//this->resetCurrentMaze();
						return false;
					}
				}
				else
				{
					//cout << "The program thought that it couldn't get a line." << endl;
					//cout << "The maze before resetting: " << this->getMaze();

					//cout << "The maze after resetting: " << this->getMaze();
					return false;
				}
				
			}
			getline(mazeInFile, line);
		}
		if (getline(mazeInFile, line))
		{
			//cout << "The program thought that there was still input after getting the complete maze" << endl;
			//this->resetCurrentMaze();
			return false;
		}
		else
		{
			//cout << "The segfault happened in here.";
			if (newMaze.size() == SIZE && newMaze[4].size() == SIZE && newMaze[4][3].size() == SIZE)
			{
				if (newMaze[0][0][0] == UNBLOCKED && newMaze[4][4][4] == UNBLOCKED)
				{
					for (int floor = 0; floor < SIZE; floor++)
					{
						for (int row = 0; row < SIZE; row++)
						{
							for (int column = 0; column < SIZE; column++)
							{
								currentMaze[floor][row][column] = newMaze[floor][row][column];
							}
						}
					}
					//cout << "I should be returning true." << endl;					
					return true;
				}
				else
				{
					//cout << "I am returning false here." << endl;					
					return false;
				}
			}
			else
			{
				//cout << "I am returning false here." << endl;	
				//cout << "newMaze.size() is " << newMaze.size() << " newMaze[4].size() is " << newMaze[4].size() << " newMaze[4][3].size() is " << newMaze[4][3].size() << endl;		
				return false;
			}
			
		}
	}
	else
	{
		//cout << "The program thought the file didn't open." << endl;
		//this->resetCurrentMaze();
		return false;
	}
	
	
	//return false;
}

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
vector<string> Pathfinder::solveMaze()
{
	if (recursiveMazeSolver(this->currentFloor, this->currentRow, this->currentColumn))
	{
		int printingCurrentFloor = INITIAL_POSITION;
		int printingCurrentRow = INITIAL_POSITION;
		int printingCurrentColumn = INITIAL_POSITION;
		while (currentMaze[printingCurrentFloor][printingCurrentRow][printingCurrentColumn] == PATH
			&& (printingCurrentFloor != FINAL_POSITION || printingCurrentRow != FINAL_POSITION
			|| printingCurrentColumn != FINAL_POSITION))
		{
			stringstream ss;
			ss << "(" << printingCurrentFloor << ", " << printingCurrentRow << ", "
				<< printingCurrentColumn << ")";
			path.push_back(ss.str());
			if (currentMaze[printingCurrentFloor + 1][printingCurrentRow][printingCurrentColumn] == PATH)
			{
				currentMaze[printingCurrentFloor][printingCurrentRow][printingCurrentColumn] = UNBLOCKED;
				printingCurrentFloor += printingCurrentFloor;
			}
			else if (currentMaze[printingCurrentFloor - 1][printingCurrentRow][printingCurrentColumn] == PATH)
			{
				currentMaze[printingCurrentFloor][printingCurrentRow][printingCurrentColumn] = UNBLOCKED;
				printingCurrentFloor -= printingCurrentFloor;
			}
			else if (currentMaze[printingCurrentFloor][printingCurrentRow + 1][printingCurrentColumn] == PATH)
			{
				currentMaze[printingCurrentFloor][printingCurrentRow][printingCurrentColumn] = UNBLOCKED;
				printingCurrentRow += printingCurrentRow;
			}
			else if (currentMaze[printingCurrentFloor][printingCurrentRow - 1][printingCurrentColumn] == PATH)
			{
				currentMaze[printingCurrentFloor][printingCurrentRow][printingCurrentColumn] = UNBLOCKED;
				printingCurrentRow -= printingCurrentRow;
			}
			else if (currentMaze[printingCurrentFloor][printingCurrentRow][printingCurrentColumn + 1] == PATH)
			{
				currentMaze[printingCurrentFloor][printingCurrentRow][printingCurrentColumn] = UNBLOCKED;
				printingCurrentColumn += printingCurrentColumn;
			}
			else if (currentMaze[printingCurrentFloor][printingCurrentRow][printingCurrentColumn - 1] == PATH)
			{
				currentMaze[printingCurrentFloor][printingCurrentRow][printingCurrentColumn] = UNBLOCKED;
				printingCurrentColumn -= printingCurrentColumn;
			}
		}
	}
	return path;
}
