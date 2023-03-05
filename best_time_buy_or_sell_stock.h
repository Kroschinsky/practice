#pragma once

#include <iostream>
#include <vector>
#include <string>

/*
121. Best Time to Buy and Sell Stock [Easy]

You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Example 2:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.

Constraints:
1 <= prices.length <= 105
0 <= prices[i] <= 104
*/

int maxProfit(std::vector<int> prices)
{
	int size = prices.size();
	int best = 0;	

	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (prices[j] - prices[i] > best)
				best = prices[j] - prices[i];
		}
	}

	return best;
}

int maxProfit2(std::vector<int> prices)
{
	int size = prices.size();
	int min = INT_MAX;					// prices[0]
	int best = 0;

	for (int i = 0; i < size; i++)
	{
		best = std::max(best, prices[i] - min);
		min = std::min(min, prices[i]);
	}

	return best;
}

/*
	int i1 = maxProfit2({ 7,1,5,3,6,4 });
	int i2 = maxProfit2({ 7,6,4,3,1 });
	int i3 = maxProfit2({ 1 });
*/