#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_set>

/*
135. Candy [hard]

There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.
You are giving candies to these children subjected to the following requirements:
Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.

Example 1:
Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.

Example 2:
Input: ratings = [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
The third child gets 1 candy because it satisfies the above two conditions.

Constraints:
n == ratings.length
1 <= n <= 2 * 104
0 <= ratings[i] <= 2 * 104
*/

int candy(std::vector<int> ratings)
{
	int size = ratings.size();
	std::vector<int> count(size, 1);

	// right
	for (int i = 1; i < size; ++i)
	{
		if (ratings[i] > ratings[i - 1])
			count[i] = count[i - 1] + 1;
	}

	// left
	for (int i = size - 2; i >= 0; --i)
	{
		if (ratings[i] > ratings[i + 1])
			count[i] = std::max(count[i], count[i + 1] + 1);
	}

	int ret = 0;
	for (int& value : count)
		ret += value;

	//std::accumulate(count.begin(), count.end(), 0);

	return ret;
}

/*
	int output_1 = candy({ 1,0,2 });            // 5
	int output_2 = candy({ 1,2,2 });            // 4
	int output_3 = candy({ 1,3,2,2,1 });        // 7
	int output_4 = candy({ 1,2,7,7,7,2,1 });    // 13
	int output_5 = candy({ 1,3,4,5,2 });        // 11
*/