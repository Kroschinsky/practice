#pragma once

#include <vector>

/*
62. Unique Paths [Medium]

There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). 
The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

Example 1:
Input: m = 3, n = 7
Output: 28

Example 2:
Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down

Constraints:
1 <= m, n <= 100
*/

// Dynamic programming
int uniquePaths(int m, int n) 
{
	std::vector<int> row(n, 1);

	for (int i = 0; i < m - 1; i++)
	{
		std::vector<int> new_row(n, 1);

		for (int j = n - 2; j >= 0; j--)
			new_row[j] = new_row[j + 1] + row[j];

		row = new_row;
	}

	return row[0];
}

int uniquePaths2(int m, int n)
{
	int all = m + n - 2;
	int com = m - 1;
	long long ret = 1;

	for (int i = 1; i <= com; i++)
		ret = ret * (all + i - com) / i;

	return ret;
}

/*
	int i1 = uniquePaths(3, 7);
	int i2 = uniquePaths(3, 2);
	int i3 = uniquePaths(3, 3);
*/