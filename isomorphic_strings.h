#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <map>

/*
Created: 28-02-23

205. Isomorphic Strings [Easy]

Given two strings s and t, determine if they are isomorphic.
Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters. 
No two characters may map to the same character, but a character may map to itself.

Example 1:
Input: s = "egg", t = "add"
Output: true

Example 2:
Input: s = "foo", t = "bar"
Output: false

Example 3:
Input: s = "paper", t = "title"
Output: true
*/

bool isIsomorphic(std::string s, std::string t)
{
	int size = s.size();
	char s1, s2;
	std::map<char, char> map;
	std::map<char, char> map_key;

	for (int i = 0; i < size; i++)
	{
		s1 = s[i];
		s2 = t[i];

		auto it = map.find(s1);
		if (it == map.end())
		{
			auto it_key = map_key.find(s2);
			if (it_key == map_key.end())
				map_key[s2] = s1;
			else
			{
				if (it_key->second != s1)
					return false;
			}

			map[s1] = s2;			
		}
		else
		{
			if (it->second != s2)
				return false;
		}
	}

	return true;
}

/*
	bool b1 = isIsomorphic("egg", "add");           // true
	bool b2 = isIsomorphic("foo", "bar");           // false
	bool b3 = isIsomorphic("paper", "title");       // true
	bool b4 = isIsomorphic("badc", "baba");         // false
*/