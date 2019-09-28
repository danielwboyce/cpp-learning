#include "ExpressionManagerInterface.h"
#include <sstream>

using namespace std;

class ExpressionManager : public ExpressionManagerInterface
{
public:
	//constructor and deconstructor
	ExpressionManager();
	~ExpressionManager();

	/*
	* Checks whether an expression is balanced on its parentheses
	*
	* - The given expression will have a space between every number or operator
	*
	* @return true if expression is balanced
	* @return false otherwise
	*/
	bool isBalanced(string expression);

	/**
	* Converts a postfix expression into an infix expression
	* and returns the infix expression.
	*
	* - The given postfix expression will have a space between every number or operator.
	* - The returned infix expression must have a space between every number or operator.
	* - Redundant parentheses are acceptable i.e. ( ( 3 * 4 ) + 5 ).
	* - Check lab requirements for what will be considered invalid.
	*
	* return the string "invalid" if postfixExpression is not a valid postfix expression.
	* otherwise, return the correct infix expression as a string.
	*/
	string postfixToInfix(string postfixExpression);

	/*
	* Converts an infix expression into a postfix expression
	* and returns the postfix expression
	*
	* - The given infix expression will have a space between every number or operator.
	* - The returned postfix expression must have a space between every number or operator.
	* - Check lab requirements for what will be considered invalid.
	*
	* return the string "invalid" if infixExpression is not a valid infix expression.
	* otherwise, return the correct postfix expression as a string.
	*/
	string infixToPostfix(string infixExpression);

	/*
	* Evaluates a postfix expression returns the result as a string
	*
	* - The given postfix expression will have a space between every number or operator.
	* - Check lab requirements for what will be considered invalid.
	*
	* return the string "invalid" if postfixExpression is not a valid postfix Expression
	* otherwise, return the correct evaluation as a string
	*/
	string postfixEvaluate(string postfixExpression);

	//Checks if the input is a left parenthesis, bracket, or curly brace.
	bool isLeftParenth(string t);

	//Checks if the input is a right parenthesis, bracket, or curly brace.
	bool isRightParenth(string t);

	//Checks if the two parenthesis, brackets, or curly braces form a pair.
	bool isPair(string left, string right);

	//Checks if the input is an operator
	bool isOperator(string t);

	//Checks if the input is a number or not
	bool isNumber(string t);

	//Returns the precedence of the operator
	int precedence(string operatorInput);

	const int IMMEDIATE_PRECEDENCE = 3;
	const int HIGH_PRECEDENCE = 2;
	const int LOW_PRECEDENCE = 1;
	const int WILD_PRECEDENCE = 0;


//private:

};