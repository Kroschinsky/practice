#pragma once

#include <vector>

/*
15. 3Sum [Medium]

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

Example 2:
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.

Example 3:
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.

Constraints:
3 <= nums.length <= 3000
-105 <= nums[i] <= 105
*/

std::vector<std::vector<int>> threeSum(std::vector<int> nums) 
{
	std::vector<std::vector<int>> ret;
	int size = nums.size();

	int l, r, sum;

	std::sort(nums.begin(), nums.end());

	for (int i = 0; i < size - 2; i++)
	{
		if (i > 0 && nums[i] == nums[i - 1]) 
			continue;

		l = i + 1;
		r = size - 1;

		while (l < r)
		{
			sum = nums[i] + nums[l] + nums[r];
			if (sum > 0)
				r--;
			else if (sum < 0)
				l++;
			else
			{
				ret.push_back({ nums[i] , nums[l] , nums[r] });
				l++;

				while(nums[l] == nums[l-1] && l < r)
					l++;
			}
		}
	}

	return ret;
}

/*
	auto v1 = threeSum({ -1,0,1,2,-1,-4 });
	auto v2 = threeSum({ 0,1,1 });
	auto v3 = threeSum({ 0,0,0 });
*/