// 03 -- Plinko.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Expand for test cases!
/**
-------------------------------------TEST CASE 1-------------------------------------
MENU: Please select one of the following options:
1 - Drop a single chip into one slot
2 - Drop multiple chips into one slot
3 - Quit the program
Enter your selection now: 0
INVALID SELECTION.  Please enter 1, 2 or 3

MENU: Please select one of the following options:
1 - Drop a single chip into one slot
2 - Drop multiple chips into one slot
3 - Quit the program
Enter your selection now: 1

*** DROP SINGLE CHIP ***
Which slot do you want to drop the chip in (0-8)? 1000
INVALID SLOT.

MENU: Please select one of the following options:
1 - Drop a single chip into one slot
2 - Drop multiple chips into one slot
3 - Quit the program
Enter your selection now: 1

Which slot do you want to drop the chip in (0-8)? 4

*** DROPPING CHIP INTO SLOT 4 ***
PATH: [4.0 4.5 5.0 6.5 7.0 6.5 6.0 6.5 6.0 5.5 5.0 5.5 6.0]
WINNINGS: $1000.00

MENU: Please select one of the following options:
1 - Drop a single chip into one slot
2 - Drop multiple chips into one slot
3 - Quit the program
Enter your selection now: 3
GOODBYE!

-------------------------------------TEST CASE 2-------------------------------------
MENU: Please select one of the following options:
1 - Drop a single chip into one slot
2 - Drop multiple chips into one slot
3 - Quit the program
Enter your selection now: -1
INVALID SELECTION.  Please enter 1, 2 or 3

MENU: Please select one of the following options:
1 - Drop a single chip into one slot
2 - Drop multiple chips into one slot
3 - Quit the program
Enter your selection now: 2

*** DROP MULTIPLE CHIPS ***
How many chips do you want to drop (>0)? 0
INVALID NUMBER OF CHIPS.

MENU: Please select one of the following options:
1 - Drop a single chip into one slot
2 - Drop multiple chips into one slot
3 - Quit the program
Enter your selection now: 2

*** DROP MULTIPLE CHIPS ***
How many chips do you want to drop (>0)? -5
INVALID NUMBER OF CHIPS.

MENU: Please select one of the following options:
1 - Drop a single chip into one slot
2 - Drop multiple chips into one slot
3 - Quit the program
Enter your selection now: 2

How many chips do you want to drop (>0)? 142
Which slot do you want to drop the chip in (0-8)? -1
INVALID SLOT.

MENU: Please select one of the following options:
1 - Drop a single chip into one slot
2 - Drop multiple chips into one slot
3 - Quit the program
Enter your selection now: 2

How many chips do you want to drop (>0)? 142
Which slot do you want to drop the chip in (0-8)? 10
INVALID SLOT.

MENU: Please select one of the following options:
1 - Drop a single chip into one slot
2 - Drop multiple chips into one slot
3 - Quit the program
Enter your selection now: 2

How many chips do you want to drop (>0)? 3
Which slot do you want to drop the chip in (0-8)? 2
Total Winnings on 142 chips: $10500.00
Average winnings per chip:  $3500.00

MENU: Please select one of the following options:
1 - Drop a single chip into one slot
2 - Drop multiple chips into one slot
3 - Quit the program
Enter your selection now: 3
GOODBYE!

-------------------------------------TEST CASE 3-------------------------------------
MENU: Please select one of the following options:
1 - Drop a single chip into one slot
2 - Drop multiple chips into one slot
3 - Quit the program
Enter your selection now: 5
INVALID SELECTION.  Please enter 1, 2 or 3

MENU: Please select one of the following options:
1 - Drop a single chip into one slot
2 - Drop multiple chips into one slot
3 - Quit the program
Enter your selection now: 2

How many chips do you want to drop (>0)? 10
Which slot do you want to drop the chip in (0-8)? 5
Total Winnings on 142 chips: $14100.00
Average winnings per chip:  $1410.00

MENU: Please select one of the following options:
1 - Drop a single chip into one slot
2 - Drop multiple chips into one slot
3 - Quit the program
Enter your selection now: 2

How many chips do you want to drop (>0)? 3
Which slot do you want to drop the chip in (0-8)? 1
Total Winnings on 142 chips: $1000.00
Average winnings per chip:  $333.33

MENU: Please select one of the following options:
1 - Drop a single chip into one slot
2 - Drop multiple chips into one slot
3 - Quit the program
Enter your selection now: 3
GOODBYE!
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

const double SLOT_0_WINNINGS = 100;
const double SLOT_1_WINNINGS = 500;
const double SLOT_2_WINNINGS = 1000;
const double SLOT_3_WINNINGS = 0;
const double SLOT_4_WINNINGS = 10000;
const double SLOT_5_WINNINGS = 0;
const double SLOT_6_WINNINGS = 1000;
const double SLOT_7_WINNINGS = 500;
const double SLOT_8_WINNINGS = 100;

const double SLOT_0_POSITION = 0.0;
const double SLOT_1_POSITION = 1.0;
const double SLOT_2_POSITION = 2.0;
const double SLOT_3_POSITION = 3.0;
const double SLOT_4_POSITION = 4.0;
const double SLOT_5_POSITION = 5.0;
const double SLOT_6_POSITION = 6.0;
const double SLOT_7_POSITION = 7.0;
const double SLOT_8_POSITION = 8.0;

const double CHIP_MOTION_MAGNITUDE = 0.5;
const int BOARD_LENGTH = 12;
const int TWO_OPTIONS = 2;

const int ONE_CHIP_INPUT_SIGNAL = 1;
const int MULT_CHIPS_INPUT_SIGNAL = 2;
const int END_PROGRAM_INPUT_SIGNAL = 3;


/**
This function prints the main menu.
*/

