#pragma once

#include <iostream>
#include <vector>
#include <string>

/*
Created: 28-02-23
1480. Running Sum of 1d Array [Easy]
Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

Return the running sum of nums.

Example 1:
Input: nums = [1,2,3,4]
Output: [1,3,6,10]
Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].

Example 2:
Input: nums = [1,1,1,1,1]
Output: [1,2,3,4,5]
Explanation: Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].

Example 3:
Input: nums = [3,1,2,10,1]
Output: [3,4,6,16,17]
*/

std::vector<int> runningSum(std::vector<int> nums)
{
	int sum = 0;
	int size = nums.size();
	std::vector<int> ret;
	ret.resize(size);	

	for (int i = 0; i < size; i++)
	{
		ret[i] = nums[i] + sum;
		sum += nums[i];
	}

	return ret;
}

std::vector<int> runningSum2(std::vector<int> nums)
{
	int sum = 0;
	std::vector<int> ret;
	for (int val : nums)
	{
		sum += val;
		ret.push_back(sum);
	}

	return ret;
}

/*
	auto v1 = runningSum({ 1,2,3,4 });			// 1,3,6,10
	auto v2 = runningSum({ 1,1,1,1,1 });		// 1,2,3,4,5
	auto v3 = runningSum({ 3,1,2,10,1 });		// 3,4,6,16,17
*/