#pragma once

#include <string>


/*
28. Find the Index of the First Occurrence in a String [Easy]

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

Example 2:
Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.

Constraints:
1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.
*/

// brutal force
int findIndexFirstOccurrenceString(std::string haystack, std::string needle)
{
	int sizeh = haystack.size();
	int sizen = needle.size();

	for (int i = 0; i <= sizeh - sizen; i++)
	{
		bool check = true;

		for (int j = 0; j < sizen; j++)
		{
			if (haystack[i + j] != needle[j])
			{
				check = false;
				break;
			}
		}

		if (check)
			return i;
	}

	return -1;
}

int findIndexFirstOccurrenceString2(std::string haystack, std::string needle)
{
	std::size_t found = haystack.find(needle);
	if (found != std::string::npos)
		return found;

	return -1;
}

/*
	int i1 = findIndexFirstOccurrenceString("sadbutsad", "sad");
	int i2 = findIndexFirstOccurrenceString("leetcode", "leeto");
	int i3 = findIndexFirstOccurrenceString("a", "a");
*/