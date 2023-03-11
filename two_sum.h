#pragma once

#include <vector>
#include <unordered_map>

/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]
*/

// brutal force
std::vector<int> twoSum(std::vector<int> nums, int target)
{
	int size = nums.size();

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == j)
				continue;

			if (nums[i] + nums[j] == target)
			{
				return { i,j };
			}
		}
	}

	return std::vector<int>();
}

std::vector<int> twoSum2(std::vector<int> nums, int target)
{
	std::vector<int> ret;
	std::unordered_map<int, int> map;
	int size = nums.size();
	int diff = 0;

	for (int i = 0; i < size; i++)
	{
		diff = target - nums[i];
		auto pair = map.find(diff);
		if (pair != map.end())
		{
			ret.push_back(pair->second);
			ret.push_back(i);
			break;
		}

		map[nums[i]] = i;
	}

	return ret;
}

/*
auto val1 = twoSum2({ 2,7,11,15 }, 9);
auto val2 = twoSum2({ 3,2,4 }, 6);
auto val3 = twoSum2({ 3,3 }, 6);
*/