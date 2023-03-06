#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <stack>

/*
Created : 26-02-23

You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.

*/

std::vector<std::string> token_split_string(std::string text, char separator)
{
	std::vector<std::string> ret;
	std::string token = "";

	int size = text.size();

	for (int i = 0; i < size; i++)
	{
		if (text[i] == separator)
		{
			ret.push_back(token);
			token = "";
		}
		else
		{
			token += text[i];
		}
	}

	if (token != "")
		ret.push_back(token);

	return ret;
}

int erpn_vector(std::vector<std::string>& tokens)
{
	std::stack<int> stack;
	int val1, val2;

	for (std::string& token : tokens)
	{
		if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			val1 = stack.top();
			stack.pop();

			val2 = stack.top();
			stack.pop();

			if (token == "+")
			{
				val1 = val2 + val1;
			}
			else if (token == "-")
			{
				val1 = val2 - val1;
			}
			else if (token == "*")
			{
				val1 = val2 * val1;
			}
			else if (token == "/")
			{
				val1 = val2 / val1;
			}

			stack.push(val1);
		}
		else
			stack.push(stoi(token));
	}

	return stack.top();
}

int rpnCalculator(std::string text)
{
	auto tokens = token_split_string(text, ' ');
	return erpn_vector(tokens);
}

/*
    auto v1 = rpnCalculator("1 2 3 * +"); // 7
    auto v2 = rpnCalculator("1156 12 11 * +"); // 1288
    auto v3 = rpnCalculator("5 2 + 3 *"); // 21
    auto v4 = rpnCalculator("5 2 * 2 * 4 +"); // 24
    auto v5 = rpnCalculator("5 2 + 2 + 4 +"); // 13
    auto v6 = rpnCalculator("3 2 + 2 4 + *"); // 30
    auto v7 = rpnCalculator("3 2 2 4 + + *"); // 24
    auto v8 = rpnCalculator("5"); // 5
    auto v9 = rpnCalculator("0 1 *"); // 0
    auto v0 = rpnCalculator("5 5 + 6 6 + 1 1 + * +"); // "10 12 2 * +" => 34
*/