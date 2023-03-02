#pragma once

#include <iostream>
#include <vector>
#include <string>

/*
Created: 27-02-23

704. Binary Search [Easy]

Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. 
If target exists, then return its index. Otherwise, return -1.
You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4

Example 2:
Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
*/

int binary_search(std::vector<int> nums, int target) 
{
	int size = nums.size();
	for (int i = 0; i < size; i++)
	{
		if (nums[i] == target)
			return i;
	}

	return -1;
}

int binary_search2(std::vector<int> nums, int target)
{
	int size = nums.size();
	if (size == 0)
		return -1;

	int index = size / 2;
	int div = index;

	while (true)
	{
		if (nums[index] == target)
			return index;

		if (div / 2 == 0)
		{
			while (index > 0)
			{
				index--;
				if (nums[index] == target)
					return index;

				if (nums[index] < target)
					break;
			}
			
			while (index < size-1)
			{
				index++;
				if (nums[index] == target)
					return index;

				if (nums[index] > target)
					break;
			}

			break;
		}

		div -= div / 2;
		if (nums[index] > target)
			index -= div;
		else
			index += div;
	}

	return -1;
}

/*
	int v1 = binary_search2({ -1,0,3,5,9,12 }, 9);           // 4
	int v2 = binary_search2({ -1,0,3,5,9,12 }, 2);           // -1
	int v3 = binary_search2({ 2,5 }, 2);                     // 0
	int v4 = binary_search2({ -1,0,5}, 5);                   // 2
	int v5 = binary_search2({ -1,0,3,5,9,12 }, -1);          // 0
*/