#pragma once

#include <cstdint>
#include <algorithm>

/*
191. Number of 1 Bits [Easy]

Write a function that takes the binary representation of an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

Example 1:
Input: n = 00000000000000000000000000001011
Output: 3
Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.

Example 2:
Input: n = 00000000000000000000000010000000
Output: 1
Explanation: The input binary string 00000000000000000000000010000000 has a total of one '1' bit.

Example 3:
Input: n = 11111111111111111111111111111101
Output: 31
Explanation: The input binary string 11111111111111111111111111111101 has a total of thirty one '1' bits.

Constraints:
The input must be a binary string of length 32.
*/

int HammingWeight(uint32_t n)
{
	uint32_t bits = 0;

	for (int32_t i = 32; i >= 0; i--)
	{
		uint64_t pow = std::pow(2, i);
		if (n >= pow)
		{
			bits++;
			n -= pow;

			if (n == 0)
				break;
		}
	}

	return bits;
}

int HammingWeight2(uint32_t n)
{
	int bits = 0;

	while (n != 0)
	{
		if (n & 1)
			bits++;
		n = n >> 1;
	}

	return bits;
}

/*
	int val1 = HammingWeight2(11);           // 00000000000000000000000000001011
	int val2 = HammingWeight2(128);          // 00000000000000000000000010000000
	int val3 = HammingWeight2(4294967293);   // 11111111111111111111111111111101
*/