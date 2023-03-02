#pragma once

#include <iostream>
#include <vector>
#include <string>

/*
Created: 27-02-23

35. Search Insert Position [Easy]
Given a sorted array of distinct integers and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.
You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2

Example 2:
Input: nums = [1,3,5,6], target = 2
Output: 1

Example 3:
Input: nums = [1,3,5,6], target = 7
Output: 4
*/

int searchInsert(std::vector<int> nums, int target) 
{
	int size = nums.size();

	for (int i = 0; i < size; i++)
	{
		if (nums[i] >= target)
			return i;
	}

	return size;
}

int searchInsert2(std::vector<int> nums, int target)
{
	int size = nums.size();
	if (size > 0 && nums[0] >= target)
		return 0;

	int mid;
	int e = 1;
	int d = size;

	while (e <= d)
	{
		mid = e + (d - e) / 2;
		if (mid >= size)
			return size;

		if (nums[mid] == target)
			return mid;

		if (nums[mid] > target)
		{
			if (nums[mid - 1] < target)
				return mid;

			d = mid - 1;			
		}
		else
		{
			e = mid + 1;
		}
	}

	return size;
}

/*
    int v1 = searchInsert2({ 1,3,5,6 }, 5);      // 2
    int v2 = searchInsert2({ 1,3,5,6 }, 2);      // 1
    int v3 = searchInsert2({ 1,3,5,6 }, 7);      // 4
    int v4 = searchInsert2({ 1,3,5,6 }, 1);      // 0
*/