#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <map>

/*
438. Find All Anagrams in a String [Medium]

Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:
Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

Example 2:
Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".

Constraints:
1 <= s.length, p.length <= 3 * 104
s and p consist of lowercase English letters.
*/

std::vector<int> findAnagrams(std::string s, std::string p)
{
	std::vector<int> ret;
	std::sort(p.begin(), p.end());

	std::string compare = "";

	int size_s = s.size();
	int size_p = p.size();

	for (int i = 0; i <= size_s - size_p; i++)
	{
		compare = "";

		for (int j = 0; j < size_p; j++)
			compare += s[i + j];

		std::sort(compare.begin(), compare.end());

		if (compare == p)
			ret.push_back(i);
	}

	return ret;
}

std::vector<int> findAnagrams2(std::string s, std::string p)
{
	int size_s = s.size();
	int size_p = p.size();

	if (size_p > size_s)
		return { };

	std::vector<int> ret;

	std::unordered_map<char, int> map_s;
	std::unordered_map<char, int> map_p;

	//std::vector<int> vec_s(26, 0);
	//std::vector<int> vec_p(26, 0);

	for (int i = 0; i < size_p; i++)
	{
		map_s[s[i]]++;
		map_p[p[i]]++;
	}

	if (map_s == map_p)
		ret.push_back(0);

	int l = 0;
	for (int r = size_p; r < size_s; r++)
	{
		char cr = s[r];
		char cl = s[l];

		map_s[s[r]]++;
		map_s[s[l]]--;
		if (map_s[s[l]] == 0)
			map_s.erase(s[l]);

		l++;
		if (map_s == map_p)
			ret.push_back(l);
	}

	return ret;
}

/*
	auto v1 = findAnagrams2("cbaebabacd", "abc");
	auto v2 = findAnagrams2("abab", "ab");
	auto v3 = findAnagrams2("abacbabc", "abc");
*/