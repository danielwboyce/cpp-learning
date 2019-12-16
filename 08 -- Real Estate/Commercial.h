#pragma once
#include "Property.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Commercial : public Property
{
public:
	//Constructor and destructor
	Commercial(string address_in, bool is_rental_in, double value_in, bool is_discounted_in, double discount_rate_in);
	~Commercial();

	//These will return is_discounted and discount_rate
	bool getIsDiscounted();
	double getDiscountRate();

	//This will return a single string with useful information about the property
	string toString();

	//This will return this property's tax rate
	double getTaxes();

private:
	bool is_discounted;
	double discount_rate;
	const double TAX_RATE_IF_RENTAL = 0.012;
	const double TAX_RATE_IF_NONRENTAL = 0.01;

};