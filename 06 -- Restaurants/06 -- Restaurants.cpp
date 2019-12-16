// 06 -- Restaurants.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

#include <vector>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <istream>
using namespace std;


const string DISPLAY_ALL_SIGNAL = "1";
const string ADD_RESTAURANT_SIGNAL = "2";
const string REMOVE_RESTAURANT_SIGNAL = "3";
const string SHUFFLE_VECTOR_SIGNAL = "4";
const string BEGIN_TOURNAMENT_SIGNAL = "5";
const string QUIT_PROGRAM_SIGNAL = "6";

/**
This function prints the main menu.
*/
void main_menu()
{
	cout << "MENU: Please select one of the following options:" << endl << endl
		<< " 1 - Display all restaurants" << endl
		<< " 2 - Add a restaurant" << endl
		<< " 3 - Remove a restaurant" << endl
		<< " 4 - Shuffle the vector" << endl
		<< " 5 - Begin the tournament" << endl
		<< " 6 - Quit the program" << endl << endl
		<< "Enter your selection now: ";
}

/**
This function prints all of the restaurants in the vector.
@parameter vector<string> list Is the list of restaurants.
*/
void print_list(vector<string> list)
{
	cout << endl;
	int list_size = list.size();
	for (int i = 0; i < list_size; i++)
	{
		cout << list[i];
		if (i < list_size - 1)
		{
			cout << ", ";
		}
	}
	cout << endl;
}

/**
This function searches for given restaurant in the list of restaurants
@parameter vector<string> list Is the list of restaurants
@parameter string desired_restaurant Is the name of the restaurant you are looking for
*/
int find_restaurant_name(vector<string> list, string desired_restaurant)
{
	int index_saver = -1;
	int list_size = list.size();
	for (int i = 0; i < list_size; i++)
	{
		if (desired_restaurant == list[i])
		{
			index_saver = i;
		}
	}

	return index_saver;
}

/**
This function prompts the user for the name of a restaurant they wish to add to
the list and adds it to the vector, if it wasn't already there.
@parameter vector<string>& list Is the list of restaurants
*/
void add_restaurant(vector<string>& list)
{
	string new_restaurant;
	cout << endl << "Please enter the name of the restaurant that you wish to add: ";
	cin.sync();
	getline(cin, new_restaurant);
	int restaurant_index = find_restaurant_name(list, new_restaurant);
	if (restaurant_index == -1)
	{
		cout << "The restaurant was added to the list." << endl;
		list.push_back(new_restaurant);
	}
	if (restaurant_index >= 0)
	{
		cout << "The restaurant was already in the list. It was not added again."
			<< endl;
	}
}

/**
This function prompts the user for the name of a restaurant they wish to remove
the list and removes it from the vector, if it's there
@parameter vector<string>& list Is the list of restaurants
*/
void remove_restaurant(vector<string>& list)
{
	string restaurant_to_be_deleted;
	cout << endl << "Please enter the name of the restaurant that you wish to delete: ";
	cin.sync();
	getline(cin, restaurant_to_be_deleted);
	int restaurant_index = find_restaurant_name(list, restaurant_to_be_deleted);
	if (restaurant_index == -1)
	{
		cout << "The restaurant was not found in the list. It was therefore not deleted." << endl;
	}
	if (restaurant_index >= 0)
	{
		int list_size = list.size();
		for (int i = restaurant_index + 1; i < list_size; i++)
		{
			list[i - 1] = list[i];
		}
		list.pop_back();
		cout << "The restaurant was removed from the list." << endl;
	}
}

/**
This function shuffles the restaurant list
@parameter vector<string>& list Is the restaurant list
*/
void shuffle_list(vector<string>& list)
{
	int list_size = list.size();
	// Make a copy of the list
	vector<string> copied_list;
	for (int i = 0; i < list_size; i++)
	{
		copied_list.push_back(list[i]);
	}

	for (int i = 0; i < list_size; i++)
	{
		// Get a random number j between i and the last index of the copied list
		int j = rand() % copied_list.size();
		// Take the element from the randomly selected position of the copied array
		// and save it at position i of the actual list
		list[i] = copied_list[j];
		// Remove the copied away element from the copied list.
		copied_list[j] = copied_list[copied_list.size() - 1];
		copied_list.pop_back();
	}
	cout << "The list has been shuffled." << endl;
}

