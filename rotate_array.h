#pragma once

#include <iostream>
#include <vector>
#include <string>

/*
Created: 28-02-23

189. Rotate Array [Medium]

Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

Example 1:
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation:
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
*/

void rotate_array_helper(std::vector<int>& nums)
{
	int size = nums.size();
	int index = 0;
	int old = 0;
	int curr = nums[0];

	for (int i = 0; i < size; i++)
	{
		index += 1;
		if (index > size - 1)
			index -= size;

		old = nums[index];
		nums[index] = curr;
		curr = old;
	}
}

// slow
void rotate_array(std::vector<int>& nums, int k) 
{
	if (k == 0)
		return;

	int size = nums.size();
	if (size == 1)
		return;

	k %= size;

	while (k > 0)
	{
		rotate_array_helper(nums);
		k--;
	}
}

void reverse_array(std::vector<int>& nums, int left, int right)
{
	int temp;

	while (left < right)
	{
		temp = nums[left];
		nums[left] = nums[right];
		nums[right] = temp;

		left++;
		right--;
	}
}

void rotate_array2(std::vector<int>& nums, int k)
{
	int size = nums.size();
	k %= size;

	reverse_array(nums, 0, size - 1);
	reverse_array(nums, 0, k - 1);
	reverse_array(nums, k, size - 1);
}

/*
	std::vector<int> v1 = { 1,2,3,4,5,6,7 };
	rotate_array2(v1, 3);

	std::vector<int> v2 = { -1,-100,3,99 };
	rotate_array2(v2, 2);

	std::vector<int> v3 = { 1,2,3,4,5,6 };
	rotate_array2(v3, 3);

	std::vector<int> v4 = { 1,2 };
	rotate_array2(v4, 3);
*/