#pragma once

#include <iostream>
#include <vector>
#include <string>

/*
Created: 01-03-23
 
557. Reverse Words in a String III [Easy]

Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"

Example 2:
Input: s = "God Ding"
Output: "doG gniD"

Constraints:
1 <= s.length <= 5 * 104
s contains printable ASCII characters.
s does not contain any leading or trailing spaces.
There is at least one word in s.
All the words in s are separated by a single space.
*/

void reverse_word_helper(std::string& s, int l, int r)
{
	char temp;
	while (l < r)
	{
		temp = s[l];
		s[l] = s[r];
		s[r] = temp;

		//std::swap(s[l++], s[r--]);
	}
}

std::string reverseWords(std::string& s)
{
	int size = s.size();
	int start = 0;

	for (int i = 0; i < size; i++)
	{
		if (s[i] == ' ')
		{
			reverse_word_helper(s, start, i-1);
			start = i + 1;
		}
	}

	reverse_word_helper(s, start, size-1);

	return s;
}

/*
	std::string s1 = "Let's take LeetCode contest";
	reverseWords(s1);

	std::string s2 = "God Ding";
	reverseWords(s2);
*/