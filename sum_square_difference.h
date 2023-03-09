#pragma once

/*
Sum square difference
The sum of the squares of the first ten natural numbers is, 1^2 + 2^2 ... + 10^2 = 385
The square of the sum of the first ten natural numbers is, (1 + 2 + 3 ... +10)^2 = 55^2 = 3025
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is.
3025 - 385 = 2640
Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/

long long sumSquareDifference(int value)
{
	long long sum1 = 0;
	long long sum2 = 0;

	for (int i = 1; i <= value; i++)
	{
		sum1 += i * i;
		sum2 += i;
	}

	sum2 *= sum2;

	return sum2-sum1;
}

/*
auto value = sumSquareDifference(100);		// 25164150
*/