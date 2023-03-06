#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

/*
49. Group Anagrams [Medium]

Given an array of strings strs, group the anagrams together. You can return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Example 2:
Input: strs = [""]
Output: [[""]]

Example 3:
Input: strs = ["a"]
Output: [["a"]]

Constraints:
1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.
*/

bool groupAnagrams_check(std::string s, std::string t)
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

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> strs)
{
	std::vector<std::vector<std::string>> ret;

	int size = strs.size();
	std::vector<int> check(size, 0);

	for (int i = 0; i < size; i++)
	{
		if (check[i] == 1)
			continue;

		check[i] = 1;

		std::vector<std::string> group;
		group.push_back(strs[i]);

		for (int j = i+1; j < size; j++)
		{
			if (check[j] == 1)
				continue;

			if (groupAnagrams_check(strs[i], strs[j]))
			{
				check[j] = 1;
				group.push_back(strs[j]);
			}
		}

		ret.push_back(group);
	}

	return ret;
}

std::vector<std::vector<std::string>> groupAnagrams2(std::vector<std::string> strs)
{
	std::vector<std::vector<std::string>> ret;
	int size = strs.size();

	// ordened string / default string
	std::unordered_map<std::string, std::vector<std::string>> map;

	for (int i = 0; i < size; i++)
	{
		std::string s = strs[i];
		std::sort(s.begin(), s.end());
		map[s].push_back(strs[i]);
	}

	for (auto& pair : map)
		ret.push_back(pair.second);

	/*
	for (const auto& [_, val] : map)
		ret.push_back(val.second);
	*/

	return ret;
}


/*
	auto v1 = groupAnagrams({ "eat", "tea", "tan", "ate", "nat", "bat" });
	auto v2 = groupAnagrams({ "" });
	auto v3 = groupAnagrams({ "a" });
*/