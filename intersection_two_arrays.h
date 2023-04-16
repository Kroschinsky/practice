#pragma once

#include <vector>
#include <unordered_map>
#include <algorithm>

/*
349. Intersection of Two Arrays [Easy]

Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.

Constraints:
1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000
*/

std::vector<int> intersection(std::vector<int> nums1, std::vector<int> nums2) 
{
	std::vector<int> ret;

	int size1 = nums1.size();
	int size2 = nums2.size();

	std::sort(nums1.begin(), nums1.end());
	std::sort(nums2.begin(), nums2.end());

	int i1 = 0;
	int i2 = 0;
	int val = -1;
	
	while (true)
	{
		if (i1 == size1 || i2 == size2)
			break;

		if (nums1[i1] == val)
		{
			i1++;
			continue;
		}

		if (nums2[i2] == val)
		{
			i2++;
			continue;
		}

		if (nums1[i1] == nums2[i2])
		{
			val = nums1[i1];
			ret.push_back(nums1[i1]);
		}
		else if (nums1[i1] < nums2[i2])
			i1++;
		else
			i2++;
	}

	return ret;
}

std::vector<int> intersection2(std::vector<int> nums1, std::vector<int> nums2)
{
	std::vector<int> ret;
	std::unordered_map<int, int> map;
	for (int i : nums1)
		map[i] = 1;

	for (int i : nums2)
	{
		auto it = map.find(i);
		if (it == map.end())
			continue;

		if (it->second == 1)
		{
			it->second = 0;
			ret.push_back(i);
		}
	}

	return ret;
}


/*
	auto v1 = intersection2({ 1,2,2,1 }, {2,2});
	auto v2 = intersection2({ 4,9,5 }, { 9,4,9,8,4 });
*/