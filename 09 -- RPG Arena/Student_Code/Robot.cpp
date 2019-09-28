//Robot - Relies on strength to deal damage. Also can use stored energy to temporarily increase damage(max / starting energy equal to 2 * magic). Only Robots have energy.

#include "Robot.h"
using namespace std;

//Constructor and destructor
Robot::Robot(string name_in, char type_in, int maxHP_in, int strength_in, int speed_in, int magic_in) :
Fighter(name_in, type_in, maxHP_in, strength_in, speed_in, magic_in)
{
	this->maxEnergy = 2 * this->getMagic();
	this->currentEnergy = this->maxEnergy;
	this->bonusDamage = 0;
}
Robot::~Robot(){}

//This returns the value of the maximum amount of energy
int Robot::getMaxEnergy() const
{
	return this->maxEnergy;
}

//Returns the amount of damage a fighter will deal. This value is equal to the Robot's strength plus any additional damage added for 
//having just used its special ability. After attacking bonus damage is always reset to zero.
int Robot::getDamage()
{
	int damage_temp = this->getStrength() + this->bonusDamage;
	this->bonusDamage = 0;
	return damage_temp;
}

/*
Restores a fighter's current hit points to its maximum hit points.

Also restores a Robot's current energy to its maximum value (which is 2 times its magic).
Also resets a Robot's bonus damage (calculated when a Robot uses its ability) to 0.
*/
void Robot::reset()
{
	this->CurrentHP = this->getMaximumHP();
	this->currentEnergy = 2 * this->getMagic();
	this->bonusDamage = 0;
}

/*
*	Increases the fighter's current hit points by an amount equal to one sixth of
*	the fighter's strength.  This method must increase the fighter's current hit
*	points by at least one.  Do not allow the current hit points to exceed the
*	maximum hit points.
*/
void Robot::regenerate()
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
*	Attempts to perform a special ability based on the type of fighter.  The
*	fighter will attempt to use this special ability just prior to attacking
*	every turn.
*
*	Robot: Shockwave Punch
*	Adds bonus damage to the Robot's next attack (and only its next attack) equal to (strength  * ((current_energy/maximum_energy)^4)).
*	Can only be used if the Robot has at least [ROBOT_ABILITY_COST] energy.
*	Decreases the Robot's current energy by [ROBOT_ABILITY_COST] (after calculating the additional damage) when used.
*		Examples:
*		strength=20, current_energy=20, maximum_energy=20		=> bonus_damage=20
*		strength=20, current_energy=15, maximum_energy=20		=> bonus_damage=6
*		strength=20, current_energy=10, maximum_energy=20		=> bonus_damage=1
*		strength=20, current_energy=5,  maximum_energy=20		=> bonus_damage=0
*	Robot Note:
*	The bonus damage formula should be computed using double arithmetic, and only
*	the final result should be cast into an integer.
*
*	Return true if the ability was used; false otherwise.
*/
bool Robot::useAbility()
{
	int current_energy_temp = this->currentEnergy;
	//cout << this->getName() << " " << this->currentEnergy << endl;
	if (current_energy_temp >= ROBOT_ABILITY_COST)
	{
		double strength_d = this->getStrength();
		double current_energy_d = this->currentEnergy;
		double maximum_energy_d = this->getMaxEnergy();
		const double EXPONENTIATION_CONSTANT = 4.0;
		double bonus_damage_d = strength_d * pow((current_energy_d / maximum_energy_d), EXPONENTIATION_CONSTANT);
		this->bonusDamage = bonus_damage_d;

		this->currentEnergy = this->currentEnergy - ROBOT_ABILITY_COST;

		//cout << "The special ability was used by " << this->getName() << "when the energy was " << current_energy_temp << endl;		
		return true;
	}
	else
	{
		//cout << "The special ability was NOT used by " << this->getName() << "when the energy was " << current_energy_temp << endl;
		return false;
	}
}
