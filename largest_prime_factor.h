#pragma once

/*
Largest prime factor
The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143 ?
*/

long long largest_prime_factor(long long value)
{
	std::vector<long long> primes;
	primes.push_back(2);

	long long max_value = sqrt(value);

	for (long long i = 3; i < max_value; i++)
	{
		if (i % 2 == 0)
			continue;

		bool find = false;

		for (long long v : primes)
		{
			if (i % v == 0)
			{
				find = true;
				break;
			}
		}

		if (!find)
			primes.push_back(i);
	}

	for (auto it = primes.rbegin(); it != primes.rend(); it++)
	{
		if ((value % (*it)) == 0)
		{
			std::cout << (*it);
			return (*it);
		}
	}

	return 0;
}

/*
auto value = largest_prime_factor(600851475143);
*/