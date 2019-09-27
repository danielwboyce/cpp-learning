// 04 -- Plinko with Functions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Expand for test cases!
/**
-------------------------------------TEST CASE 1-------------------------------------
Welcome to Plinko!

MENU: Please select one of the following options:
1 - Drop a single chip into one slot
2 - Drop multiple chips into one slot
3 - Drop multiple chips into each slot
4 - Quit the program
Enter your selection now: ahoy
INVALID SELECTION. Please enter 1, 2, 3, or 4

MENU: Please select one of the following options:
1 - Drop a single chip into one slot
2 - Drop multiple chips into one slot
3 - Drop multiple chips into each slot
4 - Quit the program
Enter your selection now: 0
INVALID SELECTION. Please enter 1, 2, 3, or 4

MENU: Please select one of the following options:
1 - Drop a single chip into one slot
2 - Drop multiple chips into one slot
3 - Drop multiple chips into each slot
4 - Quit the program
Enter your selection now: -1
INVALID SELECTION. Please enter 1, 2, 3, or 4

MENU: Please select one of the following options:
1 - Drop a single chip into one slot
2 - Drop multiple chips into one slot
3 - Drop multiple chips into each slot
4 - Quit the program
Enter your selection now: 5
INVALID SELECTION. Please enter 1, 2, 3, or 4

MENU: Please select one of the following options:
1 - Drop a single chip into one slot
2 - Drop multiple chips into one slot
3 - Drop multiple chips into each slot
4 - Quit the program
Enter your selection now: 1

*** DROP SINGLE CHIP ***
Which slot do you want to drop the chip in (0-8)? hey
INVALID SLOT.

MENU: Please select one of the following options:
1 - Drop a single chip into one slot
2 - Drop multiple chips into one slot
3 - Drop multiple chips into each slot
4 - Quit the program
Enter your selection now: 1

*** DROP SINGLE CHIP ***
Which slot do you want to drop the chip in (0-8)? -1
INVALID SLOT.

MENU: Please select one of the following options:
1 - Drop a single chip into one slot
2 - Drop multiple chips into one slot
3 - Drop multiple chips into each slot
4 - Quit the program
Enter your selection now: 1

*** DROP SINGLE CHIP ***
Which slot do you want to drop the chip in (0-8)? 9
INVALID SLOT.

MENU: Please select one of the following options:
1 - Drop a single chip into one slot
2 - Drop multiple chips into one slot
3 - Drop multiple chips into each slot
4 - Quit the program
Enter your selection now: 1

*** DROP SINGLE CHIP ***
Which slot do you want to drop the chip in (0-8)? 5

*** DROPPING CHIP INTO SLOT 5 ***
PATH: [5.0 4.5 5.0 5.5 6.0 5.5 6.0 5.5 6.0 6.5 7.0 7.5 7.0]
WINNINGS: $500.00

MENU: Please select one of the following options:
1 - Drop a single chip into one slot
2 - Drop multiple chips into one slot
3 - Drop multiple chips into each slot
4 - Quit the program
Enter your selection now: 4
GOODBYE!

-------------------------------------TEST CASE 2-------------------------------------
Welcome to Plinko!

MENU: Please select one of the following options:
1 - Drop a single chip into one slot
2 - Drop multiple chips into one slot
3 - Drop multiple chips into each slot
4 - Quit the program
Enter your selection now: 2

*** DROP MULTIPLE CHIPS ***
How many chips do you want to drop (>0)? potato
INVALID NUMBER OF CHIPS.

MENU: Please select one of the following options:
1 - Drop a single chip into one slot
2 - Drop multiple chips into one slot
3 - Drop multiple chips into each slot
4 - Quit the program
Enter your selection now: 2

*** DROP MULTIPLE CHIPS ***
How many chips do you want to drop (>0)? -1
INVALID NUMBER OF CHIPS.

MENU: Please select one of the following options:
1 - Drop a single chip into one slot
2 - Drop multiple chips into one slot
3 - Drop multiple chips into each slot
4 - Quit the program
Enter your selection now: 2

*** DROP MULTIPLE CHIPS ***
How many chips do you want to drop (>0)? 0
INVALID NUMBER OF CHIPS.

MENU: Please select one of the following options:
1 - Drop a single chip into one slot
2 - Drop multiple chips into one slot
3 - Drop multiple chips into each slot
4 - Quit the program
Enter your selection now: 2

*** DROP MULTIPLE CHIPS ***
How many chips do you want to drop (>0)? 10
Which slot do you want to drop the chips in (0-8)? test
INVALID SLOT.

MENU: Please select one of the following options:
1 - Drop a single chip into one slot
2 - Drop multiple chips into one slot
3 - Drop multiple chips into each slot
4 - Quit the program
Enter your selection now: 2

*** DROP MULTIPLE CHIPS ***
How many chips do you want to drop (>0)? 10
Which slot do you want to drop the chips in (0-8)? -1
INVALID SLOT.

MENU: Please select one of the following options:
1 - Drop a single chip into one slot
2 - Drop multiple chips into one slot
3 - Drop multiple chips into each slot
4 - Quit the program
Enter your selection now: 2

*** DROP MULTIPLE CHIPS ***
How many chips do you want to drop (>0)? 10
Which slot do you want to drop the chips in (0-8)? 9
INVALID SLOT.

MENU: Please select one of the following options:
1 - Drop a single chip into one slot
2 - Drop multiple chips into one slot
3 - Drop multiple chips into each slot
4 - Quit the program
Enter your selection now: 2

*** DROP MULTIPLE CHIPS ***
How many chips do you want to drop (>0)? 10
Which slot do you want to drop the chips in (0-8)? 5

*** DROPPING CHIP INTO SLOT 5 ***
Total Winnings on 10 chips: $14100
Average winnings per chip: $1410

MENU: Please select one of the following options:
1 - Drop a single chip into one slot
2 - Drop multiple chips into one slot
3 - Drop multiple chips into each slot
4 - Quit the program
Enter your selection now: 4
GOODBYE!

-------------------------------------TEST CASE 3-------------------------------------
Welcome to Plinko!

MENU: Please select one of the following options:
1 - Drop a single chip into one slot
2 - Drop multiple chips into one slot
3 - Drop multiple chips into each slot
4 - Quit the program
Enter your selection now: 3

*** DROP MULTIPLE CHIPS INTO EVERY SLOT ***
How many chips do you want to drop into every slot (>0)? no
INVALID NUMBER OF CHIPS.

MENU: Please select one of the following options:
1 - Drop a single chip into one slot
2 - Drop multiple chips into one slot
3 - Drop multiple chips into each slot
4 - Quit the program
Enter your selection now: 3

*** DROP MULTIPLE CHIPS INTO EVERY SLOT ***
How many chips do you want to drop into every slot (>0)? -10000
INVALID NUMBER OF CHIPS.

MENU: Please select one of the following options:
1 - Drop a single chip into one slot
2 - Drop multiple chips into one slot
3 - Drop multiple chips into each slot
4 - Quit the program
Enter your selection now: 3

*** DROP MULTIPLE CHIPS INTO EVERY SLOT ***
How many chips do you want to drop into every slot (>0)? 0
INVALID NUMBER OF CHIPS.

MENU: Please select one of the following options:
1 - Drop a single chip into one slot
2 - Drop multiple chips into one slot
3 - Drop multiple chips into each slot
4 - Quit the program
Enter your selection now: 3

*** DROP MULTIPLE CHIPS INTO EVERY SLOT ***
How many chips do you want to drop into every slot (>0)? 100000

*** DROPPING 100000 CHIPS INTO EVERY SLOT ***

*** WINNINGS FROM SLOT 0 DROP ***
Total Winnings on 100000 chips: $7.75745e+007
Average winnings per chip: $775.745

*** WINNINGS FROM SLOT 1 DROP ***
Total Winnings on 100000 chips: $1.02933e+008
Average winnings per chip: $1029.33

*** WINNINGS FROM SLOT 2 DROP ***
Total Winnings on 100000 chips: $1.5885e+008
Average winnings per chip: $1588.5

*** WINNINGS FROM SLOT 3 DROP ***
Total Winnings on 100000 chips: $2.26418e+008
Average winnings per chip: $2264.18

*** WINNINGS FROM SLOT 4 DROP ***
Total Winnings on 100000 chips: $2.56328e+008
Average winnings per chip: $2563.28

*** WINNINGS FROM SLOT 5 DROP ***
Total Winnings on 100000 chips: $2.26655e+008
Average winnings per chip: $2266.55

*** WINNINGS FROM SLOT 6 DROP ***
Total Winnings on 100000 chips: $1.59301e+008
Average winnings per chip: $1593.01

*** WINNINGS FROM SLOT 7 DROP ***
Total Winnings on 100000 chips: $1.03028e+008
Average winnings per chip: $1030.28

*** WINNINGS FROM SLOT 8 DROP ***
Total Winnings on 100000 chips: $7.74378e+007
Average winnings per chip: $774.378


MENU: Please select one of the following options:
1 - Drop a single chip into one slot
2 - Drop multiple chips into one slot
3 - Drop multiple chips into each slot
4 - Quit the program
Enter your selection now: 4
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
const int MULT_CHIPS_MULT_SLOTS_SIGNAL = 3;
const int END_PROGRAM_INPUT_SIGNAL = 4;


/**
This function prints the main menu.
*/

