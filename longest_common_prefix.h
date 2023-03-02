#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

/*
Created : 27-02-23

14. Longest Common Prefix [Easy]

Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

Constraints:
1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.
*/


std::string longestCommonPrefix(std::vector<std::string> strs)
{
	std::string ret;
	int size = strs.size();

	// get min string size
	int min_size = 999;
	int ss;
	for (int i = 0; i < size; i++)
	{
		ss = strs[i].size();
		if (ss < min_size)
			min_size = ss;
	}

	for (int i = 0; i < min_size; i++)
	{
		for (int j = 1; j < size; j++)
		{
			if (strs[0][i] != strs[j][i])
				return ret;
		}

		ret += strs[0][i];
	}

	return ret;
}

/*
	auto s1 = longestCommonPrefix({ "flower", "flow", "flight" });
	auto s2 = longestCommonPrefix({ "dog","racecar","car" });
*/