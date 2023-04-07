#pragma once

#include <vector>
#include <string>

/*
412. Fizz Buzz [Easy]

Given an integer n, return a string array answer (1-indexed) where:
answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
answer[i] == "Fizz" if i is divisible by 3.
answer[i] == "Buzz" if i is divisible by 5.
answer[i] == i (as a string) if none of the above conditions are true.

Example 1:
Input: n = 3
Output: ["1","2","Fizz"]

Example 2:
Input: n = 5
Output: ["1","2","Fizz","4","Buzz"]

Example 3:
Input: n = 15
Output: ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]

Constraints:
1 <= n <= 104
*/

std::vector<std::string> fizzBuzz(int n) 
{
	std::vector<std::string> ret;

	int c3 = 0;
	int c5 = 0;

	for (int i = 1; i <= n; i++)
	{
		c3++;
		c5++;

		if (c3 == 3 && c5 == 5)
		{
			c3 = 0;
			c5 = 0;
			ret.push_back("FizzBuzz");
		}
		else if (c3 == 3)
		{
			c3 = 0;
			ret.push_back("Fizz");
		}
		else if (c5 == 5)
		{
			c5 = 0;
			ret.push_back("Buzz");
		}
		else
		{
			ret.push_back(std::to_string(i));
		}
	}

	return ret;
}

/*
	auto v1 = fizzBuzz(3);
	auto v2 = fizzBuzz(5);
	auto v3 = fizzBuzz(15);
*/
