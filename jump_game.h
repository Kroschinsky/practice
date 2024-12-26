#pragma once

#include <iostream>
#include <vector>
#include <string>


/*
55. Jump Game [medium]

You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
Return true if you can reach the last index, or false otherwise.

Example 1:
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

Constraints:
1 <= nums.length <= 104
0 <= nums[i] <= 105
*/

bool canJump(std::vector<int> nums) 
{
	int size = nums.size();
	if (size <= 1)
		return true;

	int start = 0;

	while (start < size-1)
	{
		int best_index = start + 1;
		int jumps = nums[start];

		if (jumps == 0)
			return false;

		if (jumps + start >= size-1)
			return true;

		for (int i = 1; i < jumps; ++i)
		{
			if ((i + start + 1) >= size)
				return true;

			if (nums[i + start + 1] == 0)
				continue;

			if ((i + start + 1) + nums[i + start + 1] >= nums[best_index] + best_index)
			{
				best_index = i + start + 1;
			}
		}

		//std::cout << nums[best_index] << std::endl;

		start = best_index;
	}

	return true;
}

bool canJump2(std::vector<int> nums)
{
	int i = 0;
	int size = nums.size();

	for (int reach = 0; i < size && i <= reach; ++i)
		reach = std::max(reach, i + nums[i]);

	return i == size;
}

/*
	bool output_1 = canJump2({ 2,3,1,1,4 });     // true
	bool output_2 = canJump2({ 3,2,1,0,4 });     // false
	bool output_3 = canJump2({ 2, 0 });          // true
	bool output_4 = canJump2({ 2, 0, 0 });       // true
	bool output_5 = canJump2({ 2, 1, 0, 0 });    // false
	bool output_6 = canJump2({ 1,1,1,1 });       // true
	bool output_7 = canJump2({ 5,9,3,2,1,0,2,3,3,1,0,0 });       // true
	bool output_8 = canJump2({ 4,2,0,0,1,1,4,4,4,0,4,0 });       // true
*/