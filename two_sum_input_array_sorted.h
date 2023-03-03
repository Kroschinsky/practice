#pragma once

#include <iostream>
#include <vector>
#include <string>

/*
Created: 01-03-23

167. Two Sum II - Input Array Is Sorted [Medium]

Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. 
Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.
Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.
The tests are generated such that there is exactly one solution. You may not use the same element twice.
Your solution must use only constant extra space.

Example 1:
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].

Example 2:
Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].

Example 3:
Input: numbers = [-1,0], target = -1
Output: [1,2]
Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].
*/

// simply but slow
std::vector<int> twoSumArraySorted(std::vector<int> numbers, int target)
{
	int size = numbers.size();

	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (numbers[i] + numbers[j] == target)
				return { i + 1 , j + 1 };
		}
	}

	return std::vector<int>();
}

std::vector<int> twoSumArraySorted2(std::vector<int> numbers, int target)
{
	int size = numbers.size();

	int sum;
	int left = 0;
	int right = size - 1;
	
	while (left < right)
	{
		sum = numbers[left] + numbers[right];

		if (sum < target)
			left++;
		else if (sum > target)
			right--;
		else
		{
			return { left + 1, right + 1 };

			break;
		}
	}

	return {};
}

/*
	auto v1 = twoSumArraySorted2({ 2,7,11,15 }, 9);
	auto v2 = twoSumArraySorted2({ 2,3,4 }, 6);
	auto v3 = twoSumArraySorted2({ -1,0 }, -1);
*/