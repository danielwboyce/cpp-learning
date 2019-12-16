#include "Commercial.h"
using namespace std;

//Constructor and destructor
Commercial::Commercial(string address_in, bool is_rental_in, double value_in, bool is_discounted_in, double discount_rate_in)
	: Property(address_in, is_rental_in, value_in)
{
	this->is_discounted = is_discounted_in;
	this->discount_rate = discount_rate_in;
}
Commercial::~Commercial(){}

//These will return is_discounted and discount_rate
bool Commercial::getIsDiscounted()
{
	return is_discounted;
}
double Commercial::getDiscountRate()
{
	return discount_rate;
}

//This will return a single string with useful information about the property
string Commercial::toString()
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
	if (this->getIsDiscounted() == true)
	{
		ss << " Discounted";
		ss << " Discount: " << this->getDiscountRate();
	}
	else
	{
		ss << " NOT discounted";
	}
	ss << endl;

	return ss.str();
}

//This will return this property's tax rate
double Commercial::getTaxes()
{
	if (this->getIsDiscounted() == true)
	{
		if (this->getIsRental() == true)
		{
			return TAX_RATE_IF_RENTAL * (1 - this->getDiscountRate()) * this->getValue();
		}
		else if (this->getIsRental() == false)
		{
			return TAX_RATE_IF_NONRENTAL * (1 - this->getDiscountRate()) * this->getValue();
		}
	}
	else if (this->getIsDiscounted() == false)
	{
		if (this->getIsRental() == true)
		{
			return TAX_RATE_IF_RENTAL * this->getValue();
		}
		else if (this->getIsRental() == false)
		{
			return TAX_RATE_IF_NONRENTAL * this->getValue();
		}
	}
}

