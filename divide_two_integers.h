#pragma once

/*
29. Divide Two Integers [Medium]

Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.
The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.
Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. 
For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.

Example 1:
Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333.. which is truncated to 3.

Example 2:
Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = -2.33333.. which is truncated to -2.

Constraints:
-231 <= dividend, divisor <= 231 - 1
divisor != 0
*/

int divide(int dividend, int divisor) 
{
	if (dividend == 1 << 31 && divisor == -1)
		return INT_MAX;

	long long ret = 0;
	
	long long dvs = divisor;
	long long dvd = dividend;
	
	bool sign = false;
	if (dvd < 0)
	{
		sign = true;
		dvd = -dvd;
	}
	if (dvs < 0)
	{
		sign = !sign;
		dvs = -dvs;
	}	

	while (dvd - dvs >= 0)
	{
		int count = 0;	
		while (dvd - (dvs << 1 << count) >= 0)
			count++;

		ret += 1 << count;
		dvd -= dvs << count;
	}

	if (sign)
	{
		if (ret > INT_MAX)
			return INT_MAX;
		return ret;
	}

	if (-ret < INT_MIN)
		return INT_MIN;
	return -ret;
}

/*
	int i1 = divide(10,3);
	int i2 = divide(7,-3);
	int i3 = divide(0, 1);
	int i4 = divide(-2147483648, -1);
	int i5 = divide(2147483647, 1);
*/