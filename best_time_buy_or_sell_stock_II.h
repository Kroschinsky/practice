#pragma once

#include <iostream>
#include <vector>
#include <string>

/*
122. Best Time to Buy and Sell Stock II [Medium]

You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.
Find and return the maximum profit you can achieve.

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.

Example 2:
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.

Example 3:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.

Constraints:
1 <= prices.length <= 3 * 104
0 <= prices[i] <= 104
*/

int maxProfit(std::vector<int> prices)
{
	int profit = 0;

	int buy_index = 0;

	int sell_value = -1;
	int sell_index = 1;

	int size = prices.size();

	while(size > sell_index)
	{
		int buy  = prices[buy_index];
		int sell = prices[sell_index];

		if (buy > sell && sell_value == -1)
		{
			++buy_index;
			++sell_index;			
		}
		else
		{
			if (sell_value < sell)
			{
				sell_value = sell;
				++sell_index;
			}
			else
			{
				//std::cout << "Buy : " << buy << " - Sell : " << sell_value << std::endl;

				profit += sell_value - buy;
				sell_value = -1;

				buy_index = sell_index;
				sell_index = buy_index + 1;
			}			
		}
	}

	int buy = prices[buy_index];
	if (sell_value > buy)
	{
		//std::cout << "Buy : " << buy << " - Sell : " << sell_value << std::endl;
		profit += sell_value - buy;
	}

	//std::cout << "Profit : " << profit << std::endl;

	return profit;
}

int maxProfit2(std::vector<int> prices)
{
	int profit = 0;

	for (int i = 1; i < prices.size(); i++) 
	{
		if (prices[i - 1] < prices[i])
		{
			//std::cout << "Buy : " << prices[i - 1] << " - Sell : " << prices[i] << std::endl;
			profit += prices[i] - prices[i - 1];
		}
	}

	//std::cout << "Profit : " << profit << std::endl;

	return profit;
}

//int profit_1 = maxProfit2({ 7,1,5,3,6,4 });          // 7
//int profit_2 = maxProfit2({ 1,2,3,4,5 });            // 4
//int profit_3 = maxProfit2({ 7,6,4,3,1 });            // 0
//int profit_4 = maxProfit2({ 2,4,1 });                // 2