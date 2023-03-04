#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <map>

/*
Created: 04-03-23

409. Longest Palindrome [Easy]

Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.
Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

Example 1:
Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.

Example 2:
Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.

Constraints:
1 <= s.length <= 2000
s consists of lowercase and/or uppercase English letters only.
*/


int longestPalindromeBuilted(std::string s) 
{
	std::unordered_map<char, int> map;

	for (char c : s)
		map[c]++;

	int count = 0;
	int odd = 0;
	for (auto& pair : map)
	{
		if (pair.second % 2 == 0)
			count += pair.second;
		else
		{
			odd = 1;
			count += pair.second - 1;
		}
	}

	return count + odd;
}

/*
	int i1 = longestPalindromeBuilted("abccccdd");
	int i2 = longestPalindromeBuilted("a");
*/