void main_menu()
{
	cout << "MENU: Please select one of the following options:" << endl
		<< " 1 - Drop a single chip into one slot" << endl
		<< " 2 - Drop multiple chips into one slot" << endl
		<< " 3 - Drop multiple chips into each slot" << endl
		<< " 4 - Quit the program" << endl
		<< "Enter your selection now: ";
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

/**
This function moves the chip along once.
@refparameter position is the position of the chip before the iteration of the function.
*/
void single_chip_advance(double& position)
{
	int random_number_one_or_two = rand() % TWO_OPTIONS;
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
This function takes the original position of a single chip and records its final position after dropping through the entire board.
@parameter starting_slot Is the original into which the chip is dropped.
@return final_slot Is the slot into which the chip falls after falling through the whole board.
*/
double single_chip_final_position(double starting_slot)
{
	for (int how_far_fallen = 1; how_far_fallen <= BOARD_LENGTH; how_far_fallen++)
	{
		single_chip_advance(starting_slot);
	}
	double final_slot = starting_slot;
	return final_slot;
}

/**
This function takes which slot multiple chips will be dropped into and how many chips will be dropped and returns the total winnings.
@parameter starting_slot Is the original slot into which the chip is dropped
@parameter how_many_chips Is the number of chips which will be dropped
@return total_winnings is the amount of winnings that will be gained total.
*/
void multi_chip_drop_winnings(double starting_slot, int how_many_chips)
{
	double total_winnings = 0;
	double multi_chip_starter = 0;
	for (int which_chip_counter = 1; which_chip_counter <= how_many_chips;
		which_chip_counter++)
	{
		multi_chip_starter = starting_slot;
		double multi_chip_final = single_chip_final_position(multi_chip_starter);

		total_winnings = total_winnings + chip_winnings(multi_chip_final);
	}
	cout << endl << "Total Winnings on " << how_many_chips << " chips: $"
		<< total_winnings;
	cout << endl << "Average winnings per chip: $" << total_winnings / how_many_chips
		<< endl;
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
		if (cin.fail())
		{
			cin.clear();
			cin.sync();
		}

		// For the end program menu option
		if (user_input == END_PROGRAM_INPUT_SIGNAL)
		{
			break;
		}

		// For the single chip menu option
		else if (user_input == ONE_CHIP_INPUT_SIGNAL)
		{
			double chip_position = 0;
			cout << endl << "*** DROP SINGLE CHIP ***" << endl
				<< "Which slot do you want to drop the chip in (0-8)\? ";
			cin >> chip_position;
			if (cin.fail())
			{
				cin.clear();
				cin.sync();
				cout << "INVALID SLOT." << endl;
			}
			else if (chip_position >= SLOT_0_POSITION && chip_position <= SLOT_8_POSITION)
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


		// For the multiple chip menu option
		else if (user_input == MULT_CHIPS_INPUT_SIGNAL)
		{
			int how_many_dropped_chips = 0;
			cout << endl << "*** DROP MULTIPLE CHIPS ***" << endl
				<< "How many chips do you want to drop (>0)\? ";
			cin >> how_many_dropped_chips;
			if (cin.fail())
			{
				cin.clear();
				cin.sync();
				cout << "INVALID NUMBER OF CHIPS." << endl;
			}
			else if (how_many_dropped_chips > 0)
			{
				double multiple_chips_starting_slot = 0;
				cout << "Which slot do you want to drop the chips in (0-8)\? ";
				cin >> multiple_chips_starting_slot;
				if (cin.fail())
				{
					cin.clear();
					cin.sync();
					cout << "INVALID SLOT." << endl;
				}
				else if (multiple_chips_starting_slot >= SLOT_0_POSITION && multiple_chips_starting_slot <= SLOT_8_POSITION)
				{
					cout << endl << "*** DROPPING CHIP INTO SLOT " << multiple_chips_starting_slot << " ***";
					multi_chip_drop_winnings(multiple_chips_starting_slot, how_many_dropped_chips);
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

		//For the multiple chips into every slot menu option
		else if (user_input == MULT_CHIPS_MULT_SLOTS_SIGNAL)
		{
			int all_slots_drop_count = 0;
			cout << endl << "*** DROP MULTIPLE CHIPS INTO EVERY SLOT ***" << endl
				<< "How many chips do you want to drop into every slot (>0)\? ";
			cin >> all_slots_drop_count;
			if (cin.fail())
			{
				cin.clear();
				cin.sync();
				cout << "INVALID NUMBER OF CHIPS." << endl;
			}
			else if (all_slots_drop_count > 0)
			{
				cout << endl << "*** DROPPING " << all_slots_drop_count << " CHIPS INTO EVERY SLOT ***" << endl << endl;
				for (double which_slot = SLOT_0_POSITION; which_slot <= SLOT_8_POSITION; which_slot++)
				{
					cout << "*** WINNINGS FROM SLOT " << which_slot << " DROP ***";
					multi_chip_drop_winnings(which_slot, all_slots_drop_count);
					cout << endl;
				}
			}
			else
			{
				cout << "INVALID NUMBER OF CHIPS." << endl;
			}
		}

		else
		{
			cout << "INVALID SELECTION. Please enter 1, 2, 3, or 4" << endl;
		}

	} while (user_input != END_PROGRAM_INPUT_SIGNAL);

	cout << "GOODBYE!" << endl << endl;
	system("pause");
	return 0;

}