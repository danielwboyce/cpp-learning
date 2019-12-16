//Archer - Relies on speed to deal damage. Also can increase its speed for the remainder of the battle(no max bonus speed).

#pragma once
//#include "FighterInterface.h"
#include "Fighter.h"
#include <string>

using namespace std;

class Archer : public Fighter
{
public:
	//constructor and destructor
	Archer(string name_in, char type_in, int maxHP_in, int strength_in, int speed_in, int magic_in);
	~Archer();

	//Archer: This value is equal to the Archer's speed.
	int getDamage();

	//Restores a fighter's current hit points to its maximum hit points. Also resets an Archer's current speed to its original value.
	void reset();

	/*
		Increases the fighter's current hit points by an amount equal to one sixth of
		the fighter's strength.  This method must increase the fighter's current hit
		points by at least one.  Do not allow the current hit points to exceed the
		maximum hit points.
	*/
	void regenerate();

	/*
	*	Archer: Quickstep
		Increases the Archer's speed by one point each time the ability is used.
		This bonus lasts until the reset() method is used.
		This ability always works; there is no maximum bonus speed.
		
		Return true if the ability was used; false otherwise.
	*/
	bool useAbility();

private:
	int maxSpeed;

};
