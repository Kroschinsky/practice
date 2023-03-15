#pragma once

#include <vector>
#include <set>

/*
136. Single Number [Easy]

Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space.

Example 1:
Input: nums = [2,2,1]
Output: 1

Example 2:
Input: nums = [4,1,2,1,2]
Output: 4

Example 3:
Input: nums = [1]
Output: 1

Constraints:
1 <= nums.length <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104
Each element in the array appears twice except for one element which appears only once.
*/

int singleNumber(std::vector<int> nums)
{
	std::unordered_set<int> set;

	for (int n : nums)
	{
		auto it = set.find(n);
		if (it == set.end())
			set.insert(n);
		else
			set.erase(it);
	}

	return *set.begin();
}

// xor
int singleNumber2(std::vector<int> nums)
{
	int ret = 0;
	for (int n : nums)
		ret ^= n;

	return ret;
}

/*
	int i1 = singleNumber2({ 2,2,1 });
	int i2 = singleNumber2({ 4,1,2,1,2 });
	int i3 = singleNumber2({ 1 });
*/