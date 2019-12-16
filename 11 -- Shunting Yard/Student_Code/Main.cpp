#include "ExpressionManager.h"


using namespace std;

void printBalanceTests(string input)
{
	ExpressionManager expressions;
	
	cout << "Input: " << input << endl;
	if (expressions.isBalanced(input))
	{
		cout << "Returned true" << endl;
	}
	else
	{
		cout << "Returned false" << endl;
	}
}
void printPostFixEvaluate(string input)
{
	ExpressionManager expressions;

	cout << "Input: " << input << endl
		<< "Output: " << expressions.postfixEvaluate(input) << endl;
}
void printPostfixToInfix(string input)
{
	ExpressionManager expressions;

	cout << "Input: " << input << endl
		<< "Output: " << expressions.postfixToInfix(input) << endl;
}
void printInfixToPostfix(string input)
{
	ExpressionManager expressions;

	cout << "Input: " << input << endl
		<< "Output: " << expressions.infixToPostfix(input) << endl;
}

int main()
{
	/*
	cout << "Output from tests on isBalanced." << endl;
	//Input1 and input2 are from the test drivers
	string input1 = "{ { [ ( ) ] } ( ) }";
	string input2 = "{ { ( ) [ { } ] ( [ ] ) } }";
	//string input3 = "( ( ( 3 * 4 ) + [ 2 / 3 ] )";

	printBalanceTests(input1);
	printBalanceTests(input2);
	//printBalanceTests(input3);
	*/

	
	//string input4 = "1 7 + 3 * 3 - 2 *";
	//printPostFixEvaluate(input4);
	//cout << endl;
	

	
	//cout << endl << "Output from tests on postfixEvaluate." << endl;
	//These inputs are from the test drivers
	/*
	string postFixEvaluateInput1 = "40 2 4 + 1 1 + - * 4 2 / 1 / - 7 %";
	printPostFixEvaluate(postFixEvaluateInput1);
	string pFEI2 = "34 90 / 4 - 65 3 * /";
	printPostFixEvaluate(pFEI2);
	string pFEI3 = "1 5 - 2 / 89 -";
	printPostFixEvaluate(pFEI3);
	string pFEI4 = "100 50 6 10 - 10 * / /";
	printPostFixEvaluate(pFEI4);
	string pFEI5 = "5 5 5 5 5 5 5 - - - - - -";
	printPostFixEvaluate(pFEI5);
	string pFEI6 = "1";
	printPostFixEvaluate(pFEI6);
	*/
	//string pFEI7 = "0 3 2 + *";
	//printPostFixEvaluate(pFEI7);
	

	/*
	cout << endl << "Output from tests of postfixToInfix." << endl;
	string PTI1 = "3 4 + 3 2 - * 2 2 / - 24 3 / +";
	printPostfixToInfix(PTI1);
	//printPostFixEvaluate(PTI1);

	
	string PTI2 = "3 + 3 /";
	printPostfixToInfix(PTI2);
	string PTI3 = "3 3 4 +";
	printPostfixToInfix(PTI3);
	string PTI4 = "40 2 4 + 1 1 + - * 4 5 / 6 / -";
	printPostfixToInfix(PTI4);
	string PTI5 = "*";
	printPostfixToInfix(PTI5);
	string PTI6 = "+ 3 3";
	printPostfixToInfix(PTI6);
	string PTI7 = "3 3";
	printPostfixToInfix(PTI7);
	string PTI8 = "five plus three";
	printPostfixToInfix(PTI8);
	string PTI9 = "4.3 2 +";
	printPostfixToInfix(PTI9);
	string PTI10 = "5 5 5 5 5 5 5 - - - - - -";
	printPostfixToInfix(PTI10);
	string PTI11 = "56 67 34 + - * 1";
	printPostfixToInfix(PTI11);
	string PTI12 = "3 3 +";
	printPostfixToInfix(PTI12);
	*/

	cout << "Output from infixToPostfix tests." << endl;
	/*
	string ITP1 = "{ { 2 + 4 }";
	printInfixToPostfix(ITP1);
	string ITP2 = "2 + a";
	printInfixToPostfix(ITP2);
	string ITP3 = "3 $ 3";
	printInfixToPostfix(ITP3);
	*/
	string ITP4 = "40 * ( 2 + 4 - ( 2 + 2 ) ) - 4 / 5 / 6";
	printInfixToPostfix(ITP4);
	/*
	string ITP5 = "4 * ( 2 + 4 - ( 2 + )  ) - 4 / 5";
	printInfixToPostfix(ITP5);
	string ITP6 = "4 * ( 2 * + 4 - ( 2 + 2 ) ) - 4 / 5";
	printInfixToPostfix(ITP6);
	*/
	//string ITP7 = "( 3 + 2 + 13 ) / 4";
	//printInfixToPostfix(ITP7);
	//string ITP8 = "43 + 2 * 19";
	//printInfixToPostfix(ITP8);
	/*
	string ITP9 = "( 3 + 5 - ( 4 + 2 ) }";
	printInfixToPostfix(ITP9);
	string ITP10 = "3 + 4.2";
	printInfixToPostfix(ITP10);
	string ITP11= "-";
	printInfixToPostfix(ITP11);
	string ITP12 = "@";
	printInfixToPostfix(ITP12);
	*/
	//string ITP13 = "( ( 3 + 4 ) * ( 3 - 2 ) - ( 2 / 2 ) ) + 24 / 3";
	//printInfixToPostfix(ITP13);
	//string ITP14 = "3 + 5 * 6 - 8";
	//printInfixToPostfix(ITP14);
	//string ITP15 = "48 + 36 % 7 - 2";
	//printInfixToPostfix(ITP15);

	

	cout << endl << endl;
	system("pause");
	return 0;
}