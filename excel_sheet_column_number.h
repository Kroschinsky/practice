#pragma once

#include <string>

/*
171. Excel Sheet Column Number [Easy]

Given a string columnTitle that represents the column title as appears in an Excel sheet, return its corresponding column number.
For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28
...

Example 1:
Input: columnTitle = "A"
Output: 1

Example 2:
Input: columnTitle = "AB"
Output: 28

Example 3:
Input: columnTitle = "ZY"
Output: 701

Constraints:
1 <= columnTitle.length <= 7
columnTitle consists only of uppercase English letters.
columnTitle is in the range ["A", "FXSHRXW"].
*/

int titleToNumber(std::string columnTitle) 
{
	int ret = 0;
	int size = columnTitle.size();

	for (int i = 0; i < size; i++)
	{
		int value = columnTitle[size - 1 - i] - 'A' + 1;
		ret += value * std::pow(26, i);
	}

	return ret;
}

int titleToNumber2(std::string columnTitle)
{
	int ret = 0;
	int size = columnTitle.size();

	for (char c : columnTitle)
		ret = ret * 26 + (c - 'A' + 1);

	return ret;
}

/*
	int v1 = titleToNumber("A");            // 1
	int v2 = titleToNumber("AB");           // 28
	int v3 = titleToNumber("ZY");           // 701
*/