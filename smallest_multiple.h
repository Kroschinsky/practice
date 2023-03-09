#pragma once

#include <vector>

/*
* Smallest multiple
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

long long smallestMultiple()
{
	int end = 20;
	std::vector<int> primes = { 2,3,5,7,11,13,17,19,23,29 };

	long long min = 1;
	int i = 0;
	while (true)
	{
		if (primes[i] > end)
			break;

		min *= primes[i];

		i++;
	}

	for (int i = 4; i <= end; i++)
	{
		int rest = min % i;
		if (rest != 0)
		{
			int prime = 0;
			for (int e : primes)
			{
				if (i % e == 0)
				{
					prime = e;
					break;
				}
			}

			while (true)
			{
				int rest = min % i;
				if (rest == 0)
					break;

				min *= prime;
			}
		}
	}

	return min;
}