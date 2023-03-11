#pragma once

#include <vector>

/*
118. Pascal's Triangle [Easy]

Given an integer numRows, return the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

Example 2:
Input: numRows = 1
Output: [[1]]

Constraints:
1 <= numRows <= 30
*/

std::vector<std::vector<int>> generatePascalTriangle(int numRows) 
{
	std::vector<std::vector<int>> ret;
	
	for (int i = 0; i < numRows; i++)
	{
		std::vector<int> row;
		row.resize(i + 1);

		row[0] = 1;
		row[i] = 1;

		// center
		for (int j = 1; j < i; j++)
		{
			row[j] = ret[i - 1][j - 1] + ret[i - 1][j];
		}

		ret.emplace_back(row);
	}

	return ret;
}

/*
	auto v1 = generatePascalTriangle(5);
	auto v2 = generatePascalTriangle(2);
*/