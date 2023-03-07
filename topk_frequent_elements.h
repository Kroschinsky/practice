#pragma once

#include <vector>

/*
347. Top K Frequent Elements [Medium]

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]

Constraints:
1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

std::vector<int> topKFrequent(std::vector<int> nums, int k) 
{
	int size = nums.size();
	std::vector<int> ret;

	std::unordered_map<int, int> map;

	for (int i = 0; i < size; i++)
		map[nums[i]]++;

	for (int i = 0; i < k; i++)
	{
		int freq = 0;
		int num = 0;

		for (auto& pair : map)
		{
			if (pair.second > freq)
			{
				num = pair.first;
				freq = pair.second;
			}
		}

		map[num] = 0;
		ret.push_back(num);
	}

	return ret;
}

// Bucket Sort
std::vector<int> topKFrequent2(std::vector<int> nums, int k)
{
	std::vector<int> ret;
	std::unordered_map<int, int> map;
	std::multimap<int, int> multimap;

	for (int num : nums)
		map[num]++;

	for (auto& pair : map)
		multimap.insert(std::make_pair(pair.second, pair.first));

	int i = 0;
	for (auto it = multimap.rbegin(); i < k && it != multimap.rend(); it++, i++)
		ret.push_back(it->second);

	return ret;
}

/*
	auto v1 = topKFrequent2({ 1,1,1,2,2,3 }, 2);
	auto v2 = topKFrequent2({ 1 }, 1);
	auto v3 = topKFrequent2({ -1,-1 }, 1);
*/