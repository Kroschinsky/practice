#pragma once

#include <iostream>
#include <vector>
#include <string>

/*
Created: 02-03-23

67. Add Binary [Easy]

Given two binary strings a and b, return their sum as a binary string.

Example 1:
Input: a = "11", b = "1"
Output: "100"

Example 2:
Input: a = "1010", b = "1011"
Output: "10101"
*/

std::string addBinary(std::string a, std::string b) 
{
	int size_a = a.size();
	int size_b = b.size();
	int size = size_a;
	if (size_b > size_a)
		size = size_b;

	std::string ret;

	int carry = 0;
	int sum = 0;
	int v1, v2;

	for (int i = 0; i < size; i++)
	{
		v1 = 0;
		if (size_a > i && a[size_a - i - 1] == '1')
			v1 = 1;

		v2 = 0;
		if (size_b > i && b[size_b - i - 1] == '1')
			v2 = 1;

		sum = v1 + v2 + carry;

		if (sum == 3)
		{
			carry = 1;
			ret = '1' + ret;
		}
		else if (sum == 2)
		{
			carry = 1;
			ret = '0' + ret;
		}
		else if (sum == 1)
		{
			carry = 0;
			ret = '1' + ret;
		}
		else
		{
			carry = 0;
			ret = '0' + ret;
		}
	}

	if (carry == 1)
		ret = '1' + ret;

	return ret;
}

std::string addBinary2(std::string a, std::string b)
{
	std::string ret = "";

	int sum = 0;
	int carry = 0;
	int ia = a.size() - 1;
	int ib = b.size() - 1;

	while (ia >= 0 || ib >= 0)
	{
		int sum = carry;

		if (ia >= 0)
			sum += a[ia--] - '0';

		if (ib >= 0)
			sum += b[ib--] - '0';

		carry = sum > 1 ? 1 : 0;

		ret = char('0' + (sum % 2)) + ret;
	}

	if (carry == 1)
		ret = '1' + ret;

	return ret;
}

/*
	auto s1 = addBinary2("11", "1");             // "100"
	auto s2 = addBinary2("1010", "1011");        // "10101"
*/