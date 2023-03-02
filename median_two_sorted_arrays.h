#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <set>

/*
Created : 26-02-23

Median of Two Sorted Arrays

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).

Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
*/

double findMedianSortedArrays(std::vector<int> nums1, std::vector<int> nums2)
{
	double ret = 0;

	int m = nums1.size();
	int n = nums2.size();
	int size = m + n;

	int n1 = 0;
	int n2 = 0;
	std::vector<int> merge;

	for (int i = 0; i <= (size / 2); i++)
	{
		if (m <= n1)
		{
			merge.push_back(nums2[n2]);
			n2++;
			continue;
		}

		if (n <= n2)
		{
			merge.push_back(nums1[n1]);
			n1++;
			continue;
		}

		if (nums1[n1] < nums2[n2])
		{
			merge.push_back(nums1[n1]);
			n1++;
		}
		else
		{
			merge.push_back(nums2[n2]);
			n2++;
		}
	}
	
	if (size % 2 == 0)
	{
		ret = merge[(size / 2) - 1];
		ret += merge[size / 2];
		ret /= 2;
	}
	else
	{
		ret = merge[size / 2];
	}	

	return ret;
}

double findMedianSortedArrays2(std::vector<int> nums1, std::vector<int> nums2)
{
	int m = nums1.size();
	int n = nums2.size();
	int size = m + n;

	int n1 = 0;
	int n2 = 0;
	int l1 = 0;
	int l2 = 0;

	for (int i = 0; i <= (size / 2); i++)
	{
		l2 = l1;

		if (m <= n1)
		{
			l1 = nums2[n2];
			n2++;
			continue;
		}

		if (n <= n2)
		{
			l1 = nums1[n1];
			n1++;
			continue;
		}

		if (nums1[n1] < nums2[n2])
		{
			l1 = nums1[n1];
			n1++;
		}
		else
		{
			l1 = nums2[n2];
			n2++;
		}
	}

	if (size % 2 == 0)
	{
		double ret = l1;
		ret += l2;
		return ret /= 2;
	}

	return l1;
}

/*
	auto v1 = findMedianSortedArrays({ 1,3 }, { 2 });       // {1,2,3}      =>  2
	auto v2 = findMedianSortedArrays({ 1,2 }, { 3,4 });     // {1,2,3,4}    =>  2 + 3 / 2 = 2.5
	auto v3 = findMedianSortedArrays({ 1,3 }, { 2,7 });     // {1,2,3,7}    =>  2 + 3 / 2 = 2.5
	auto v4 = findMedianSortedArrays({ 1,1 }, { 1,2 });     // {1,1,1,2}    =>  1 + 1 / 2 = 1
*/