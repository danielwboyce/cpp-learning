//Cleric - Relies on magic to deal damage.  Also can heal itself using mana, restoring hit points (max/starting mana equal to 5*magic). Only Clerics have mana.

#pragma once
#include "Fighter.h"

#include <string>

using namespace std;

class Cleric : public Fighter
{
public:
	//Constructor and destructor
	Cleric(string name_in, char type_in, int maxHP_in, int strength_in, int speed_in, int magic_in);
	~Cleric();

	//This returns the value of the maximum amount of mana
	int getMaxMana() const;
	
	//This value is equal to the Cleric's magic.
	int getDamage();

	//Restores a fighter's current hit points to its maximum hit points.
	//Also restores a Cleric's current mana to its maximum value (which is 5 times its magic).
	void reset();

	/*
		Increases the fighter's current hit points by an amount equal to one sixth of
		the fighter's strength.  This method must increase the fighter's current hit
		points by at least one.  Do not allow the current hit points to exceed the
		maximum hit points.
	
		Also increases a Cleric's current mana by an amount equal to one fifth of the
		Cleric's magic.  This method must increase the Cleric's current mana by at
		least one.  Do not allow the current mana to exceed the maximum mana (again, 5 times its magic).
	*/
	void regenerate();

	/*
		Cleric: Healing Light
		Increases the Cleric's current hit points by an amount equal to one third of its magic.
		Can only be used if the Cleric has at least [CLERIC_ABILITY_COST] mana.
		Will be used even if the Cleric's current HP is equal to their maximum HP.
		Decreases the Cleric's current mana by [CLERIC_ABILITY_COST] when used.
		Cleric Note:
		This ability, when successful, must increase the Cleric's current hit points
		by at least one, unless doing so would given the Cleric more hit points than its maximum hit points.
		Do not allow the current hit points to exceed the maximum hit points.
	
		Return true if the ability was used; false otherwise.
	*/
	bool useAbility();

	int currentMana;

private:
	int maxMana;

};