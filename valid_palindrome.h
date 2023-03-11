#pragma once

#include <string>
#include <vector>
#include <map>

/*
125. Valid Palindrome [Easy]

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and 
removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Example 3:
Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.

Constraints:
1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.
*/

bool isPalindrome(std::string s)
{
	std::string ns = "";
	std::string pl = "";

	for (char c : s)
	{
		if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
		{
			ns = ns + c;
			pl = c + pl;
			continue;
		}

		if (c >= 'A' && c <= 'Z')
		{
			char cc = c - ('A' - 'a');
			ns = ns + cc;
			pl = cc + pl;
			continue;
		}
	}

	return ns == pl;
}

char fixCharHelper(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
		return c;

	if (c >= 'A' && c <= 'Z')
		return c - ('A' - 'a');

	return 0;
}

bool isPalindrome2(std::string s)
{
	int left = 0;
	int right = s.size() - 1;

	while (right > left)
	{
		char l = fixCharHelper(s[left]);
		if (l == 0)
		{
			left++;
			continue;
		}

		char r = fixCharHelper(s[right]);
		if (r == 0)
		{
			right--;
			continue;
		}

		if (l != r)
			return false;

		left++;
		right--;
	}

	return true;
}

/*
	bool b1 = isPalindrome2("A man, a plan, a canal : Panama");
	bool b2 = isPalindrome2("race a car");
	bool b3 = isPalindrome2(" ");
*/