#pragma once

#include <vector>
#include <set>

/*
268. Missing Number [Easy]

Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

Example 1:
Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.

Example 2:
Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.

Example 3:
Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.

Constraints:
n == nums.length
1 <= n <= 104
0 <= nums[i] <= n
All the numbers of nums are unique.
*/

int missingNumber(std::vector<int> nums)
{
	uint32_t size = nums.size();
	std::unordered_set<int> set(nums.begin(), nums.end());
	for (uint32_t i = 0; i <= size; i++)
	{
		if (set.find(i) == set.end())
			return i;
	}

	return 0;
}

int missingNumber2(std::vector<int> nums)
{
	uint32_t size = nums.size();
	uint32_t total = (1 + size) * (size / 2);
	if (size % 2 == 1)
		total += (size / 2) + 1;

	uint32_t sum = 0;
	for (int n : nums)
		sum += n;

	return total-sum;
}

int missingNumber3(std::vector<int> nums)
{
	uint32_t size = nums.size();
	uint32_t sum = size;
	for (uint32_t i = 0; i < size; i++)
	{
		sum += i;
		sum -= nums[i];
	}

	return sum;
}

/*
	int v1 = missingNumber3({ 3, 0, 1 });
	int v2 = missingNumber3({ 0, 1 });
	int v3 = missingNumber3({ 9, 6, 4, 2, 3, 5, 7, 0, 1 });
*/