#pragma once

#include <vector>
#include <unordered_map>

/*
350. Intersection of Two Arrays II [Easy]

Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]

Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.

Constraints:
1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000
*/

std::vector<int> intersect(std::vector<int> nums1, std::vector<int> nums2) 
{
	std::vector<int> ret;
	std::unordered_map<int, int> map;

	for (int n : nums1)
		map[n]++;

	for (int n : nums2)
	{
		if (map[n] > 0)
		{
			map[n]--;
			ret.push_back(n);
		}
	}

	return ret;
}

/*
	auto vec1 = intersect({ 1,2,2,1 }, { 2,2 });
	auto vec2 = intersect({ 4,9,5 }, { 9,4,9,8,4 });
*/