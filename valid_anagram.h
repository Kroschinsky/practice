#pragma once

#include <string>

/*
242. Valid Anagram [Easy]

Given two strings s and t, return true if t is an anagram of s, and false otherwise.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false

Constraints:
1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
*/

bool isAnagram(std::string s, std::string t)
{
	if (s.size() != t.size())
		return false;

	std::unordered_map<char, int> map;

	for (char c : s)
		map[c]++;

	for (char c : t)
	{
		if (map[c] == 0)
			return false;

		map[c]--;
	}

	return true;
}

bool isAnagram2(std::string s, std::string t)
{
	if (s.size() != t.size())
		return false;

	int letters[26] = { 0 };

	for (char c : s)
		letters[c - 'a']++;

	for (char c : t)
	{
		if (letters[c - 'a'] == 0)
			return false;

		letters[c - 'a']--;
	}

	return true;
}

/*
	bool b1 = isAnagram2("anagram", "nagaram");
	bool b2 = isAnagram2("rat", "car");
*/