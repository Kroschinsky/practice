#pragma once

#include <vector>

/*
11. Container With Most Water [Medium]

You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.

Example 1:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

Example 2:
Input: height = [1,1]
Output: 1
*/

// brutal force o(n^2)
int containeMmaxArea(std::vector<int> height)
{
	int size = height.size();
	int max = 0;
	int area;

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			area = std::min(height[i], height[j]) * (j - i);
			max = std::max(area, max);
		}
	}

	return max;
}


int containeMmaxArea2(std::vector<int> height)
{
	int left = 0;
	int right = height.size() - 1;
	int max = 0;
	int area;

	while (right > left)
	{
		area = std::min(height[left], height[right]) * (right - left);
		max = std::max(area, max);
		
		if (height[left] > height[right])
			right--;
		else
			left++;
	}

	return max;
}

/*
	int i1 = containeMmaxArea2({ 1,8,6,2,5,4,8,3,7 });
	int i2 = containeMmaxArea2({ 1,1 });
*/