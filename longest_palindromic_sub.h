#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <set>

/*
Created: 26-02-23 

Given a string s, return the longest palindromic substring in s.
palindromic : a word, verse, sentence or a number that reads the same backward or forward.

Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:
Input: s = "cbbd"
Output: "bb"
*/

std::string longestPalindrome(std::string s)
{
	int size = s.size();
	int check_size;
	std::string test;
	std::string ret = "";
	bool find;

	for (int i = 0; i < size-1; i++)
	{
		test = s[i];

		for (int j = i + 1; j < size; j++)
		{
			test += s[j];

			if (s[i] == s[j])
			{
				// check reverse

				find = true;
				check_size = test.size();
				
				for (int c = 0; c < check_size; c++)
				{
					if (check_size % 2 == 1 && c == (check_size / 2))
						continue;

					if (test[c] != test[check_size - c - 1])
					{
						find = false;
						break;
					}
				}

				if (find)
				{
					if (test.size() > ret.size())
						ret = test;
				}
			}
		}
	}

	if (ret == "" && size > 0)
		ret = s[0];

	return ret;
}

std::string longestPalindrome2(std::string s)
{
	int size = s.size();
	if (size == 0)
		return "";

	bool find;
	int start = 0;
	int end = 0;
	int check_size = 0;

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1 + end - start; j < size; j++)
		{
			if (s[i] == s[j])
			{
				find = true;
				check_size = j - i;

				for (int c = 0; c <= check_size/2; c++)
				{
					if (s[i + c] != s[i + check_size - c])
					{
						find = false;
						break;
					}
				}

				if (find)
				{
					if (check_size > (end - start))
					{
						start = i;
						end = j;
					}
				}

			}
		}
	}

	return s.substr(start, end - start + 1);
}

/*
	auto s1 = longestPalindrome2("babad");          // bab
	auto s2 = longestPalindrome2("cbbd");           // bb
	auto s3 = longestPalindrome2("a");              // a
	auto s4 = longestPalindrome2("aacabdkacaa");    // "aca"
*/