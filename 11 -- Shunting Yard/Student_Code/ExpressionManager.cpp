#include "ExpressionManager.h"

using namespace std;

ExpressionManager::ExpressionManager() : ExpressionManagerInterface()
{}
ExpressionManager::~ExpressionManager()
{}


//Checks if the input is a left parenthesis, bracket, or curly brace.
bool ExpressionManager::isLeftParenth(string t)
{
	if (t == "(" || t == "[" || t == "{")
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Checks if the input is a right parenthesis, bracket, or curly brace.
bool ExpressionManager::isRightParenth(string t)
{
	if (t == ")" || t == "]" || t == "}")
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Checks if the two parenthesis, brackets, or curly braces form a pair.
bool ExpressionManager::isPair(string left, string right)
{
	if (left == "(" && right == ")")
	{
		return true;
	}
	else if (left == "[" && right == "]")
	{
		return true;
	}
	else if (left == "{" && right == "}")
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Checks if the input is an operator
bool ExpressionManager::isOperator(string t)
{
	//()[]{}+-*/%
	if (t == "(" || t == ")" || t == "[" || t == "]" || t == "{" || t == "}" ||
		t == "+" || t == "-" || t == "*" || t == "/" || t == "%")
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Checks if the input is a number or not
bool ExpressionManager::isNumber(string t)
{
	stringstream ss;
	ss << t;
	double inputdouble = 0;
	if (ss >> inputdouble)
	{
		stringstream tt;
		int inputint = 0;
		tt << inputdouble;
		tt >> inputint;
		if (inputdouble == 0)
		{
			return true;
		}
		else if (inputdouble / inputint == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
		//cout << input << endl;
		
	}
	else
	{
		return false;
	}
}

//Returns the precedence of the operator. Assuming the input is an approved operator.
int ExpressionManager::precedence(string operatorInput)
{
	if (isLeftParenth(operatorInput))
	{
		return 0;
	}
	else if (operatorInput == "+" || operatorInput == "-")
	{
		return 1;
	}
	else if (operatorInput == "*" || operatorInput == "/" || operatorInput == "%")
	{
		return 2;
	}
	else if (isRightParenth(operatorInput))
	{
		return 3;
	}
	else
	{
		return -1;
	}
}

/*
* Checks whether an expression is balanced on its parentheses
*
* - The given expression will have a space between every number or operator
*
* @return true if expression is balanced
* @return false otherwise
*/
bool ExpressionManager::isBalanced(string expression)
{
	stack<string> inputStack;
	stringstream ss;
	ss << expression;
	string nextInput;
	while (ss >> nextInput)
	{
		if (isLeftParenth(nextInput))
		{
			inputStack.push(nextInput);
			//cout << "A left parenth was added to the stack " << nextInput << endl;
		}
		else if (isRightParenth(nextInput))
		{
			if (inputStack.empty())
			{
				//cout << "A right parenth was next, but the stack was empty so we returned false. " << nextInput << endl;
				return false;
			}
			else
			{
				//string temp = inputStack.top();
				if (isPair(inputStack.top(), nextInput))
				{
					//cout << "A right parenth was next, which matched the previous parenth entered, so we popped the top off" << nextInput << endl;
					inputStack.pop();
				}
				else
				{
					return false;
				}
			}
		}
	}
	if (!inputStack.empty())
	{
		return false;
	}
	else
	{
		return true;
	}
	
}

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
string ExpressionManager::postfixToInfix(string postfixExpression)
{
	stack<string> inputStack;
	stringstream ss;
	ss << postfixExpression;
	string nextInput;
	

	if (postfixEvaluate(postfixExpression) == "invalid")
	{
		return "invalid";
	}
	else
	{
		while (ss >> nextInput)
		{
			stringstream product;
			if (isNumber(nextInput))
			{
				inputStack.push(nextInput);
			}
			else if (isOperator(nextInput))
			{
				if (inputStack.size() >= 2)
				{
					//cout << inputStack.top() << endl;
					
					string right = inputStack.top();
					inputStack.pop();
					string left = inputStack.top();
					inputStack.pop();
					//cout << "The right element is " << right << endl;
					//cout << "The left element is " << left << endl;


					if (nextInput == "+")
					{
						product << "( " << left << " + " << right << " )";
					}
					else if (nextInput == "-")
					{
						product << "( " << left << " - " << right << " )";
					}
					else if (nextInput == "*")
					{
						product << "( " << left << " * " << right << " )";
					}
					else if (nextInput == "/")
					{
						product << "( " << left << " / " << right << " )";
					}
					else if (nextInput == "%")
					{
						product << "( " << left << " % " << right << " )";
					}
					else
					{
						return "invalid";
					}

					inputStack.push(product.str());

					//cout << inputStack.top() << endl;
				}
				else
				{
					return "invalid";
				}

			}
			else
			{
				return "invalid";
			}
		}

		return inputStack.top();
	}
}

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
string ExpressionManager::infixToPostfix(string infixExpression)
{
	stack<string> operatorStack;
	stringstream ss;
	ss << infixExpression;
	string nextInput;
	stringstream product;

	if (isBalanced(infixExpression))
	{
		//cout << "Segfault one count." << endl;
		while (ss >> nextInput)
		{
			if (isNumber(nextInput))
			{
				product << nextInput << " ";
				//cout << "Segfault two count." << endl;
			}
			else if (isOperator(nextInput))
			{
				//cout << "Segfault three count." << endl;
				if (operatorStack.empty())
				{
					//cout << "Segfault four count." << endl;
					operatorStack.push(nextInput);
				}
				else
				{
					//cout << "Segfault five count." << endl;
					if (precedence(nextInput) == WILD_PRECEDENCE)
					{
						//cout << "Segfault six count." << endl;
						operatorStack.push(nextInput);
					}
					else if (precedence(nextInput) == IMMEDIATE_PRECEDENCE)
					{
						//cout << "Segfault six.two count." << endl;
						//cout << "Top of the stack before the while loop: " << operatorStack.top() << endl;
						while (!operatorStack.empty() && !isLeftParenth(operatorStack.top()))
						{
							product << operatorStack.top() << " ";
							//cout << operatorStack.top() << endl;
							operatorStack.pop();
							//cout << product.str() << endl;
							//cout << "Segfault seven count." << endl;
							//cout << "I made it here 1" << endl;
							//cout << operatorStack.top() << endl;
						}
						//cout << "I made it here 2" << endl;
						if (!operatorStack.empty())
						{
							if (isLeftParenth(operatorStack.top()))
							{
								operatorStack.pop();
							}
							//operatorStack.pop();
						}
						//if (!operatorStack.empty())
						//{
						//	operatorStack.pop();
							//operatorStack.pop();
						//}
						//cout << "Do I make it here?" << endl;
						//cout << "I made it here 3" << endl;
						//cout << operatorStack.top() << endl;
					}
					else if (precedence(nextInput) > precedence(operatorStack.top()))
					{
						//cout << "Segfault eight count." << endl;
						operatorStack.push(nextInput);
					}
					else if (precedence(nextInput) <= precedence(operatorStack.top()))
					{
						//cout << "Segfault nine count." << endl;
						while (!operatorStack.empty() && precedence(nextInput) <= precedence(operatorStack.top()))
						{
							
							product << operatorStack.top() << " ";
							operatorStack.pop();
							//cout << "Segfault ten count." << endl;
						}
						operatorStack.push(nextInput);
					}
				}
			}
			else
			{
				return "invalid";
			}
		}
		while (!operatorStack.empty())
		{
			product << operatorStack.top() << " ";
			operatorStack.pop();
		}

		//cout << "I made it out of the while loop!!" << endl;

		string final = product.str();
		if (final.back() == ' ')
		{
			final.pop_back();
			//return final;
		}
		//cout << "I made it to just before the return" << endl;
		
		//cout << final << endl;

		if (postfixEvaluate(final) != "invalid")
		{
			return product.str();
		}
		else
		{
			return "invalid";
		}
	}
	else
	{
		return "invalid";
	}	
}

/*
* Evaluates a postfix expression returns the result as a string
*
* - The given postfix expression will have a space between every number or operator.
* - Check lab requirements for what will be considered invalid.
*
* return the string "invalid" if postfixExpression is not a valid postfix Expression
* otherwise, return the correct evaluation as a string
*/
string ExpressionManager::postfixEvaluate(string postfixExpression)
{
	stack<string> inputStack;
	stringstream ss;
	ss << postfixExpression;
	string nextInput;
	
	//if (isBalanced(postfixExpression))
	//{
		while (ss >> nextInput)
		{
			if (isOperator(nextInput))
			{
				if (inputStack.size() >= 2)
				{
					//cout << inputStack.top() << endl;
					
					int right = 0;
					int left = 0;
					int result = 0;
					
					stringstream rightss;
					stringstream leftss;
					string rightString = inputStack.top();
					inputStack.pop();
					string leftString = inputStack.top();
					inputStack.pop();
					//cout << "The right element is " << rightString << endl;
					//cout << "The left element is " << leftString << endl;
					rightss << rightString;
					leftss << leftString;
					rightss >> right;
					leftss >> left;
					//cout << "The right element is " << right << endl;
					//cout << "The left element is " << left << endl;


					if (nextInput == "+")
					{
						result = left + right;
					}
					else if (nextInput == "-")
					{
						result = left - right;
					}
					else if (nextInput == "*")
					{
						result = left * right;
					}
					else if (nextInput == "/")
					{
						if (right == 0)
						{
							return "invalid";
						}
						else
						{
							result = left / right;
						}
					}
					else if (nextInput == "%")
					{
						if (right == 0)
						{
							return "invalid";
						}
						else
						{
							result = left % right;
						}
					}
					else
					{
						return "invalid";
					}

					stringstream product;
					product << result;
					inputStack.push(product.str());

					//cout << inputStack.top() << endl;

				}
				else
				{
					return "invalid";
				}
			}
			else if (isNumber(nextInput))
			{
				inputStack.push(nextInput);
			}
			else
			{
				return "invalid";
			}
			//cout << inputStack.top() << endl;
		}
	//}
	//else
	//{
	//	return "invalid";
	//}

	if (inputStack.size() == 1)
	{
		return inputStack.top();
	}
	else
	{
		return "invalid";
	}
}
