#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>

/*
76. Minimum Window Substring [hard]

Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window.
If there is no such substring, return the empty string "".
The testcases will be generated such that the answer is unique.

Example 1:
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

Example 2:
Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.

Example 3:
Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.

Constraints:
m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.

Follow up: Could you find an algorithm that runs in O(m + n) time?
*/

std::string minWindow(std::string s, std::string t)
{
	std::unordered_map<char, int> check;
	for (char& c : t)
		check[c]++;

	int size_t = t.size();
	int size_s = s.size();

	if (size_t > size_s)
		return "";

	int start = 0;
	int end = 0;
	int min_size = size_s + 1;
	int result_start = -1;

	while(true)
	{
		if (size_t > 0)
		{
			if (end >= size_s)
				break;

			auto it = check.find(s[end]);
			if (it != check.end())
			{
				if (it->second > 0)
					--size_t;

				check[s[end]]--;
			}

			++end;
		}
		else
		{
			if (min_size > (end - start))
			{
				min_size = end - start;
				result_start = start;
			}

			auto it = check.find(s[start]);
			if (it != check.end())
			{
				if (it->second >= 0)
					++size_t;
				
				check[s[start]]++;
			}

			++start;
			if (start + size_t >= size_s)
				break;
		}
	}

	return result_start == -1 ? "" : s.substr(result_start, min_size);
}

/*
std::string output_1 = minWindow("ADOBECODEBANC", "ABC");
std::string output_2 = minWindow("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ", "aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ");
*/