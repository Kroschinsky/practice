#pragma once

#include <iostream>
#include <vector>
#include <string>

/*
Created: 04-03-23

69. Sqrt(x) [Easy]

Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.
You must not use any built-in exponent function or operator.
For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.

Example 1:
Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.

Example 2:
Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.

Constraints:
0 <= x <= 2^31 - 1
*/

int mySqrt(int x) 
{
	int sum = 0;
	int i = 0;

	for(; i <= 46340; i++)
	{
		sum = i * i;

		if (sum == x)
			return i;
		if (sum > x)
			return i-1;
	}

	return i-1;
}

int mySqrt2(int x)
{
	if (x == 1)
		return 1;

	int first = 1;
	int last = x / 4;
	int mid;

	while (first <= last)
	{
		mid = first + (last - first) / 2;
		if (mid == x / mid)
			return mid;
		else if (mid > x / mid)
			last = mid - 1;
		else
			first = mid + 1;
	}

	return last;
}

int mySqrt3(int x)
{
	if (x == 1)
		return 1;

	float aprox = x;
	unsigned int  i = *(unsigned int*)&aprox;
	i -= 1 << 23;
	i >>= 1;
	i += 1 << 29;
	aprox = *(float*)&i;

	int first = std::max(1, (int)aprox / 2);
	int last = aprox;
	int mid;

	while (first <= last)
	{
		mid = first + (last - first) / 2;
		if (mid == x / mid)
			return mid;
		else if (mid > x / mid)
			last = mid - 1;
		else
			first = mid + 1;
	}

	return last;
}

/*
	int i1 = mySqrt2(4);
	int i2 = mySqrt2(8);
	int i3 = mySqrt2(INT_MAX);
*/