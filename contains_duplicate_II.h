#pragma once

#include <vector>
#include <unordered_set>
#include <algorithm>

/*
219. Contains Duplicate II [Easy]

Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

Example 1:
Input: nums = [1,2,3,1], k = 3
Output: true

Example 2:
Input: nums = [1,0,1,1], k = 1
Output: true

Example 3:
Input: nums = [1,2,3,1,2,3], k = 2
Output: false

Constraints:
1 <= nums.length <= 105
-109 <= nums[i] <= 109
0 <= k <= 105
*/

// window sliding
bool containsNearbyDuplicate(std::vector<int> nums, int k) 
{
	int size = nums.size();
	std::unordered_set<int> set;
	int left = 0;

	for (int right = 0; right < size; right++)
	{
		// move window to left
		if (right - left > k)
		{
			set.erase(nums[left]);
			left++;
		}

		auto it = set.find(nums[right]);
		if (it != set.end())
			return true;

		set.insert(nums[right]);
	}

	return false;
}

/*
	bool b1 = containsNearbyDuplicate({ 1,2,3,1 }, 3);
	bool b2 = containsNearbyDuplicate({ 1,0,1,1 }, 1);
	bool b3 = containsNearbyDuplicate({ 1,2,3,1,2,3 }, 2);
*/