#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Property
{
protected:
	string address;
	bool is_rental;
	double value;
	static int property_id;
	int id;
	

public:
	//Constructor and destructor
	Property(string address_in, bool is_rental_in, double value_in);
	virtual ~Property();

	//These will return the address, is_rental, value, and id.
	string getAddress();
	bool getIsRental();
	double getValue();
	int getID();
	
	//This will return a single string with useful information about the property
	virtual string toString() = 0;

	//This will set up the id number data member
	static int id_counter;
	static void resetID();
	static void addOneID();

	//This will return this property's tax rate
	virtual double getTaxes() = 0;

};

