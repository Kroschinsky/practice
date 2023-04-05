#pragma once

/*
326. Power of Three [Easy]

Given an integer n, return true if it is a power of three. Otherwise, return false.
An integer n is a power of three, if there exists an integer x such that n == 3x.

Example 1:
Input: n = 27
Output: true
Explanation: 27 = 33

Example 2:
Input: n = 0
Output: false
Explanation: There is no x where 3x = 0.

Example 3:
Input: n = -1
Output: false
Explanation: There is no x where 3x = (-1).

Constraints:
-231 <= n <= 231 - 1
*/

bool isPowerOfThree(int n) 
{
	if (n <= 0)
		return false;

	uint32_t x = 1;

	while (true)
	{
		if (x == n)
			return true;
		else if (x > n)
			return false;

		x *= 3;
	}

	return false;
}

/*
	bool b1 = isPowerOfThree(27);
	bool b2 = isPowerOfThree(0);
	bool b3 = isPowerOfThree(-1);
	bool b4 = isPowerOfThree(1);
	bool b5 = isPowerOfThree(-27);
	bool b6 = isPowerOfThree(1162261468);
	bool b7 = isPowerOfThree(-3);
*/
