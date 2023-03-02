#pragma once

#include <iostream>
#include <string>
#include <vector>

/*
Created : 26-02-23

Zigzag Conversion
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:
string convert(string s, int numRows);

Example 1:
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Example 2:
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I

Example 3:
Input: s = "A", numRows = 1
Output: "A"
*/

std::string zigzag_conversion(std::string s, int numRows)
{
	if (numRows == 1)
		return s;

	std::string ret = "";
	int size = s.size();
	int row = 0;
	int dir = 1;

	std::vector<std::pair<char, int>> letters;

	for (int i = 0; i < size; i++)
	{
		letters.push_back(std::make_pair(s[i], row));

		if (row == numRows-1)
		{
			dir = -1;
		}
		else if (row == 0)
		{
			dir = 1;
		}

		row += dir;
	}

	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (letters[j].second == i)
				ret += letters[j].first;
		}
	}

	return ret;
}

std::string zigzag_conversion2(std::string s, int numRows)
{
	if (numRows == 1)
		return s;

	std::string ret = "";
	int size = s.size();
	int row = 0;
	int dir = 1;

	std::vector<std::string> rows(numRows, "");

	for (int i = 0; i < size; i++)
	{
		rows[row] += s[i];

		if (row == numRows - 1)
		{
			dir = -1;
		}
		else if (row == 0)
		{
			dir = 1;
		}

		row += dir;
	}

	for (auto& s : rows)
		ret += s;

	return ret;
}

/*    
	auto s1 = zigzag_conversion("PAYPALISHIRING", 3);           // PAHNAPLSIIGYIR
    auto s2 = zigzag_conversion("PAYPALISHIRING", 4);           // PINALSIGYAHRPI
    auto s3 = zigzag_conversion("A", 1);                        // A
    auto s4 = zigzag_conversion("AB", 1);                       // AB
*/