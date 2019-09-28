//Archer - Relies on speed to deal damage. Also can increase its speed for the remainder of the battle(no max bonus speed).

//#include "Fighter.h"
//#include "FighterInterface.h"
#include "Archer.h"
using namespace std;

//Constructor and destructor
Archer::Archer(string name_in, char type_in, int maxHP_in, int strength_in, int speed_in, int magic_in) :
	Fighter(name_in, type_in, maxHP_in, strength_in, speed_in, magic_in)
{
	this->maxSpeed = speed_in;
}
Archer::~Archer(){}

//Archer: This value is equal to the Archer's speed.
int Archer::getDamage()
{
	return this->Speed;
}

//Restores a fighter's current hit points to its maximum hit points. Also resets an Archer's current speed to its original value.
void Archer::reset()
{
	this->CurrentHP = this->getMaximumHP();
	this->Speed = this->maxSpeed;
}

/*
Increases the fighter's current hit points by an amount equal to one sixth of
the fighter's strength.  This method must increase the fighter's current hit
points by at least one.  Do not allow the current hit points to exceed the
maximum hit points.
*/
void Archer::regenerate()
{
	if ((this->getStrength() / 6) >= 1)
	{
		this->CurrentHP += (this->getStrength() / 6);
	}
	else
	{
		this->CurrentHP++;
	}

	if (this->getCurrentHP() > this->getMaximumHP())
	{
		this->CurrentHP = this->getMaximumHP();
	}
}

/*
*	Archer: Quickstep
Increases the Archer's speed by one point each time the ability is used.
This bonus lasts until the reset() method is used.
This ability always works; there is no maximum bonus speed.

Return true if the ability was used; false otherwise.
*/
bool Archer::useAbility()
{
	this->Speed++;

	return true;
}