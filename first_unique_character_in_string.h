#pragma once

#include <string>
#include <unordered_map>

/*
387. First Unique Character in a String [Easy]

Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

Example 1:
Input: s = "leetcode"
Output: 0

Example 2:
Input: s = "loveleetcode"
Output: 2

Example 3:
Input: s = "aabb"
Output: -1

Constraints:
1 <= s.length <= 105
s consists of only lowercase English letters.
*/

int firstUniqChar(std::string s)
{
	std::unordered_map<char, int> map;
	int size = s.size();

	for (char c : s)
		map[c]++;

	for (int i = 0; i < size; i++)
	{
		if (map[s[i]] == 1)
			return i;
	}

	return -1;
}

/*
	int i1 = firstUniqChar("leetcode");
	int i2 = firstUniqChar("loveleetcode");
	int i3 = firstUniqChar("aabb");
*/