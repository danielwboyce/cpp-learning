// 00 -- Do What I'm Doing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
	//Escape sequences must be inside strings
	//entered in format: question << spacing formatting << answer << new-line formatting
	cout << "\t\t\t\t" << "Basic BYU Trivia" << "\n";
	cout << "\n";
	cout << "\t\tQuestions" << "\t\t\t\t" << "Answers" << "\n";
	cout << "\n";
	cout << "What was the original name of BYU\?" << "\t\t" << "Brigham Young Academy" << "\n";
	cout << "When was BYA established\?" << "\t\t\t" << "1875" << "\n";
	cout << "Who was the first \"permanent\" principal of BYA\?" << " " << "Karl Maeser" << "\n";
	cout << "When did BYA become BYU\?" << "\t\t\t" << "1903" << "\n";
	cout << "To what sports conference do we belong\?" << "\t\t" << "Independent (Football)" << "\n";
	cout << "When did BYU win the national football title\?" << "\t" << "1984" << "\n";
	cout << "Who won the Heisman Trophy in 1990\?" << "\t\t" << "Ty Detmer" << "\n";

	system("pause");
	return 0;
}
