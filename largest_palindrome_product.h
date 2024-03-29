#pragma once

#include "palindrome_number.h"

/*
Largest palindrome product

A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 � 99.
Find the largest palindrome made from the product of two 3-digit numbers.
*/

// brutal force
int largestPalindromeProduct()
{
	std::set<int> palinds;

	for (int i = 100; i < 1000; i++)
	{
		for (int j = 100; j < 1000; j++)
		{
			int product = i * j;

			if (isPalindrome(product))
				palinds.insert(product);
		}
	}	

	return (*palinds.rbegin());
}

// int num = largestPalindromeProduct();