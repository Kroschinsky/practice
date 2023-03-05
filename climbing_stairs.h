#pragma once

#include <iostream>
#include <vector>
#include <string>

/*
70. Climbing Stairs [Easy]

You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

Constraints:
1 <= n <= 45
*/

/*
Solution : back to front

               5
              --
            4|
           --|
		 3|
        --|
      2|
     --|
   1|
  --|
 0|
--|

8  5  3  2  1  1
*/

int climbStairs(int n) 
{
	int one = 1;
	int two = 1;
	int temp;

	for (int i = 1; i < n; i++)
	{
		temp = one;
		one += two;
		two = temp;
	}

	return one;
}

int climbStairs2(int n) 
{
    if (n <= 2)
        return n;

    std::vector<int> dp(n + 1);
    
	dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

	for (int i = 3; i <= n; i++)
		dp[i] = dp[i - 1] + dp[i - 2];

	return dp[n];
}

/*
	int i1 = climbStairs(2);        // 2
	int i2 = climbStairs(3);        // 3
	int i3 = climbStairs(5);        // 8
*/