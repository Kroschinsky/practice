#pragma once

#include <vector>

/*
695. Max Area of Island [Medium]

You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) 
You may assume all four edges of the grid are surrounded by water.
The area of an island is the number of cells with a value 1 in the island.
Return the maximum area of an island in grid. If there is no island, return 0.

Example 1:
Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.

Example 2:
Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 50
grid[i][j] is either 0 or 1.
*/

void maxAreaOfIslandHelper(std::vector<std::vector<int>>& grid, int x, int y, int& count)
{
	int size_x = grid.size();
	int size_y = grid[0].size();

	if (x < 0 || y < 0 || x >= size_x || y >= size_y)
		return;

	grid[x][y] = 0;
	count++;

	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (i == j || (i != 0 && j != 0))
				continue;

			if (x + i < 0 || y + j < 0 || x + i >= size_x || y + j >= size_y)
				continue;

			if (grid[x + i][y + j] != 1)
				continue;

			grid[x + i][y + j] = 2;

			maxAreaOfIslandHelper(grid, x + i, y + j, count);
		}
	}
}

int maxAreaOfIsland(std::vector<std::vector<int>> grid)
{
	int size_x = grid.size();
	if (size_x == 0)
		return 0;

	int count;
	int ret = 0;

	int size_y = grid[0].size();

	for (int x = 0; x < size_x; x++)
	{
		for (int y = 0; y < size_y; y++)
		{
			if (grid[x][y] != 1)
				continue;

			count = 0;
			maxAreaOfIslandHelper(grid, x, y, count);

			if (count > ret)
				ret = count;
		}
	}

	return ret;
}

/*
	int i1 = maxAreaOfIsland({ {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0}, {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0} });
	int i2 = maxAreaOfIsland({ {0, 0, 0, 0, 0, 0, 0, 0} });
*/