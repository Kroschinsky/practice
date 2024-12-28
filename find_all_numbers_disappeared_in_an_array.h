#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

/*
448. Find All Numbers Disappeared in an Array [easy]

Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.

Example 1:
Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]

Example 2:
Input: nums = [1,1]
Output: [2]

Constraints:
n == nums.length
1 <= n <= 105
1 <= nums[i] <= n
*/

std::vector<int> findDisappearedNumbers(std::vector<int> nums)
{
	int size = nums.size();

	std::vector<int> count(size, 0);
	for (int i = 0; i < size; ++i)
	{
		if (nums[i] - 1 >= size)
			continue;

		count[nums[i] - 1]++;
	}

	std::vector<int> ret;
	for (int i = 0; i < size; ++i)
	{
		if (count[i] == 0)
			ret.push_back(i+1);
	}

	return ret;
}

/*
	std::vector<int> output_1 = findDisappearedNumbers({ 4,3,2,7,8,2,3,1 });		// [5, 6]
	std::vector<int> output_2 = findDisappearedNumbers({ 1,1 });					// [2]
*/