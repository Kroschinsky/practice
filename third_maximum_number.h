#pragma once

#include <vector>
#include <set>
#include <algorithm>

/*
414. Third Maximum Number [Easy]

Given an integer array nums, return the third distinct maximum number in this array. If the third maximum does not exist, return the maximum number.

Example 1:
Input: nums = [3,2,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2.
The third distinct maximum is 1.

Example 2:
Input: nums = [1,2]
Output: 2
Explanation:
The first distinct maximum is 2.
The second distinct maximum is 1.
The third distinct maximum does not exist, so the maximum (2) is returned instead.

Example 3:
Input: nums = [2,2,3,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2 (both 2's are counted together since they have the same value).
The third distinct maximum is 1.

Constraints:
1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
*/

int thirdMax(std::vector<int> nums) 
{
	std::set<int> set;

	for (int n : nums)
		set.insert(n);

	if (set.size() < 3)
		return *set.rbegin();

	int ret = 0;
	int i = 0;
	for (auto it = set.rbegin(); it != set.rend() && i < 3; it++, i++)
		ret = (*it);

	return ret;
}

int thirdMax2(std::vector<int> nums)
{
	std::sort(nums.rbegin(), nums.rend());
	nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
	if (nums.size() < 3)
		return nums[0];

	return nums[2];
}

/*
	int i1 = thirdMax2({ 3,2,1 });
	int i2 = thirdMax2({ 1,2 });
	int i3 = thirdMax2({ 2,2,3,1 });
*/