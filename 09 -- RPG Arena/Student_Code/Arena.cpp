#include "Arena.h"

using namespace std;

//Constructor and destructor
Arena::Arena() : ArenaInterface() 
{
	vector<FighterInterface*> FighterList;
}
Arena::~Arena(){}

/*
	Adds a new fighter to the collection of fighters in the arena. Do not allow
	duplicate names.  Reject any string that does not adhere to the format
	outlined in the lab specs.

	Return true if a new fighter was added; false otherwise.
*/
bool Arena::addFighter(string info)
{
	//Rejects the empty string. Else continues
	if (info == "")
	{
		return false;
	}
	else
	{

		string name_in;
		char type_in;
		int maxHP_in = 0;
		int Strength_in = 0;
		int Speed_in = 0;
		int Magic_in = 0;
		string extra_argument_holder;

		stringstream ss;
		ss << info;


		if (ss >> name_in)
		{
			//This is to check to see if the name being found is already in the list.
			bool found = false;
			for (int i = 0; i < FighterList.size(); i++)
			{
				string tempName = (*FighterList[i]).getName();
				if (tempName == name_in)
				{
					found = true;
				}
			}

			//cout << found << endl;
			//system("pause");

			//If it was found, it won't input it
			if (found == true)
			{
				//cout << "You cannot input a fighter with the same name." << endl;
				return false;
			}
			else
			{
				if (ss >> type_in)
				{
					if (type_in == ARCHER_TYPE)
					{
						if (ss >> maxHP_in >> Strength_in >> Speed_in >> Magic_in && maxHP_in > 0 && Strength_in > 0 && Speed_in > 0 && Magic_in > 0)
						{
							if (ss >> extra_argument_holder)
							{
								return false;
							}
							if (!(ss >> extra_argument_holder))
							{
								Archer* onepointer = new Archer(name_in, type_in, maxHP_in, Strength_in, Speed_in, Magic_in);
								FighterList.push_back(onepointer);
								//cout << "We were OK'd throug the archer route" << endl;
								return true;
							}

						}
						else
						{
							//cout << "We were rejected through the archer route" << endl;
							return false;
						}
					}
					else if (type_in == CLERIC_TYPE)
					{
						if (ss >> maxHP_in >> Strength_in >> Speed_in >> Magic_in && maxHP_in > 0 && Strength_in > 0 && Speed_in > 0 && Magic_in > 0)
						{
							if (ss >> extra_argument_holder)
							{
								return false;
							}
							if (!(ss >> extra_argument_holder))
							{
								Cleric* onepointer = new Cleric(name_in, type_in, maxHP_in, Strength_in, Speed_in, Magic_in);
								FighterList.push_back(onepointer);
								//cout << "We were OK'd throug the cleric route" << endl;
								return true;
							}
						}
						else
						{
							//cout << "We were rejected through the cleric route." << endl;
							return false;
						}
					}
					else if (type_in == ROBOT_TYPE)
					{
						if (ss >> maxHP_in >> Strength_in >> Speed_in >> Magic_in && maxHP_in > 0 && Strength_in > 0 && Speed_in > 0 && Magic_in > 0)
						{
							if (ss >> extra_argument_holder)
							{
								return false;
							}
							if (!(ss >> extra_argument_holder))
							{
								Robot* onepointer = new Robot(name_in, type_in, maxHP_in, Strength_in, Speed_in, Magic_in);
								FighterList.push_back(onepointer);
								//cout << "We were OK'd throug the robot route" << endl;
								return true;
							}
						}
						else
						{
							//cout << "We were rejected through the robot route." << endl;
							return false;
						}
					}
					else
					{
						//cout << "The provided data is not in the correct format." << endl;
						return false;
					}
				}
			}
		}
	}
}

/*
	Removes the fighter whose name is equal to the given name.  Does nothing if
	no fighter is found with the given name.

	Return true if a fighter is removed; false otherwise.
*/
bool Arena::removeFighter(string name)
{
	bool found = false;
	for (int i = 0; i < FighterList.size(); i++)
	{
		string tempName = (*FighterList[i]).getName();
		if (tempName == name)
		{
			found = true;
			for (int j = i + 1; j < FighterList.size(); j++)
			{
				FighterList[j - 1] = FighterList[j];
			}
			FighterList.pop_back();
			return true;
		}
	}
	if (found == false)
	{
		return false;
	}
	
}

/*
	Returns the memory address of a fighter whose name is equal to the given
	name.  Returns NULL if no fighter is found with the given name.

	Return a memory address if a fighter is found; NULL otherwise.
*/
FighterInterface* Arena::getFighter(string name)
{
	bool found = false;
	for (int i = 0; i < FighterList.size(); i++)
	{
		string tempName = (*FighterList[i]).getName();
		if (tempName == name)
		{
			found = true;
			return FighterList[i];
		}
	}
	if (found == false)
	{
		return NULL;
	}
}

/*
	Returns the number of fighters in the arena.

	Return a non-negative integer.
*/
int Arena::getSize()
{
	return this->FighterList.size();
}
