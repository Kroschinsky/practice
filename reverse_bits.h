#pragma once

#include <cstdint>
#include <string>

/*
190. Reverse Bits [Easy]

Reverse bits of a given 32 bits unsigned integer.

Example 1:
Input: n = 00000010100101000001111010011100
Output:    964176192 (00111001011110000010100101000000)
Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596, so return 964176192 which its binary representation is 00111001011110000010100101000000.

Example 2:
Input: n = 11111111111111111111111111111101
Output:   3221225471 (10111111111111111111111111111111)
Explanation: The input binary string 11111111111111111111111111111101 represents the unsigned integer 4294967293, so return 3221225471 which its binary representation is 10111111111111111111111111111111.

Constraints:
The input must be a binary string of length 32
*/

uint32_t reverseBits(uint32_t n) 
{
	std::string r;
	for (int i = 31; i >= 0; i--)
	{
		uint32_t pow = std::pow(2, i);

		if (n >= pow)
		{
			n -= pow;
			r += "1";
		}
		else
			r += "0";
	}

	uint32_t ret = 0;
	for (int i = 0; i < 32; i++)
	{
		if (r[i] == '1')
			ret += std::pow(2, i);
	}

	return ret;
}

uint32_t reverseBits2(uint32_t n)
{
	uint32_t ret = 0;

	for (int i = 31; i >= 0; i--) 
	{
		if (n & (1 << i))
			ret = ret | (1 << (32 - i - 1));
	}

	return ret;
}

/*
	auto num1 = reverseBits2(43261596);
	auto num2 = reverseBits2(4294967293);
*/