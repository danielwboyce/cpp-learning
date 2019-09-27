#pragma once
#include "Property.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Residential : public Property
{
public:
	//Constructor and destructor
	Residential(string address_in, bool is_rental_in, double value_in, bool is_occupied_in);
	~Residential();

	//These will return is_occupied
	bool getIsOccupied();

	//This will return a single string with useful information about the property
	string toString();

	//This will return this property's tax rate
	double getTaxes();

private:
	bool is_occupied;
	const double TAX_RATE_IF_OCCUPIED = 0.006;
	const double TAX_RATE_IF_VACANT = 0.009;
};

