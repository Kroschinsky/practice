#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

/*
209. Minimum Size Subarray Sum [medium]

Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray
whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

Example 1:
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.

Example 2:
Input: target = 4, nums = [1,4,4]
Output: 1

Example 3:
Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0

Constraints:

1 <= target <= 109
1 <= nums.length <= 105
1 <= nums[i] <= 104
*/

int minSubArrayLen(int target, std::vector<int> nums) 
{
	int size = nums.size();

	int left = 0;
	int right = 0;

	int sum = nums[right];
	int sub = size + 1;

	while (left < size-1)
	{
		if (sum >= target)
		{
			if (sub > (right - left + 1))
				sub = right - left + 1;

			sum -= nums[left++];
		}
		else if (right == size - 1)
		{
			sum -= nums[left++];
		}
		else
		{
			sum += nums[right++];
		}
	}

	if (sum >= target)
	{
		if (sub > (right - left + 1))
			sub = right - left + 1;
	}

	if (sub > size)
		return 0;

	return sub;
}

int minSubArrayLen2(int target, std::vector<int> nums)
{
	int size = nums.size();
	int left = 0;
	int sum = 0;
	int minsub = size + 1;

	for (int right = 0; right < size; ++right) 
	{
		sum += nums[right];

		while (sum >= target) 
		{
			minsub = std::min(minsub, right - left + 1);
			sum -= nums[left++];
		}
	}

	if (minsub > size)
		return 0;

	return minsub;
}

/*
	int output_1 = minSubArrayLen(7, { 2,3,1,2,4,3 });          // 2
	int output_2 = minSubArrayLen(4, { 1,4,4});                 // 1
	int output_3 = minSubArrayLen(11, { 1,1,1,1,1,1,1,1 });     // 0
	int output_4 = minSubArrayLen(11, { 1, 2, 3, 4, 5 });       // 3
	int output_5 = minSubArrayLen(7, { 1, 1, 1, 1, 7 });        // 1
	int output_6 = minSubArrayLen(7, { 8 });                    // 1
*/