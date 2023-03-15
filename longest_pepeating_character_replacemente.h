#pragma once

#include <string>
#include <unordered_map>

/*
424. Longest Repeating Character Replacement [Medium]

You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. 
You can perform this operation at most k times.
Return the length of the longest substring containing the same letter you can get after performing the above operations.

Example 1:
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.

Example 2:
Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.

Constraints:
1 <= s.length <= 105
s consists of only uppercase English letters.
0 <= k <= s.length
*/

int characterReplacement(std::string s, int k)
{
	int l = 0;
	int maxc = 0;		// max char
	int maxv = 0;		// max window

	int size = s.size();

	std::unordered_map<char, int> map;

	for (int r = 0; r < size; r++)
	{
		map[s[r]]++;
		maxc = std::max(maxc, map[s[r]]);

		while ((r - l + 1) - maxc > k)
		{
			map[s[l]]--;
			l++;
		}

		maxv = std::max(maxv, r - l + 1);
	}
	
	return maxv;
}

/*
	int i1 = characterReplacement("ABAB", 2);
	int i2 = characterReplacement("AABABBA", 1);
*/