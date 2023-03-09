#pragma once

#include <vector>

/*
200. Number of Islands [Medium]

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.

Example 1:
Input: grid = 
[
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:
Input: grid = 
[
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.
*/

void numIslandsHelper(std::vector<std::vector<char>>& grid, int x, int y, int& count)
{
	int size_x = grid.size();
	int size_y = grid[0].size();

	if (x < 0 || y < 0 || x >= size_x || y >= size_y)
		return;

	grid[x][y] = '0';
	count++;

	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (i == j || (i != 0 && j != 0))
				continue;

			if (x + i < 0 || y + j < 0 || x + i >= size_x || y + j >= size_y)
				continue;

			if (grid[x + i][y + j] == '0')
				continue;

			numIslandsHelper(grid, x + i, y + j, count);
		}
	}
}

int numIslands(std::vector<std::vector<char>> grid)
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
			if (grid[x][y] == '0')
				continue;

			count = 0;
			numIslandsHelper(grid, x, y, count);

			if (count > 0)
				ret++;
		}
	}

	return ret;
}

/*
	int i1 = numIslands({ {'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'} });        // 1
	int i2 = numIslands({ {'1','1','0','0','0'} , {'1','1','0','0','0'}, {'0','0','1','0','0'}, {'0','0','0','1','1'} });                       // 3
*/