#pragma once

#include <iostream>
#include <string>
#include <vector>

/*
Created : 26-02-23

A vending machine has the following denominations : 1c, 5c, 10c, 25c, 50c, and $1.
Your task is to write a program that will be used in a vending machine to return change.
Assume that the vending machine will always want to return the least number of coins or
notes.Devise a function getChange(M, P) where M is how much money was inserted into the
machine and P the price of the item selected, that returns an array of integers
representing the number of each denomination to return.

Example :

	auto v1 = getChange(5, 0.99);			// should return [1,0,0,0,0,4]
	auto v2 = getChange(3.14, 1.99);		// should return [0,1,1,0,0,1]
	auto v3 = getChange(3, 0.01);			// should return [4,0,2,1,1,2]
	auto v4 = getChange(4, 3.14);			// should return [1,0,1,1,1,0]
	auto v5 = getChange(0.45, 0.34);		// should return [1,0,1,0,0,0]

*/


std::vector<int> getChange(float m, float p)
{
	int money = m * 100;
	int product = p * 100;
	int change = money - product;
	int coin;

	std::vector<int> coins = { 100,50,25,10,5,1 };
	int size = coins.size();

	std::vector<int> ret;
	ret.resize(size);

	for (int v = 0; v < size; v++)
	{
		coin = change / coins[v];
		change %= coins[v];
		ret[size -1 - v] = coin;
	}

	return ret;
}