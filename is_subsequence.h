#pragma once

#include <iostream>
#include <vector>
#include <string>

/*
Create: 28-02-23

392. Is Subsequence [Easy]

Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters 
without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:
Input: s = "abc", t = "ahbgdc"
Output: true

Example 2:
Input: s = "axc", t = "ahbgdc"
Output: false
*/

bool isSubsequence(std::string s, std::string t)
{
	int size_s = s.size();
	int size_t = t.size();
	if (size_s == 0) return true;
	if (size_t == 0) return false;

	int index = 0;
	char check = s[index];

	for (int i = 0; i < size_t; i++)
	{
		if (check == t[i])
		{
			check = s[++index];
			if (index == size_s)
				return true;
		}
	}	

	return index == size_s;
}

/*
	bool b_1 = isSubsequence("ace", "abcde");       // true
	bool b_2 = isSubsequence("aec", "abcde");       // false
	bool b1 = isSubsequence("abc", "ahbgdc");       // true
	bool b2 = isSubsequence("axc", "ahbgdc");       // false
*/