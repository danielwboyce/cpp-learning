#include "Property.h"
using namespace std;

//Constructor and destructor
Property::Property(string address_in, bool is_rental_in, double value_in)
{
	this->address = address_in;
	this->is_rental = is_rental_in;
	this->value = value_in;
	this->id = id_counter;
}
Property::~Property(){}

//These will return the address, is_rental, value, and ID.
string Property::getAddress()
{
	return this->address;
}
bool Property::getIsRental()
{
	return this->is_rental;
}
double Property::getValue()
{
	return this->value;
}
int Property::getID()
{
	return this->id;
}

//This will set up the id number data member
void Property::resetID()
{
	id_counter = 0;
}
void Property::addOneID()
{
	id_counter++;
}