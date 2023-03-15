#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

/*
10. Regular Expression Matching [Hard]

Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:
'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Example 1:
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:
Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

Example 3:
Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".

Constraints:
1 <= s.length <= 20
1 <= p.length <= 20
s contains only lowercase English letters.
p contains only lowercase English letters, '.', and '*'.
It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.
*/

bool isMathcDfs(std::map<std::pair<int, int>, bool>& dps, const std::string& s, const std::string& p, int i, int j)
{
	auto it = dps.find({ i,j });
	if (it != dps.end())
		return it->second;

	int szs = s.size();
	int szp = p.size();

	if (i >= szs && j >= szp)
		return true;

	if (j >= szp)
		return false;

	bool match = i < szs && (s[i] == p[j] || p[j] == '.');
	if (j + 1 < p.size() && p[j + 1] == '*') 
	{
		dps[{i, j}] = isMathcDfs(dps, s, p, i, j + 2) || (match && isMathcDfs(dps, s, p, i + 1, j));
		return dps[{i, j}];
	}

	if (match) 
	{
		dps[{i, j}] = isMathcDfs(dps, s, p, i + 1, j + 1);
		return dps[{i, j}];
	}

	dps[{i, j}] = false;
	return dps[{i, j}];
}

// top down memorization
bool isMatch(std::string s, std::string p)
{
	std::map<std::pair<int, int>, bool> dps;
	return isMathcDfs(dps, s, p, 0, 0);
}

/*
	bool b1 = isMatch("aa", "a");
	bool b2 = isMatch("aa", "a*");
	bool b3 = isMatch("ab", ".*");
	bool b4 = isMatch("aab", "c*a*b");
*/