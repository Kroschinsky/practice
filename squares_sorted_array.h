#pragma once

#include <iostream>
#include <vector>
#include <string>

/*
Created: 28-02-03

977. Squares of a Sorted Array [Easy]

Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

Example 1:
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].

Example 2:
Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
*/

std::vector<int> sortedSquares(std::vector<int> nums) 
{
	int size = nums.size();
	std::vector<int> ret;
	ret.resize(size);

	for (int i = 0; i < size; i++)
		ret[i] = nums[i] * nums[i];

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (ret[i] < ret[j])
			{
				int n1 = ret[i];
				int n2 = ret[j];

				ret[i] = n2;
				ret[j] = n1;
			}
		}
	}

	return ret;
}

// only works when the vector is sorted in non-decreasing order
std::vector<int> sortedSquares2(std::vector<int> nums)
{
	int size = nums.size();
	std::vector<int> ret(size, 0);

	int left = 0;
	int right = size - 1;

	for (int i = right; i >= 0; i--)
	{
		if (abs(nums[left]) > abs(nums[right]))
		{
			ret[i] = nums[left] * nums[left];
			left++;
		}
		else
		{
			ret[i] = nums[right] * nums[right];
			right--;
		}
	}

	return ret;
}

/*
	auto v1 = sortedSquares2({ -4,-1,0,3,10 });
	auto v2 = sortedSquares2({ -7,-3,2,3,11 });
*/