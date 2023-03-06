#pragma once

#include <iostream>
#include <vector>
#include <string>

/*
88. Merge Sorted Array [Easy]

You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
Merge nums1 and nums2 into a single array sorted in non-decreasing order.
The final sorted array should not be returned by the function, but instead be stored inside the array nums1. 
To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

Example 1:
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

Example 2:
Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].

Example 3:
Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.

Constraints:
nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-109 <= nums1[i], nums2[j] <= 109
*/

void mergeSortedArray(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
{
	for (int i = 0; i < n; i++)
		nums1[i + m] = nums2[i];

	std::sort(nums1.begin(), nums1.end());
}

void mergeSortedArray2(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
{
	int last = m + n - 1;
	m--;
	n--;

	// merge in reverse order
	while (n >= 0)
	{
		if (m >= 0)
		{
			if (nums1[m] > nums2[n])
			{
				nums1[last] = nums1[m];
				m--;
			}
			else
			{
				nums1[last] = nums2[n];
				n--;
			}
		}
		else
		{
			nums1[last] = nums2[n];
			n--;
		}

		last--;
	}
}

/*
	std::vector<int> v1_1 = { 1,2,3,0,0,0 };
	std::vector<int> v2_1 = { 2,5,6 };
	mergeSortedArray2(v1_1, 3, v2_1, 3);         // { 1,2,2,3,5,6 }

	std::vector<int> v1_2 = { 1 };
	std::vector<int> v2_2 = {  };
	mergeSortedArray2(v1_2, 1, v2_2, 0);         // { 1 }

	std::vector<int> v1_3 = { 0 };
	std::vector<int> v2_3 = { 1 };
	mergeSortedArray2(v1_3, 0, v2_3, 1);         // { 1 }

	std::vector<int> v1_4 = { 2, 0 };
	std::vector<int> v2_4 = { 1 };
	mergeSortedArray2(v1_4, 1, v2_4, 1);         // { 1,2 }
*/