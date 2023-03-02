#pragma once

#include <string>
#include <map>
#include <unordered_map>

/*
Roman to Integer

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. 
The number 27 is written as XXVII, which is XX + V + II.
Roman numerals are usually written largest to smallest from left to right. 
However, the numeral for four is not IIII. Instead, the number four is written as IV. 
Because the one is before the five we subtract it making four. 
The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.

Example 1:
Input: s = "III"
Output: 3
Explanation: III = 3.

Example 2:
Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.

Example 3:
Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

Constraints:
1 <= s.length <= 15
s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
It is guaranteed that s is a valid roman numeral in the range [1, 3999].
*/



int romanToInt(std::string s) 
{
	std::unordered_map<char, int> symbols;
	symbols = { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };

	int ret = 0;
	int val = 0;
	int temp = 0;
	int last = 0;
	int size = s.size();

	for (int i = 0; i < size; i++)
	{
		val = symbols[s[i]];

		if (last == 0)
			last = val;
		else if (last != val)
		{
			if (last > val)
				ret += temp;
			else
				ret -= temp;

			temp = 0;
			last = val;
		}

		temp += val;
	}

	return ret + temp;
}

int romanToInt2(std::string s)
{
	std::unordered_map<char, int> symbols;
	symbols = { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };

	int ret = 0;
	int v1, v2;
	int size = s.size();

	for (int i = 0; i < size; i++)
	{
		v1 = symbols[s[i]];

		v2 = 0;
		if (i+1 < size)
			v2 = symbols[s[i+1]];

		if (v1 >= v2)
			ret += v1;
		else
			ret -= v1;
	}

	return ret;
}

/*
	int v0 = romanToInt2("IV");                // 4
	int v1 = romanToInt2("III");               // 3
	int v2 = romanToInt2("LVIII");             // 58
	int v3 = romanToInt2("MCMXCIV");           // 1994
*/