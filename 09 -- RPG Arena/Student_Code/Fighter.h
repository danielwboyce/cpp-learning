#pragma once
#include "FighterInterface.h"

#include <string>

using namespace std;

const char ARCHER_TYPE = 'A';
const char CLERIC_TYPE = 'C';
const char ROBOT_TYPE = 'R';

class Fighter : public FighterInterface
{
public:
	//Constructor and destructor
	Fighter(string name_in, char type_in, int maxHP_in, int strength_in, int speed_in, int magic_in);
	~Fighter();

	//Returns the name of this fighter.
	string getName();

	//Returns the maximum hit points of this fighter.
	int getMaximumHP();

	//Returns the current hit points of this fighter.
	int getCurrentHP();

	//Returns the strength stat of this fighter.
	int getStrength();

	//Returns the speed stat of this fighter.
	int getSpeed();

	//Returns the magic stat of this fighter.
	int getMagic();


	/*
		Reduces the fighter's current hit points by an amount equal to the given
		damage minus one fourth of the fighter's speed.  This method must reduce
		the fighter's current hit points by at least one.  It is acceptable for
		this method to give the fighter negative current hit points.
	
		Examples:
			damage=10, speed=7		=> damage_taken=9
			damage=10, speed=9		=> damage_taken=8
			damage=10, speed=50		=> damage_taken=1
	*/
	void takeDamage(int damage);

	//CurrentHP has to be a public data member.
	int CurrentHP;

protected:
	string name;
	int maximumHP;
	int Strength;
	int Speed;
	int Magic;
	char type;


};