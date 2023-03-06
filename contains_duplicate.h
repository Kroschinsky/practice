#pragma once

#include <vector>
#include <set>

/*
217. Contains Duplicate [Easy]
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

Example 1:
Input: nums = [1,2,3,1]
Output: true

Example 2:
Input: nums = [1,2,3,4]
Output: false

Example 3:
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true

Constraints:
1 <= nums.length <= 105
-109 <= nums[i] <= 109
*/


// slow
bool containsDuplicate(std::vector<int> nums) 
{
	int size = nums.size();

	for (int i = 0; i < size; i++)
	{
		for (int j = i+1; j < size; j++)
		{
			if (nums[i] == nums[j])
				return true;
		}
	}
	
	return false;
}

bool containsDuplicate2(std::vector<int> nums)
{
	int size = nums.size();

	std::map<int, int> map;
	for (int num : nums)
	{
		map[num]++;

		if (map[num] > 1)
			return true;
	}

	return false;
}

bool containsDuplicate3(std::vector<int> nums)
{
	int size = nums.size();

	sort(nums.begin(), nums.end());

	for (int i = 0; i < size - 1; i++)
	{
		if (nums[i] == nums[i+1])
			return true;
	}

	return false;
}

/*
	bool b1 = containsDuplicate3({ 1,2,3,1 });
	bool b2 = containsDuplicate3({ 1,2,3,4 });
	bool b3 = containsDuplicate3({ 1,1,1,3,3,4,3,2,4,2 });
*/