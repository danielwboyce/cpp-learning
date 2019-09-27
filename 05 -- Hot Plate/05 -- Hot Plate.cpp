// 05 -- Hot Plate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const int ROWS = 20;
const int COLUMNS = 20;
const int START_ROW_INDEX = 0;
const int END_ROW_INDEX = 19;
const int START_COLUMN_INDEX = 0;
const int END_COLUMN_INDEX = 19;
const double TOLERATED_DIFFERENCE = 0.1;

/**
This function will initialize the hot plate array.
@parameter input[ROWS][COLUMNS] Is the array which will be initialized.
*/
void initialize_array(double input[ROWS][COLUMNS])
{
	//This will initialize the first row of the array.
	input[START_ROW_INDEX][START_COLUMN_INDEX] = 0;
	for (int i = START_COLUMN_INDEX + 1; i <= END_COLUMN_INDEX - 1; i++)
	{
		input[START_ROW_INDEX][i] = 100;
	}
	input[START_ROW_INDEX][END_COLUMN_INDEX] = 0;

	//This will initialize the last row of the array.
	input[END_ROW_INDEX][START_COLUMN_INDEX] = 0;
	for (int i = START_COLUMN_INDEX + 1; i <= END_COLUMN_INDEX - 1; i++)
	{
		input[END_ROW_INDEX][i] = 100;
	}
	input[END_ROW_INDEX][END_COLUMN_INDEX] = 0;

	//This will initialize all other rows
	for (int i = START_ROW_INDEX + 1; i <= END_ROW_INDEX - 1; i++)
	{
		for (int j = START_COLUMN_INDEX; j <= END_COLUMN_INDEX; j++)
		{
			input[i][j] = 0;
		}
	}

	return;
}

/**
This function will save the values from one array into another.
@parameter source[ROWS][COLUMNS] Is the 2D array from which the new array will be copied
@parameter copy[ROWS][COLUMNS] Is the 2D array into which the source array will be copied
*/
void copy_values(double source[ROWS][COLUMNS], double copy[ROWS][COLUMNS])
{
	for (int i = START_COLUMN_INDEX; i <= END_ROW_INDEX; i++)
	{
		for (int j = START_COLUMN_INDEX; j <= END_COLUMN_INDEX; j++)
		{
			copy[i][j] = source[i][j];
		}
	}
}

/**
This function will print a given array with no commas but with no decimas
@parameter input[ROWS][COLUMNS] Is the array to be printed to the console.
*/
void printNoCommasNoDecimals(double input[ROWS][COLUMNS])
{
	for (int i = START_ROW_INDEX; i <= END_ROW_INDEX; i++)
	{
		for (int j = START_COLUMN_INDEX; j <= END_COLUMN_INDEX; j++)
		{
			if (j > START_COLUMN_INDEX)
			{
				cout << " ";
			}
			cout << input[i][j];
		}
		cout << endl;
	}

	return;
}

/**
This function will print a given array with no commas but with decimas
@parameter input[ROWS][COLUMNS] Is the array to be printed to the console.
*/
void printNoCommasWithDecimals(double input[ROWS][COLUMNS])
{
	for (int i = START_ROW_INDEX; i <= END_ROW_INDEX; i++)
	{
		for (int j = START_COLUMN_INDEX; j <= END_COLUMN_INDEX; j++)
		{
			if (j > START_COLUMN_INDEX)
			{
				cout << " ";
			}
			cout << fixed << setprecision(1) << input[i][j];
		}
		cout << endl;
	}

	return;
}

/**
This function will export the given array into a comma separated values file
@parameter input[ROWS][COLUMNS] Is the array to be exported
*/
void csv_array(double input[ROWS][COLUMNS])
{
	ofstream out_file;
	out_file.open("hotplateoutput.csv");
	for (int i = START_ROW_INDEX; i <= END_ROW_INDEX; i++)
	{
		for (int j = START_COLUMN_INDEX; j <= END_COLUMN_INDEX; j++)
		{
			out_file << fixed << setprecision(1) << input[i][j] << ",";
		}
		out_file << endl;
	}
	out_file.close();
}


void printWithCommasAndDecimals(double input[ROWS][COLUMNS])
{
	for (int i = START_ROW_INDEX; i <= END_ROW_INDEX; i++)
	{
		for (int j = START_COLUMN_INDEX; j <= END_COLUMN_INDEX; j++)
		{
			cout << fixed << setprecision(1) << input[i][j] << ",";
		}
		cout << endl;
	}
}

/**
This function will update the plate elements array once.
*/
void update_plate_once(double current_iteration[ROWS][COLUMNS], double new_iteration[ROWS][COLUMNS],
	double& maxDifference)
{
	const double CELLS = 4.0;
	double maxIterationDifference = 0;

	for (int i = START_ROW_INDEX + 1; i <= END_ROW_INDEX - 1; i++)
	{
		for (int j = START_COLUMN_INDEX + 1; j <= END_COLUMN_INDEX - 1; j++)
		{
			double total_temp_surrounding_cells = current_iteration[i - 1][j] +
				current_iteration[i + 1][j] + current_iteration[i][j - 1] +
				current_iteration[i][j + 1];
			new_iteration[i][j] = total_temp_surrounding_cells / CELLS;
			double difference = new_iteration[i][j] - current_iteration[i][j];
			if (difference > maxIterationDifference)
			{
				maxIterationDifference = difference;
			}
		}
	}
	maxDifference = maxIterationDifference;
	copy_values(new_iteration, current_iteration);
}


int main()
{
	double current_iteration[ROWS][COLUMNS];
	double new_iteration[ROWS][COLUMNS];
	double maxDifference = 1;

	initialize_array(current_iteration);
	copy_values(current_iteration, new_iteration);

	printNoCommasNoDecimals(current_iteration);
	cout << endl << endl;

	update_plate_once(current_iteration, new_iteration, maxDifference);
	printNoCommasNoDecimals(current_iteration);
	cout << endl << endl;

	while (maxDifference > TOLERATED_DIFFERENCE)
	{
		update_plate_once(current_iteration, new_iteration, maxDifference);
	}
	//printWithCommasAndDecimals(current_iteration);

	csv_array(current_iteration);


	system("pause");
	return 0;
}