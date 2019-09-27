// 08 -- Real Estate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include <sstream>
#include <fstream>
#include <istream>
#include <ostream>

#include "Property.h"
#include "Residential.h"
#include "Commercial.h"

using namespace std;

const string RESIDENTIAL = "Residential";
const string COMMERCIAL = "Commercial";

int Property::id_counter;


int main()
{
	string filename;

	string line;

	vector<Property*> properties;

	Property::resetID();

	cout << "Where should I read the data from? ";
	getline(cin, filename);

	ifstream in_file;
	in_file.open(filename);
	if (!in_file.fail())
	{
		//getline(in_file, line);

		string property_type;

		bool is_rental_in;
		double value_in;
		bool is_occupied_in;
		bool is_discounted_in;
		double discout_rate_in;
		string address_in;
		while (getline(in_file, line))
		{
			stringstream ss;
			ss << line;
			ss >> property_type;
			if (property_type == RESIDENTIAL)
			{
				if (ss >> is_rental_in >> value_in >> is_occupied_in && getline(ss, address_in))
				{

					Residential* onepointer = new Residential(address_in, is_rental_in, value_in, is_occupied_in);
					Property::addOneID();
					properties.push_back(onepointer);
				}
				else
				{
					cout << "Ignoring bad RESIDENTIAL input file: " << line << endl;
				}

			}
			else if (property_type == COMMERCIAL)
			{
				if (ss >> is_rental_in >> value_in >> is_discounted_in >> discout_rate_in && getline(ss, address_in))
				{
					Commercial* onepointer = new Commercial(address_in, is_rental_in, value_in, is_discounted_in, discout_rate_in);
					Property::addOneID();
					properties.push_back(onepointer);
				}
				else
				{
					cout << "Ignoring bad COMMERCIAL input file: " << line << endl;
				}
			}
			else
			{
				cout << "Ignoring unknown types of properties appearing in the input file: " << line << endl;
			}
		}
	}
	else
	{
		cout << endl << "I cannot locate the file " << filename << ", or it failed to load." << endl;
		system("pause");
		return 1;

	}


	//This will display all valid properties
	cout << endl << "All valid properties:" << endl;
	for (int i = 0; i < properties.size(); i++)
	{
		cout << properties[i]->toString();
	}

	//This will calculate the taxes for each property.
	cout << endl << "NOW PRINTING TAX REPORT: " << endl;
	for (int i = 0; i < properties.size(); i++)
	{
		cout << "** Taxes due for property at :" << properties[i]->getAddress() << endl;
		cout << "  Property id:                                 " << properties[i]->getID() << endl;
		cout << "  This property has an estimated value of:     " << properties[i]->getValue() << endl;
		cout << "  Taxes due on this property are:              " << properties[i]->getTaxes() << endl;
	}
	cout << endl;

	system("pause");

	return 0;

}