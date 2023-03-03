#pragma once

#include <iostream>
#include <vector>
#include <string>

/*
Created: 01-03-23

283. Move Zeroes [Easy]

Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.

Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Example 2:
Input: nums = [0]
Output: [0]
*/

void moveZeroes(std::vector<int>& nums) 
{
	int size = nums.size();
	int zeros = 0;

	for (int i = size-1; i >= 0; i--)
	{
		if (nums[i] != 0)
			continue;

		zeros++;

		for (int j = i; j < size - zeros; j++)
			nums[j] = nums[j + 1];

		nums[size - zeros] = 0;
	}
}

void moveZeroes2(std::vector<int>& nums)
{
	int size = nums.size();
	int zeros = 0;

	for (int i = 0; i < size; i++)
	{
		if (nums[i] == 0)
			continue;

		nums[zeros] = nums[i];
		zeros++;
	}

	if (zeros > 0)
		memset(&nums[(size - (size - zeros))], 0, (size - zeros) * sizeof nums[0]);
}

// less moves
void moveZeroes3(std::vector<int>& nums)
{
	int size = nums.size();
	int z = 0;

	for (int i = 0; i < size; i++)
	{
		if (nums[i] == 0)
			continue;

		//std::swap(nums[z], nums[i]);
		nums[z] = nums[i];
		nums[i] = 0;

		z++;
	}
}

/*
	std::vector<int> v1 = { 0,1,0,3,12 };
	moveZeroes3(v1);

	std::vector<int> v2 = { 0 };
	moveZeroes3(v2);
*/