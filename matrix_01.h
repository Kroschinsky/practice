#pragma once

#include <vector>
#include <queue>

/*
542. 01 Matrix [Medium]

Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
The distance between two adjacent cells is 1.

Example 1:
Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]

Example 2:
Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]

Constraints:
m == mat.length
n == mat[i].length
1 <= m, n <= 104
1 <= m * n <= 104
mat[i][j] is either 0 or 1.
There is at least one 0 in mat.
*/

std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>> mat) 
{
	int m = mat.size();
	int n = mat[0].size();
        
    std::vector<int> dir = { 0, 1, 0, -1, 0 };
    std::queue<std::pair<int, int>> q;

    for (int r = 0; r < m; ++r)
    {
        for (int c = 0; c < n; ++c)
        {
            if (mat[r][c] == 0)
                q.emplace(r, c);
            else 
                mat[r][c] = -1;
        }
    }

    int nr, nc;

    while (!q.empty()) 
    {
        auto [r, c] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) 
        {
            nr = r + dir[i];
            nc = c + dir[i + 1];

            if (nr < 0 || nr == m || nc < 0 || nc == n || mat[nr][nc] != -1) 
                continue;

            mat[nr][nc] = mat[r][c] + 1;
            q.emplace(nr, nc);
        }
    }

    return mat;
}

/*
    auto v1 = updateMatrix({ {0,0,0 }, { 0,1,0 }, { 0,0,0 } });
    auto v2 = updateMatrix({ { 0,0,0 }, { 0,1,0 }, { 1,1,1 } });

    auto v3 = updateMatrix({
        { 0, 1, 1, 0, 0 },
        { 0, 1, 1, 0, 0 },
        { 0, 1, 0, 0, 1 },
        { 1, 1, 1, 1, 0 },
        { 1, 0, 0, 1, 0 } });

    auto v4 = updateMatrix({
        {1, 0, 1, 1, 0, 0, 1, 0, 0, 1},
        {0, 1, 1, 0, 1, 0, 1, 0, 1, 1},
        {0, 0, 1, 0, 1, 0, 0, 1, 0, 0},
        {1, 0, 1, 0, 1, 1, 1, 1, 1, 1},
        {0, 1, 0, 1, 1, 0, 0, 0, 0, 1},
        {0, 0, 1, 0, 1, 1, 1, 0, 1, 0},
        {0, 1, 0, 1, 0, 1, 0, 0, 1, 1},
        {1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 0, 1, 0},
        {1, 1, 1, 1, 0, 1, 0, 0, 1, 1}});

    auto v5 = updateMatrix({
        {0, 0, 1, 0, 1, 1, 1, 0, 1, 1},
        {1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 0, 0, 0, 1, 1},
        {1, 0, 1, 0, 1, 1, 1, 0, 1, 1},
        {0, 0, 1, 1, 1, 0, 1, 1, 1, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 0, 1, 0, 1},
        {0, 1, 0, 0, 0, 1, 0, 0, 1, 1},
        {1, 1, 1, 0, 1, 1, 0, 1, 0, 1},
        {1, 0, 1, 1, 1, 0, 1, 1, 1, 0} });
*/