/**
This function checks to see if the number of restaurants is a power of 2
@parameter vector<string> list Is the list of restaurants
*/
bool restaurant_power_of_2_check(vector<string> list)
{
	bool check = false;
	for (int i = 1; pow(2, i) <= list.size(); i++)
	{
		if (pow(2, i) == list.size())
		{
			check = true;
		}
	}
	return check;
}

/**
This function runs the tournament for one round
@parameter vector<string>& list Is the list of contesting restaurants
*/
void tournament(vector<string>& list)
{
	int number_of_rounds = log2(list.size());
	for (int round = 0; round < number_of_rounds; round++)
	{
		int number_of_matches = list.size() / 2;
		for (int match = 0; match < number_of_matches; match++)
		{
			string input;
			cout << "Match " << match + 1 << "/" << number_of_matches << ", "
				<< "Round " << round + 1 << "/" << number_of_rounds << " --- "
				<< "Enter 1 for " << list[match] << " or 2 for " << list[match + 1]
				<< ": ";
			cin.sync();
			getline(cin, input);
			while (input != "1" && input != "2")
			{
				cout << "Invalid response (" << input << ")" << endl;
				cout << "Match " << match + 1 << "/" << number_of_matches << ", "
					<< "Round " << round + 1 << "/" << number_of_rounds << " --- "
					<< "Enter 1 for " << list[match] << " or 2 for " << list[match + 1]
					<< ": ";
				cin.sync();
				getline(cin, input);
			}
			if (input == "1")
			{
				int index = match + 1;
				for (int j = index + 1; j < list.size(); j++)
				{
					list[j - 1] = list[j];
				}
				list.pop_back();
			}
			else if (input == "2")
			{
				int index = match + 0;
				for (int i = index + 1; i < list.size(); i++)
				{
					list[i - 1] = list[i];
				}
				list.pop_back();
			}
		}
	}
	cout << endl << "The winner is " << list[0] << "!" << endl << endl;
}

int main()
{
	//This initializes our list of restaurants
	vector<string> restaurant_list(0);
	restaurant_list.push_back("Wendy's");
	restaurant_list.push_back("Subway");
	restaurant_list.push_back("Taco Bell");
	restaurant_list.push_back("Baja Fresh");
	restaurant_list.push_back("Tito's Tacos");
	restaurant_list.push_back("Establo's Meat Market");
	restaurant_list.push_back("McDonald's");
	restaurant_list.push_back("Sizzler");

	srand(time(NULL));

	string user_input;
	do
	{
		cout << endl;
		main_menu();
		cin.sync();
		getline(cin, user_input);

		// For the end program menu option
		if (user_input == QUIT_PROGRAM_SIGNAL)
		{
			break;
		}

		// For the print all restaurants menu option
		else if (user_input == DISPLAY_ALL_SIGNAL)
		{
			print_list(restaurant_list);
		}

		// For the add a restaurant menu option
		else if (user_input == ADD_RESTAURANT_SIGNAL)
		{
			add_restaurant(restaurant_list);
		}

		// For the remove a restaurant menu option
		else if (user_input == REMOVE_RESTAURANT_SIGNAL)
		{
			remove_restaurant(restaurant_list);
		}

		// For the shuffle the vector menu option
		else if (user_input == SHUFFLE_VECTOR_SIGNAL)
		{
			shuffle_list(restaurant_list);
		}

		// For the begin tournament menu option
		else if (user_input == BEGIN_TOURNAMENT_SIGNAL)
		{
			if (restaurant_power_of_2_check(restaurant_list))
			{
				tournament(restaurant_list);

				break;
			}
			else
			{
				cout << "The number of restaurants must be equal a power of two. "
					<< "Please add or remove restaurants to comply." << endl;
			}
		}

		else
		{
			cout << "Invalid selection. Please enter 1, 2, 3, 4, 5, or 6 "
				<< "to signify your choice." << endl;
		}
	} while (user_input != QUIT_PROGRAM_SIGNAL);

	cout << endl << "GOODBYE!" << endl << endl;
	system("pause");
	return 0;
}