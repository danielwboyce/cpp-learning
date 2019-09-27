// 07 -- Cars.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Car.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <istream>
#include <ostream>

using namespace std;

const string SHOW_INV_COMMAND = "1";
const string SHOW_BALANCE_COMMAND = "2";
const string BUY_CAR_COMMAND = "3";
const string SELL_CAR_COMMAND = "4";
const string PAINT_CAR_COMMAND = "5";
const string LOAD_FILE_COMMAND = "6";
const string SAVE_FILE_COMMAND = "7";
const string QUIT_COMMAND = "8";

const int NOT_FOUND_INDEX = -1;

/**
This function prints the main menu.
*/
void main_menu()
{
	cout << "MENU: Please select one of the following options:" << endl << endl
		<< " 1 - Show current inventory." << endl
		<< " 2 - Show current balance." << endl
		<< " 3 - Buy a car." << endl
		<< " 4 - Sell a car." << endl
		<< " 5 - Paint a car." << endl
		<< " 6 - Load file." << endl
		<< " 7 - Save file." << endl
		<< " 8 - Quit program." << endl << endl
		<< "Enter your selection now: ";

	return;
}

/**
This function displays the complete inventory to the console
@parameter vector<Car> inventory Is the vector storing Car objects as the inventory
*/
void display_inventory(vector<Car> inventory)
{
	if (inventory.size() == 0)
	{
		cout << endl << "Inventory Empty" << endl;
	}
	else
	{
		for (int i = 0; i < inventory.size(); i++)
		{
			cout << endl << (inventory[i]).toString();
		}
	}

	return;
}

/**
This function couts the dealership's balance.
@parameter double balance Is the dealership's balance.
*/
void print_balance(double balance)
{
	cout << endl << "Your balance is $" << fixed << setprecision(2)
		<< balance << endl;

	return;
}

/**
This function searches for a matched car name in the list of cars
@parameter vector<Car> inventory Is the list of cars in the inventory
@parameter string desired_car_name Is the name of the car you are looking for
@return int index_saver Is the index of the Car with the same name as the inputted name.
*/
int find_car_name(vector<Car> inventory, string desired_car_name)
{
	int index_saver = NOT_FOUND_INDEX;
	int inventory_size = inventory.size();
	for (int i = 0; i < inventory_size; i++)
	{
		if (desired_car_name == (inventory[i]).getName())
		{
			index_saver = i;
		}
	}

	return index_saver;
}

/**
This function prompts the user to enter the name, color, and price
of a new car to be purchased and added to the inventory.
@parameter vector<Car>& inventory Is the list of cars in the inventory
@parameter double& dealership_balance Is the balance of the dealership
*/
void buy_car(vector<Car>& inventory, double& dealership_balance)
{
	string new_car_name;
	string new_car_color;
	double new_car_price = 0;

	cout << endl << "Please enter the name, color, and price of the new car." << endl;

	cout << "Name: ";
	cin.sync();
	getline(cin, new_car_name);

	cout << "Color: ";
	cin.sync();
	getline(cin, new_car_color);

	cout << "Price: ";
	cin >> new_car_price;
	if (cin.fail())
	{
		cin.clear();
		cin.sync();
	}

	//If the car was already found in the inventory
	if (find_car_name(inventory, new_car_name) != NOT_FOUND_INDEX)
	{
		cout << endl << "You already own the same kind of car! Car not purchased." << endl;
	}
	//If the car is too expensive
	else if (new_car_price > dealership_balance)
	{
		cout << endl << "You can't afford this car!" << endl;
	}
	else
	{
		Car new_car = Car(new_car_name, new_car_color, new_car_price);
		inventory.push_back(new_car);
		dealership_balance = dealership_balance - new_car_price;
		cout << endl << "The " << new_car_name << " was purchased!" << endl;
	}

	return;
}

/**
This function prompts the user to enter the name of a car to be sold and removed from
the inventory, if we have it.
@parameter vector<Car>& inventory Is the list of cars in the inventory
@parameter double& dealership_balance Is the balance of the dealership
*/
void sell_car(vector<Car>& inventory, double& dealership_balance)
{
	if (inventory.size() > 0)
	{

		string selling_car_name;

		cout << endl << "Please enter the name of the car to be sold." << endl;

		cout << "Name: ";
		cin.sync();
		getline(cin, selling_car_name);

		//Index of the car we want to sell in the inventory vector
		int car_index = find_car_name(inventory, selling_car_name);

		//If the car was not found in the inventory
		if (car_index == NOT_FOUND_INDEX)
		{
			cout << endl << "You don't own that kind of car!" << endl;
		}
		else
		{
			//Update the balance first, before we move the vector all around.
			dealership_balance = dealership_balance + inventory[car_index].getPrice();

			//Overwrites every index starting at the index containing the car to be sold
			//with the data for the car immediately following it in the vector.
			int inventory_size = inventory.size();
			for (int i = car_index + 1; i < inventory_size; i++)
			{
				inventory[i - 1] = inventory[i];
			}
			inventory.pop_back();
			cout << endl << "The " << selling_car_name << " was sold!" << endl;
		}
	}
	else
	{
		cout << endl << "You don't have any cars to sell!" << endl;
	}

	return;
}

