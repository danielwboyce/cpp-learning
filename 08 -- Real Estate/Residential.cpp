#include "Residential.h"
using namespace std;

//Constructor and destructor
Residential::Residential(string address_in, bool is_rental_in, double value_in, bool is_occupied_in) 
	: Property(address_in, is_rental_in, value_in)
{
	this->is_occupied = is_occupied_in;
}
Residential::~Residential(){}

//This will return is_occupied
bool Residential::getIsOccupied()
{
	return this->is_occupied;
}

//This will return a single string with useful information about the property
string Residential::toString()
{
	stringstream ss;
	ss << "Property id: " << this->getID();
	ss << " Address:" << this->getAddress();
	if (this->getIsRental() == true)
	{
		ss << " Rental";
	}
	else
	{
		ss << " NOT rental";
	}
	ss << " Estimated value: " << this->getValue();
	if (this->getIsOccupied() == true)
	{
		ss << " occupied";
	}
	else
	{
		ss << " NOT occupied";
	}
	ss << endl;
	
	return ss.str();
}

//This will return this property's tax rate
double Residential::getTaxes()
{
	if (this->getIsOccupied() == true)
	{
		return TAX_RATE_IF_OCCUPIED * this->getValue();
	}
	else if (this->getIsOccupied() == false)
	{
		return TAX_RATE_IF_VACANT * this->getValue();
	}
}
