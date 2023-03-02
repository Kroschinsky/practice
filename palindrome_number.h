#pragma once

#include <iostream>
#include <string>
#include <vector>

/*
Created: 26-02-23

Palindrome Number

Given an integer x, return true if x is a palindrome, and false otherwise.

Example 1:
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

Example 2:
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
*/

bool isPalindrome(int x) 
{
	if (x < 0)
		return false;

	std::string s = "";

	while (true)
	{
		int val = x / 10;
		int rest = x % 10;

		s += '0' + rest;

		if (val == 0)
			break;

		x = val;
	}

	int size = s.size();

	for (int i = 0; i <= (size / 2); i++)
	{
		if (s[i] != s[size - i - 1])
			return false;
	}

	return true;
}

/*
	bool b1 = isPalindrome(121);        // true
	bool b2 = isPalindrome(-121);       // false
	bool b3 = isPalindrome(10);         // false
	bool b4 = isPalindrome(0);          // true
*/