void main_menu()
{
	cout << "MENU: Please select one of the following options:" << endl
		<< " 1 - Drop a single chip into one slot" << endl
		<< " 2 - Drop multiple chips into one slot" << endl
		<< " 3 - Quit the program" << endl
		<< "Enter your selection now: ";
}

/**
This function finds the path for a single chip and prints it as it goes.
@refparameter position is the position of the chip before the iteration of the function.
*/
void single_chip_advance(double& position)
{
	int random_number_one_or_two = rand() % TWO_OPTIONS;
	double chip_position = position;
	//For left (negative) motion of the chip
	if ((random_number_one_or_two) == 0)
	{
		//The chip can't go off the board when it's all the way to the left.
		if (position == 0)
		{
			position = position + CHIP_MOTION_MAGNITUDE;
		}
		//But otherwise it won't break the program for it to move left.
		else
		{
			position = position - CHIP_MOTION_MAGNITUDE;
		}
	}
	//For right (postive) motion of the chip
	else
	{
		//The chip can't go off the board when it's all the way to the right.
		if (position == 8)
		{
			position = position - CHIP_MOTION_MAGNITUDE;
		}
		//But otherwise it won't break the program for it to move left.
		else
		{
			position = position + CHIP_MOTION_MAGNITUDE;
		}
	}
}

/**
This function finds the winnings for each chip.
@parameter final_chip_position Is the slot where the chip ends up
@return winnings Is the total winnings that the player gets for landing in that slot
*/
double chip_winnings(double final_chip_position)
{
	double winnings;
	if (final_chip_position == SLOT_0_POSITION) winnings = SLOT_0_WINNINGS;
	if (final_chip_position == SLOT_1_POSITION) winnings = SLOT_1_WINNINGS;
	if (final_chip_position == SLOT_2_POSITION) winnings = SLOT_2_WINNINGS;
	if (final_chip_position == SLOT_3_POSITION) winnings = SLOT_3_WINNINGS;
	if (final_chip_position == SLOT_4_POSITION) winnings = SLOT_4_WINNINGS;
	if (final_chip_position == SLOT_5_POSITION) winnings = SLOT_5_WINNINGS;
	if (final_chip_position == SLOT_6_POSITION) winnings = SLOT_6_WINNINGS;
	if (final_chip_position == SLOT_7_POSITION) winnings = SLOT_7_WINNINGS;
	if (final_chip_position == SLOT_8_POSITION) winnings = SLOT_8_WINNINGS;

	return winnings;
}



int main()
{
	srand(time(0));

	int user_input = 0;
	cout << "Welcome to Plinko!" << endl;

	do
	{
		user_input = 0;
		cout << endl;
		main_menu();
		cin >> user_input;

		// For the end program input
		if (user_input == END_PROGRAM_INPUT_SIGNAL)
		{
			break;
		}

		// For the single chip input
		else if (user_input == ONE_CHIP_INPUT_SIGNAL)
		{
			double chip_position = 0;
			cout << endl << "*** DROP SINGLE CHIP ***" << endl
				<< "Which slot do you want to drop the chip in (0-8)\? ";
			cin >> chip_position;
			if (chip_position >= 0 && chip_position <= 8)
			{
				cout << endl << "*** DROPPING CHIP INTO SLOT " << chip_position << " ***"
					<< endl << "PATH: [" << fixed << setprecision(1) << chip_position;
				for (int how_far_fallen = 1; how_far_fallen <= BOARD_LENGTH; how_far_fallen++)
				{
					single_chip_advance(chip_position);
					cout << " " << chip_position;
				}
				cout << "]" << endl;
				cout << "WINNINGS: $" << fixed << setprecision(2)
					<< chip_winnings(chip_position) << endl;
			}
			else
			{
				cout << "INVALID SLOT." << endl;
			}

		}


		// For the multiple chip input
		else if (user_input == MULT_CHIPS_INPUT_SIGNAL)
		{
			int how_many_dropped_chips = 0;
			cout << endl << "*** DROP MULTIPLE CHIPS ***" << endl
				<< "How many chips do you want to drop (>0)\? ";
			cin >> how_many_dropped_chips;
			if (how_many_dropped_chips > 0)
			{
				double multiple_chips_starting_slot = 0;
				cout << "Which slot do you want to drop the chips in (0-8)\? ";
				cin >> multiple_chips_starting_slot;
				if (multiple_chips_starting_slot >= 0 && multiple_chips_starting_slot <= 8)
				{
					cout << endl << "*** DROPPING CHIP INTO SLOT " << multiple_chips_starting_slot << " ***";
					double total_winnings = 0;
					double multi_chip_position = 0;
					for (int which_chip_counter = 1; which_chip_counter <= how_many_dropped_chips;
						which_chip_counter++)
					{
						multi_chip_position = multiple_chips_starting_slot;
						for (int how_far_fallen = 1; how_far_fallen <= BOARD_LENGTH;
							how_far_fallen++)
						{
							single_chip_advance(multi_chip_position);
						}

						total_winnings = total_winnings + chip_winnings(multi_chip_position);
					}
					cout << endl << "Total Winnings on " << how_many_dropped_chips << " chips: $"
						<< total_winnings;
					cout << endl << "Average winnings per chip: $" << total_winnings / how_many_dropped_chips
						<< endl;
				}
				else
				{
					cout << "INVALID SLOT." << endl;
				}
			}
			else
			{
				cout << "INVALID NUMBER OF CHIPS." << endl;
			}
		}

		else
		{
			cout << "INVALID SELECTION. Please enter 1, 2 or 3" << endl;
		}

	} while (user_input != END_PROGRAM_INPUT_SIGNAL);

	cout << "GOODBYE!" << endl << endl;
	system("pause");
	return 0;

}
