#pragma once

#include <vector>
#include <map>

/*
169. Majority Element [Easy]

Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. 
You may assume that the majority element always exists in the array.

Example 1:
Input: nums = [3,2,3]
Output: 3

Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2

Constraints:
n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
*/

int majorityElement(std::vector<int> nums)
{
	int size = nums.size();
	std::unordered_map<int, int> map;

	for (int n : nums)
		map[n]++;

	for (auto pair : map)
	{
		if (pair.second > size / 2)
			return pair.first;
	}

	return 0;
}

/*
	int i1 = majorityElement({ 3,2,3 });
	int i2 = majorityElement({ 2,2,1,1,1,2,2 });
*/