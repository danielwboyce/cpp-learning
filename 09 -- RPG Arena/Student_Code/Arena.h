#pragma once
#include "ArenaInterface.h"
//#include "FighterInterface.h"
//#include "Fighter.h"
#include "Archer.h"
#include "Cleric.h"
#include "Robot.h"

#include <sstream>
#include <fstream>
#include <istream>
#include <ostream>

using namespace std;

class Arena : public ArenaInterface
{
public:
	//Constructor and destructor
	Arena();
	~Arena();

	//Adds a new fighter to the collection of fighters in the arena.
	bool addFighter(string info);

	//Removes the fighter whose name is equal to the given name.
	bool removeFighter(string name);

	//Returns the memory address of a fighter whose name is equal to the given name.
	FighterInterface* getFighter(string name);

	//Returns the number of fighters in the arena.
	int getSize();

private:
	//This is vector that contains the list of pointers to all fighters.
	vector<FighterInterface*> FighterList;
};