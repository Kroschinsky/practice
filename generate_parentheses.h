#pragma once

#include <vector>
#include <string>

/*
22. Generate Parentheses [Medium]
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:
Input: n = 1
Output: ["()"]

Constraints:
1 <= n <= 8
*/

void generateParenthesisHelper(int open, int close, int n, std::string text, std::vector<std::string>& ret)
{
	if (open == close && open == n)
	{
		ret.push_back(text);
		return;
	}

	if (open < n)
	{
		generateParenthesisHelper(open + 1, close, n, text + "(", ret);
	}

	if (close < open)
	{
		generateParenthesisHelper(open, close + 1, n, text + ")", ret);
	}
}

std::vector<std::string> generateParenthesis(int n) 
{
	std::vector<std::string> ret;
	generateParenthesisHelper(0, 0, n, "", ret);
	return ret;
}

/*
	auto v1 = generateParenthesis(3);
	auto v2 = generateParenthesis(1);
*/