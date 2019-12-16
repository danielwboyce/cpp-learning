//Cleric - Relies on magic to deal damage.  Also can heal itself using mana, restoring hit points (max/starting mana equal to 5*magic). Only Clerics have mana.

#include "Cleric.h"
using namespace std;

//Constructor and destructor
Cleric::Cleric(string name_in, char type_in, int maxHP_in, int strength_in, int speed_in, int magic_in) :
Fighter(name_in, type_in, maxHP_in, strength_in, speed_in, magic_in)
{
	this->maxMana = 5 * magic_in;
	this->currentMana = this->maxMana;
}
Cleric::~Cleric(){}

//This returns the value of the maximum amount of mana
int Cleric::getMaxMana() const
{
	return this->maxMana;
}

//This value is equal to the Cleric's magic.
int Cleric::getDamage()
{
	return this->getMagic();
}

//Restores a fighter's current hit points to its maximum hit points.
//Also restores a Cleric's current mana to its maximum value (which is 5 times its magic).
void Cleric::reset()
{
	this->CurrentHP = this->getMaximumHP();
	this->currentMana = this->getMaxMana();
}

/*
Increases the fighter's current hit points by an amount equal to one sixth of
the fighter's strength.  This method must increase the fighter's current hit
points by at least one.  Do not allow the current hit points to exceed the
maximum hit points.

Also increases a Cleric's current mana by an amount equal to one fifth of the
Cleric's magic.  This method must increase the Cleric's current mana by at
least one.  Do not allow the current mana to exceed the maximum mana (again, 5 times its magic).
*/
void Cleric::regenerate()
{
	//cout << this->CurrentHP << " " << this->currentMana << endl;
	
	//This regenerates the fighter's HP
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

	//This regenerates the cleric's mana.
	if ((this->getMagic() / 5) >= 1)
	{
		this->currentMana += (this->getMagic() / 5);
	}
	else
	{
		this->currentMana++;
	}

	if (this->currentMana > this->getMaxMana())
	{
		this->currentMana = this->getMaxMana();
	}

	//cout << this->CurrentHP << " " << this->currentMana << endl;
}

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
bool Cleric::useAbility()
{
	if (this->currentMana > CLERIC_ABILITY_COST)
	{
		if ((this->getMagic() / 3) > 1)
		{
			this->CurrentHP += (this->getMagic() / 3);
		}
		else
		{
			this->CurrentHP++;
		}

		if (this->getCurrentHP() > this->getMaximumHP())
		{
			this->CurrentHP = this->getMaximumHP();
		}
		
		if (this->currentMana > this->getMaxMana())
		{
			this->currentMana = this->getMaxMana();
		}

		this->currentMana -= CLERIC_ABILITY_COST;

		return true;	
	}
	else
	{
		return false;
	}
}