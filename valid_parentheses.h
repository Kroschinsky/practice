#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stack>

/*
20. Valid Parentheses
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false

Constraints:
1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/

bool isValidParentheses(std::string s)
{
	if (s.empty())
		return false;

	std::map<char, char> map;
	map = { {')','('}, {'}','{'} , {']','['} };
	std::vector<char> open;

	int size = s.size();

	for (int i = 0; i < size; i++)
	{
		auto it = map.find(s[i]);
		if (it != map.end())
		{
			// close
			int index = open.size() - 1;
			if (index == -1)
				return false;

			if (open[index] == it->second)
				open.erase(open.begin() + index);
			else
				return false;
		}
		else
		{
			// open
			open.push_back(s[i]);
		}
	}

	return open.size() == 0;
}

bool isValidParentheses2(std::string s)
{
	if (s.empty())
		return false;

	std::map<char, char> map;
	map = { {')','('}, {'}','{'} , {']','['} };
	std::stack<char> open;

	int size = s.size();

	for (int i = 0; i < size; i++)
	{
		auto it = map.find(s[i]);
		if (it != map.end())
		{
			// close
			if (open.empty() || open.top() != it->second)
				return false;

			open.pop();
		}
		else
		{
			// open
			open.push(s[i]);
		}
	}

	return open.size() == 0;
}

/*
	bool b1 = isValidParentheses2("()");
	bool b2 = isValidParentheses2("()[]{}");
	bool b3 = isValidParentheses2("(]");
*/