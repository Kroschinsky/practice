#pragma once

#include <iostream>
#include <vector>
#include <string>

/*
Created: 01-03-23

58. Length of Last Word [Easy]

Given a string s consisting of words and spaces, return the length of the last word in the string.
A word is a maximal substring consisting of non-space characters only.

Example 1:
Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.

Example 2:
Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.

Example 3:
Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.
*/

int lengthOfLastWord(std::string s)
{
	int size = s.size();
	int end = 0;
	int blanks = 0;

	for (int i = size - 1; i >= 0; i--)
	{
		if (s[i] == ' ')
		{
			blanks++;

			if (end != 0)
				return end - i;
		}
		else if (end == 0)
			end = i;
	}

	return size - blanks;
}

int lengthOfLastWord2(std::string s)
{
	int size = s.size();
	int count = 0;

	for (int i = size - 1; i >= 0; i--)
	{
		if (s[i] == ' ')
		{
			if (count > 0)
				break;

			continue;
		}

		count++;
	}

	return count;
}

/*
	int i1 = lengthOfLastWord("Hello World");
	int i2 = lengthOfLastWord("   fly me   to   the moon  ");
	int i3 = lengthOfLastWord("luffy is still joyboy");
	int i4 = lengthOfLastWord("a");
	int i5 = lengthOfLastWord("a ");
*/