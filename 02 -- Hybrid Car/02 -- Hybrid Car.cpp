// 02 -- Hybrid Car.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
Inputs
Test case	Yearly Milage	Gas Price	Initial Hyb. Cost	Hybrid Efficiency	Hybrid Resale	Initial NH Cost		NH Efficiency	NH Resale	Criterion
1			12000			2.00		60000				50					35000			40000				25				25000		Gas
2			50000			3.30		45000				36					20000			15000				15				5000		Total
3			2000			1.90		50000				40					40000			30000				20				22000		Total

Outputs
Test case	Hybrid/NH		1st fuel consumption	1st tot.cost	Hybrid/NH		2nd fuel consumption	2nd total cost
1			Hybrid			1200.00					27400.00		Non-Hybrid		2400.00					19800.00
2			Hybrid			6944.44					47916.67		Non-Hybrid		16666.67				65000.00
3			Non-Hybrid		500.00					8950.00			Hybrid			250.00					10475.00
*/

//Extra credit: 166.667 mpg

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	//Inputs the estimated yearly mileage and checks if it's positive
	double yearly_mileage;
	cout << "How many miles do you expect to drive each year\? ";
	cin >> yearly_mileage;
	if (yearly_mileage <= 0)
	{
		cout << endl << "Error. Please enter a value greater than 0: ";
		cin >> yearly_mileage;
	}

	//Inputs the estimated price of a gallon of gas during the ownership period
	//and checks if it's positive
	double gas_price_estimate;
	cout << "How much do you expect a gallon of gas to cost during the ownership period\? $";
	cin >> gas_price_estimate;
	if (gas_price_estimate <= 0)
	{
		cout << endl << "Error. Please enter a value greater than 0: ";
		cin >> gas_price_estimate;
	}

	const double OWNERSHIP_PERIOD = 5.0;

	//Inputs the initial cost of a hybrid car and checks if it's positive
	double initial_hybrid_price;
	cout << endl << "What will the initial price of the hybrid car be\? $";
	cin >> initial_hybrid_price;
	if (initial_hybrid_price <= 0)
	{
		cout << endl << "Error. Please enter a value greater than 0: ";
		cin >> initial_hybrid_price;
	}

	//Inputs efficiency of the hybrid in mpg and checks if it's positive
	double hybrid_efficiency;
	cout << "What will the fuel efficiency of the hybrid be in miles per gallon\? ";
	cin >> hybrid_efficiency;
	if (hybrid_efficiency <= 0)
	{
		cout << endl << "Error. Please enter a value greater than 0: ";
		cin >> hybrid_efficiency;
	}

	//Inputs the estimated resale value of the hybrid after 5 years and checks if
	//it's positive.
	double resale_value_hybrid_estimate;
	cout << "How much do you think you can sell the hybrid for after five years\? $";
	cin >> resale_value_hybrid_estimate;
	if (resale_value_hybrid_estimate <= 0)
	{
		cout << endl << "Error. Please enter a value greater than 0: ";
		cin >> resale_value_hybrid_estimate;
	}

	//Inputs the initial cost of a nonhybrid car and checks if it's positive
	double initial_nonhybrid_price;
	cout << endl << "What will the initial price of the non-hybrid car be\? $";
	cin >> initial_nonhybrid_price;
	if (initial_nonhybrid_price <= 0)
	{
		cout << endl << "Error. Please enter a value greater than 0: ";
		cin >> initial_nonhybrid_price;
	}

	//Inputs efficiency of the nonhybrid in mpg and checks if it's positive
	double nonhybrid_efficiency;
	cout << "What will the fuel efficiency of the non-hybrid be in miles per gallon\? ";
	cin >> nonhybrid_efficiency;
	if (nonhybrid_efficiency <= 0)
	{
		cout << endl << "Error. Please enter a value greater than 0: ";
		cin >> nonhybrid_efficiency;
	}

	//Inputs the estimated resale value of the nonhybrid after 5 years and checks if
	//it's positive.
	double resale_value_nonhybrid_estimate;
	cout << "How much do you think you can sell the non-hybrid for after five years\? $";
	cin >> resale_value_nonhybrid_estimate;
	if (resale_value_nonhybrid_estimate <= 0)
	{
		cout << endl << "Error. Please enter a value greater than 0: ";
		cin >> resale_value_nonhybrid_estimate;
	}

	//Inputs the user's buying criterion
	string gas_or_total;
	cout << endl << "What is your main buying criterion\? Minimized gas consumption or minimized"
		<< endl << "\t total cost\? Please enter \"Gas\" or \"Total\" without quotes: ";
	cin >> gas_or_total;



	//This will find the total fuel consumed and the total cost of owning the hybrid car
	double total_fuel_consumption_hybrid =
		(OWNERSHIP_PERIOD * yearly_mileage) / hybrid_efficiency;
	double total_fuel_cost_hybrid = total_fuel_consumption_hybrid * gas_price_estimate;
	double depreciation_hybrid = initial_hybrid_price - resale_value_hybrid_estimate;
	double total_hybrid_ownership_cost = depreciation_hybrid + total_fuel_cost_hybrid;

	//This will find the total fuel consumed and the total cost of owning the nonhybrid car
	double total_fuel_consumption_nonhybrid =
		(OWNERSHIP_PERIOD * yearly_mileage) / nonhybrid_efficiency;
	double total_fuel_cost_nonhybrid = total_fuel_consumption_nonhybrid * gas_price_estimate;
	double depreciation_nonhybrid = initial_nonhybrid_price - resale_value_nonhybrid_estimate;
	double total_nonhybrid_ownership_cost = depreciation_nonhybrid + total_fuel_cost_nonhybrid;

	//Sets precison on the printouts
	cout << fixed << setprecision(2);

	//If minimizing gas consumption is the buyer's goal, this will print the information for
	// the car with the least fuel consumption first.
	if (gas_or_total == "Gas")
	{
		if (total_fuel_consumption_hybrid < total_fuel_consumption_nonhybrid)
		{
			cout << endl << "Hybrid";
			cout << endl << "Hybrid\'s total fuel consumption:\t " << total_fuel_consumption_hybrid
				<< " gallons of gas";
			cout << endl << "Total cost of owning the hybrid:\t$" << total_hybrid_ownership_cost;
			cout << endl << endl << "Non-Hybrid";
			cout << endl << "Non-Hybrid\'s total fuel consumption:\t "
				<< total_fuel_consumption_nonhybrid << " gallons of gas";
			cout << endl << "Total cost of owning the non-hybrid:\t$"
				<< total_nonhybrid_ownership_cost << endl << endl;
		}
		else
		{
			cout << endl << "Non-Hybrid";
			cout << endl << "Non-Hybrid\'s total fuel consumption:\t "
				<< total_fuel_consumption_nonhybrid << " gallons of gas";
			cout << endl << "Total cost of owning the non-hybrid:\t$" << total_nonhybrid_ownership_cost;
			cout << endl << endl << "Hybrid";
			cout << endl << "Hybrid\'s total fuel consumption:\t " << total_fuel_consumption_hybrid
				<< " gallons of gas";
			cout << endl << "Total cost of owning the hybrid:\t$"
				<< total_hybrid_ownership_cost << endl << endl;
		}
	}

	//If minimizing total ownership cost is the buyer's goal, this will print the
	//information for the car with the least fuel consumption first.
	if (gas_or_total == "Total")
	{
		if (total_hybrid_ownership_cost < total_nonhybrid_ownership_cost)
		{
			cout << endl << "Hybrid";
			cout << endl << "Hybrid\'s total fuel consumption:\t " << total_fuel_consumption_hybrid
				<< " gallons of gas";
			cout << endl << "Total cost of owning the hybrid:\t$" << total_hybrid_ownership_cost;
			cout << endl << endl << "Non-Hybrid";
			cout << endl << "Non-Hybrid\'s total fuel consumption:\t "
				<< total_fuel_consumption_nonhybrid << " gallons of gas";
			cout << endl << "Total cost of owning the non-hybrid:\t$"
				<< total_nonhybrid_ownership_cost << endl << endl;
		}
		else
		{
			cout << endl << "Non-Hybrid";
			cout << endl << "Non-Hybrid\'s total fuel consumption:\t " << total_fuel_consumption_nonhybrid
				<< " gallons of gas";
			cout << endl << "Total cost of owning the non-hybrid:\t$" << total_nonhybrid_ownership_cost;
			cout << endl << endl << "Hybrid";
			cout << endl << "Hybrid\'s total fuel consumption:\t " << total_fuel_consumption_hybrid
				<< " gallons of gas";
			cout << endl << "Total cost of owning the hybrid:\t$" << total_hybrid_ownership_cost
				<< endl << endl;
		}
	}



	system("pause");
	return 0;
}