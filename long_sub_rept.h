#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

/*
Given a string s, find the length of the longest substring without repeating characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.

Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

int lengthOfLongestSubstring(std::string s)
{
	int size = s.size();
	std::string sub = "";
	int curr = 0;
	int max = 0;
	bool find;

	for (int i = 0; i < size; i++)
	{
		curr = 1;
		sub = s[i];

		for (int j = i+1; j < size; j++)
		{	
			find = false;
			for (int l = 0; l < sub.size(); l++)
			{
				if (sub[l] == s[j])
				{
					find = true;
					break;
				}
			}

			if (find)
				break;

			sub += s[j];
			curr++;
		}

		if (curr > max)
			max = curr;

		if (max > (size - i))
			break;
	}

	return max;
}

int lengthOfLongestSubstring2(std::string s)
{
	int size = s.size();
	int curr = 0;
	int max = 0;

	for (int i = 0; i < size; i++)
	{
		curr = 0;
		std::unordered_set<char> set;

		for (int j = i; j < size; j++)
		{
			auto it = set.find(s[j]);
			if (it != set.end())
				break;

			set.insert(s[j]);
			curr++;
		}

		if (curr > max)
			max = curr;

		if (max > (size - i))
			return max;
	}

	return max;
}

int lengthOfLongestSubstring3(std::string s)
{
	std::unordered_map<char, int> chars;

	int size = s.size();
	int result = 0;
	int l = 0;
	
	for (int i = 0; i < size; i++)
	{
		auto it = chars.find(s[i]);
		if (it != chars.end() && it->second >= l)
			l = it->second + 1;
		else
			result = std::max(result, i - l + 1);

		chars[s[i]] = i;
	}

	return result;
}

/*
    int v1 = lengthOfLongestSubstring3("abcabcbb");     // 3
    int v2 = lengthOfLongestSubstring3("bbbbb");        // 1
    int v3 = lengthOfLongestSubstring3("pwwkew");       // 3
    int v4 = lengthOfLongestSubstring3("a");            // 1
    int v5 = lengthOfLongestSubstring3("");             // 0
    int v6 = lengthOfLongestSubstring3("aab");          // 2
    int v7 = lengthOfLongestSubstring3("cdd");          // 2
    int v8 = lengthOfLongestSubstring3("dvdf");         // 3
*/