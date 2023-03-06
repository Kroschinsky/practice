#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <map>

/*
567. Permutation in String [Medium]

Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
In other words, return true if one of s1's permutations is the substring of s2.

Example 1:
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:
Input: s1 = "ab", s2 = "eidboaoo"
Output: false

Constraints:
1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.
*/

bool checkInclusion(std::string s1, std::string s2)
{
	int size1 = s1.size();
	int size2 = s2.size();
	if (size1 > size2)
		return false;

	bool find = true;

	std::unordered_map<char, int> map_s1;
	for (int i = 0; i < size1; i++)
		map_s1[s1[i]]++;

	for (int i = 0; i < size2 - size1 + 1; i++)
	{
		find = true;
		std::unordered_map<char, int> map;

		for (int j = 0; j < size1; j++)
			map[s2[i + j]]++;

		for (auto& pair : map)
		{
			auto it = map_s1.find(pair.first);
			if (it == map_s1.end() || it->second != pair.second)
			{
				find = false;
				break;
			}
		}

		if (find)
			return true;
	}

	return false;
}


bool checkInclusion2(std::string s1, std::string s2)
{
	int size1 = s1.size();
	int size2 = s2.size();

	if (size1 > size2)
		return false;

	std::unordered_map<char, int> s1_map;
	std::unordered_map<char, int> s2_map;

	for (char c : s1)
		s1_map[c]++;

	for (int i = 0, j = 0; i < size2; i++)
	{
		s2_map[s2[i]]++;

		if (i - j + 1 > size1)
		{
			s2_map[s2[j]]--;
			j++;

			if (s2_map[s2[j - 1]] == 0)
				s2_map.erase(s2[j - 1]);
		}

		if ((i - j + 1 == size1) && s1_map == s2_map)
			return true;
	}

	return false;
}

/*
{
	bool b1 = checkInclusion2("ab", "eidbaooo");
	bool b2 = checkInclusion2("ab", "eidboaoo");
	bool b3 = checkInclusion2("adc", "dcda");
*/