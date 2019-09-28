/*
All fighters have the following attributes:
Name - The fighter's name
Hit Points - The amount of health the fighter has, with a specified maximum; reaching 0 is equivalent to losing. A Fighter's
starting Hit Points (which is a Fighter's maximum Hit Points) must be greater than 0. There is no upper bound to what
a Fighter's starting/maximum Hit Points could be.
Strength - Physical power, used to determine hit point regeneration. Must be greater than 0. No maximum value.
Speed - Dexterity and physical movement, used to reduce damage when being attacked. Must be greater than 0. No maximum value.
Magic - Magical prowess, used for some special abilities. Must be greater than 0. No maximum value.
*/

//#include "FighterInterface.h"
#include "Fighter.h"
using namespace std;

//Constructor and destructor
Fighter::Fighter(string name_in, char type_in, int maxHP_in, int strength_in, int speed_in, int magic_in) : FighterInterface()
{
	//
	//if (type_in == ARCHER_TYPE || type_in == CLERIC_TYPE || type_in == ROBOT_TYPE)
	//{
		//if (maxHP_in > 0 && strength_in > 0 && speed_in > 0 && magic_in > 0)
		//{
			this->name = name_in;
			this->type = type_in;
			this->maximumHP = maxHP_in;
			this->CurrentHP = maxHP_in;
			this->Strength = strength_in;
			this->Speed = speed_in;
			this->Magic = magic_in;
		//}
		//else
		//{
			//cout << "You provided invalid data." << endl;
		//}
	//}
	//else
	//{
		//cout << "You provided invalid data." << endl;
	//}
}
Fighter::~Fighter(){}

//Returns the name of this fighter.
string Fighter::getName()
{
	return this->name;
}

//Returns the maximum hit points of this fighter.
int Fighter::getMaximumHP()
{
	return this->maximumHP;
}

//Returns the current hit points of this fighter.
int Fighter::getCurrentHP()
{
	return this->CurrentHP;
}

//Returns the strength stat of this fighter.
int Fighter::getStrength()
{
	return this->Strength;
}

//Returns the speed stat of this fighter.
int Fighter::getSpeed()
{
	return this->Speed;
}

//Returns the magic stat of this fighter.
int Fighter::getMagic()
{
	return this->Magic;
}


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
void Fighter::takeDamage(int damage)
{
	int damage_taken = 0;
	if (damage - (this->getSpeed()) / 4 > 0)
	{
		damage_taken = damage - (this->getSpeed()) / 4;
		this->CurrentHP = this->CurrentHP - damage_taken;
	}
	else
	{
		damage_taken = 1;
		this->CurrentHP = this->CurrentHP - damage_taken;
	}
}
