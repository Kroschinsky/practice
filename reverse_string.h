#pragma once

#include <iostream>
#include <vector>
#include <string>

/*
Created: 01-03-23

344. Reverse String [Easy]

Write a function that reverses a string. The input string is given as an array of characters s.
You must do this by modifying the input array in-place with O(1) extra memory.

Example 1:
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

Example 2:
Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
*/

void reverseString(std::vector<char>& s)
{
	int size = s.size();
	int left = 0;
	int right = size - 1;

	while (left < right)
	{
		std::swap(s[left], s[right]);

		left++;
		right--;
	}
}

/*
	std::vector<char> v1 = { 'h','e','l','l','o' };
	reverseString(v1);

	std::vector<char> v2 = { 'H','a','n','n','a','h' };
	reverseString(v2);
*/