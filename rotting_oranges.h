#pragma once

#include <vector>
#include <queue>

/*
994. Rotting Oranges [Medium]

You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

Example 1:
Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4

Example 2:
Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

Example 3:
Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.
*/

// BFS
int orangesRotting(std::vector<std::vector<int>> grid)
{
	int m = grid.size();
	int n = grid[0].size();

	std::queue<std::pair<int, int>> q;
	int time = 0;
	int fresh = 0;
	int row, col;

	for (int x = 0; x < m; x++)
	{
		for (int y = 0; y < n; y++)
		{
			if (grid[x][y] == 1)
				fresh++;
			else if (grid[x][y] == 2)
				q.push(std::make_pair(x, y));
		}
	}

	std::vector<int> dir = { 0, 1, 0, -1, 0 };
	
	while (!q.empty() && fresh > 0)
	{
		int size_q = q.size();

		for(int i = 0; i < size_q; i++)
		{
			auto [r, c] = q.front();

			q.pop();

			for (int d = 0; d < 4; d++)
			{
				row = r + dir[d];
				col = c + dir[d + 1];

				if (row < 0 || row == m || col < 0 || col == n || grid[row][col] != 1)
					continue;

				fresh--;
				grid[row][col] = 2;
				q.push(std::make_pair(row, col));
			}
		}

		time++;
	}

	if (fresh > 0)
		return -1;

	return time;
}

/*
	int i1 = orangesRotting({ { 2,1,1 }, { 1,1,0 }, { 0,1,1 } });
	int i2 = orangesRotting({ { 2,1,1 }, { 0,1,1 }, { 1,0,1 } });
	int i3 = orangesRotting({ { 0,2 } });
*/