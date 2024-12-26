#pragma once

#include <iostream>
#include <vector>
#include <string>


/*
45. Jump Game II [medium]

You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].
Each element nums[i] represents the maximum length of a forward jump from index i. 
In other words, if you are at nums[i], you can jump to any nums[i + j] where:
0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

Example 1:
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: nums = [2,3,0,1,4]
Output: 2

Constraints:
1 <= nums.length <= 104
0 <= nums[i] <= 1000
It's guaranteed that you can reach nums[n - 1].
*/

int jump(std::vector<int> nums)
{
	int size = nums.size();
	if (size <= 1)
		return 0;

	int best_index = 0;
	int jumps = 0;
	int count = 0;
	int start = 0;

	while (start < size - 1)
	{
		best_index = start + 1;
		jumps = nums[start];

		if (jumps + start >= size - 1)
			return ++count;

		for (int i = 1; i < jumps; ++i)
		{
			if ((i + start + 1) >= size)
				return ++count;

			if (nums[i + start + 1] == 0)
				continue;

			if ((i + start + 1) + nums[i + start + 1] >= nums[best_index] + best_index)
			{
				best_index = i + start + 1;
			}
		}

		//std::cout << nums[best_index] << std::endl;

		start = best_index;
		++count;
	}

	return count;
}

int jump2(std::vector<int> nums)
{
	int size = nums.size();
	if (size < 2)
		return 0;

	int reach = 0;
	int jump = 0;
	int jumps = 0;

	for (int i = 0; i < size; ++i)
	{
		reach = std::max(reach, i + nums[i]);
		if (reach >= size - 1) 		
		{
			return jumps + 1;
		}

		if (i == jump) 
		{
			jumps++;
			jump = reach;
		}
	}

	return jumps;
}