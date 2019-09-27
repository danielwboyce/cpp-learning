// 01 -- Pizza.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;

/*
Test case values from doing the program by hand:

Test case 1: 1 guest, 0 large pizzas, 0 medium pizzas, 1 small, 113.097 square inches total,
113.097 square inches per person, 20 percent tip, 9 dollars

Test case 2: 19 guests, 2 large pizzas, 1 medium pizzas, 2 small pizzas, 1055.57 square inches total,
55.5565 square inches per person, 30 percent tip, 72 dollars

Test case 3: 300 guests, 42 large pizzas, 2 medium pizzas, 0 small pizzas, 13596.8 square inches total,
45.3227 square inches per person, 15 percent tip, 735 dollars
*/

int main()
{
	//This will record how many guests you have.
	int guests_attending;
	cout << "How many guests will attending the event?" << endl;
	cin >> guests_attending;

	//This will find out how many large pizzas you have to buy.
	const int LARGE_PIZZA_SERVING_SIZE = 7;
	int large_pizzas_to_buy = guests_attending / LARGE_PIZZA_SERVING_SIZE;

	//This will find out how many medium pizzas you have to buy.
	const int MEDIUM_PIZZA_SERVING_SIZE = 3;
	int unfed_after_large_pizzas = guests_attending % LARGE_PIZZA_SERVING_SIZE;
	int medium_pizzas_to_buy = unfed_after_large_pizzas / MEDIUM_PIZZA_SERVING_SIZE;

	//This will find out how many small pizzas you have to buy.
	const int SMALL_PIZZA_SERVING_SIZE = 1;
	int unfed_after_medium_pizzas = unfed_after_large_pizzas % MEDIUM_PIZZA_SERVING_SIZE;
	int small_pizzas_to_buy = unfed_after_medium_pizzas / SMALL_PIZZA_SERVING_SIZE;

	//This will print out how many of each pizza you need.
	cout << endl << "Pizzas you need:" << " " << large_pizzas_to_buy << " large." << endl
		<< "\t\t " << medium_pizzas_to_buy << " medium." << endl
		<< "\t\t " << small_pizzas_to_buy << " small." << endl;

	//This will find the total area of needed pizza (in square inches) and print the results.
	const int DIAMETER_LARGE_PIZZA = 20;
	const int DIAMETER_MEDIUM_PIZZA = 16;
	const int DIAMETER_SMALL_PIZZA = 12;
	//Radius is half the diameter.
	const double RADIUS_LARGE_PIZZA = DIAMETER_LARGE_PIZZA / 2.0;
	const double RADIUS_MEDIUM_PIZZA = DIAMETER_MEDIUM_PIZZA / 2.0;
	const double RADIUS_SMALL_PIZZA = DIAMETER_SMALL_PIZZA / 2.0;
	//Area is pi times the radius squared
	const double PI = 3.14159;
	const double AREA_SINGLE_LARGE_PIZZA = PI * pow(RADIUS_LARGE_PIZZA, 2);
	const double AREA_SINGLE_MEDIUM_PIZZA = PI * pow(RADIUS_MEDIUM_PIZZA, 2);
	const double AREA_SINGLE_SMALL_PIZZA = PI * pow(RADIUS_SMALL_PIZZA, 2);

	double area_total = (large_pizzas_to_buy * AREA_SINGLE_LARGE_PIZZA) +
		(medium_pizzas_to_buy * AREA_SINGLE_MEDIUM_PIZZA) + (small_pizzas_to_buy * AREA_SINGLE_SMALL_PIZZA);
	cout << endl << "You will have " << area_total << " square inches of pizza." << endl;

	//This will find the total area of pizza (in square inches) that each guest can eat and print the results.
	double area_of_pizza_per_quest = area_total / guests_attending;
	cout << "Each guest will have " << area_of_pizza_per_quest << " square inches of pizza." << endl;

	//This will find find the total price (rounded to the nearest dollar) to be paid, including tip.
	const double PRICE_LARGE_PIZZA = 14.68;
	const double PRICE_MEDIUM_PIZZA = 11.48;
	const double PRICE_SMALL_PIZZA = 7.28;
	double tip_rate;
	cout << endl << "What percent tip do you want to give\? (Please enter this as a whole number from 0 to 100.)"
		<< endl;
	cin >> tip_rate;
	double price_larges = large_pizzas_to_buy * PRICE_LARGE_PIZZA;
	double price_mediums = medium_pizzas_to_buy * PRICE_MEDIUM_PIZZA;
	double price_smalls = small_pizzas_to_buy * PRICE_SMALL_PIZZA;
	double price_all_pizzas = price_larges + price_mediums + price_smalls;
	double tip_total = price_all_pizzas * (tip_rate / 100.0);
	double total_price = price_all_pizzas + tip_total;
	int rounded_total_price = total_price + 0.5;

	//This will print the total rounded price.
	cout << endl << "Rounded to the nearest dollar, you'll want to pay $" << rounded_total_price << "." << endl << endl;

	system("pause");
	return 0;
}