/**
This function prompts the user to enter the name of a car to be painted, and paints
it, if we have it.
@parameter vector<Car>& inventory Is the list of cars in the inventory
*/
void paint_car(vector<Car>& inventory)
{
	if (inventory.size() > 0)
	{

		string car_to_be_painted;

		cout << endl << "Please enter the name of the car that you'd like to paint."
			<< endl << "Name: ";

		cin.sync();
		getline(cin, car_to_be_painted);

		//Index of the car we want to paint, if it's found.
		int car_index = find_car_name(inventory, car_to_be_painted);

		//If the car was not found in the inventory
		if (car_index == NOT_FOUND_INDEX)
		{
			cout << endl << "You don't own that kind of car!" << endl;
		}
		else
		{
			string new_paint_color;

			cout << "Please enter the color that you'd like to paint this car."
				<< endl << "Color: ";

			cin.sync();
			getline(cin, new_paint_color);

			//Paints it if the new color is different from the current color
			if (new_paint_color != inventory[car_index].getColor())
			{
				inventory[car_index].paint(new_paint_color);
				cout << endl << "The " << car_to_be_painted << " was painted " << new_paint_color
					<< "! Its value increased by $1000." << endl;
			}
			else
			{
				cout << endl << "The " << car_to_be_painted
					<< " is already " << new_paint_color << "." << endl;
			}
		}
	}
	else
	{
		cout << endl << "You don't have any cars to paint!" << endl;
	}

	return;
}

/**
This function loads the balance and inventory  from a .txt file
@parameter vector<Car>& inventory Is the list of cars in the inventory
@parameter double& dealership_balance Is the balance of the dealership
*/
void load_file(vector<Car>& inventory, double& dealership_balance)
{
	string filename;

	cout << endl << "Please enter the name of the file that you would like to load. "
		<< "Please do not include \".txt\" in the file name." << endl << "File name: ";

	cin.sync();
	getline(cin, filename);

	ifstream in_file;
	in_file.open(filename + ".txt");
	if (!in_file.fail())
	{
		in_file >> dealership_balance;
		while (in_file)
		{
			string in_name;
			string in_color;
			double in_price = 0;

			in_file >> in_name >> in_color >> in_price;
			Car newCar = Car(in_name, in_color, in_price);
			inventory.push_back(newCar);
		}
		inventory.pop_back();
		cout << endl << "File " << filename << ".txt loaded!" << endl;
	}
	else
	{
		cout << endl << "File " << filename << ".txt failed to load. :(" << endl;
	}
}

/**
This function saves the balance and inventory into a .txt file
@parameter vector<Car> inventory Is the list of cars in the inventory
@parameter double dealership_balance Is the balance of the dealership
*/

void save_file(vector<Car> inventory, double dealership_balance)
{
	string file_name;

	cout << endl << "Please enter the name of the file that you would like to create. "
		<< "Please do not include \".txt\" in the file name." << endl << "File name: ";

	cin.sync();
	getline(cin, file_name);

	ofstream out_file;
	out_file.open(file_name + ".txt");
	if (!out_file.fail())
	{
		out_file << dealership_balance << endl;
		for (int i = 0; i < inventory.size(); i++)
		{
			out_file << inventory[i].getName() << " " << inventory[i].getColor() << " "
				<< inventory[i].getPrice() << endl;
		}
		out_file.close();

		cout << endl << "File " << file_name << ".txt saved!" << endl;
	}
	else
	{
		cout << endl << "File " << file_name << ".txt failed to save. :(" << endl;
	}

	return;
}

int main()
{
	double dealership_balance = 10000.00;

	vector<Car> inventory;

	string user_input;

	do
	{
		cout << endl;
		main_menu();
		cin.sync();
		getline(cin, user_input);

		//Car tardis = Car("TARDIS", "TARDIS blue", 20000);
		//inventory.push_back(tardis);

		//Car mustang = Car("Mustang", "Cherry red", 28000);
		//inventory.push_back(mustang);

		if (user_input == SHOW_INV_COMMAND)
		{
			display_inventory(inventory);
		}

		else if (user_input == SHOW_BALANCE_COMMAND)
		{
			print_balance(dealership_balance);
		}

		else if (user_input == BUY_CAR_COMMAND)
		{
			buy_car(inventory, dealership_balance);
		}

		else if (user_input == SELL_CAR_COMMAND)
		{
			sell_car(inventory, dealership_balance);
		}

		else if (user_input == PAINT_CAR_COMMAND)
		{
			paint_car(inventory);
		}

		else if (user_input == LOAD_FILE_COMMAND)
		{
			load_file(inventory, dealership_balance);
		}

		else if (user_input == SAVE_FILE_COMMAND)
		{
			save_file(inventory, dealership_balance);
		}

		else if (user_input == QUIT_COMMAND)
		{
			break;
		}

		else
		{
			cout << "Invalid selection. Please enter 1, 2, 3, 4, 5, 6, 7, or 8 "
				<< "to signify your choice." << endl;
		}

	} while (user_input != QUIT_COMMAND);

	cout << endl << endl << "GOODBYE!" << endl << endl;
	system("pause");

	return 0;
}