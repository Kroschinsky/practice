#pragma once

#include <vector>
#include <unordered_map>
#include <string>


/*
17. Letter Combinations of a Phone Number [Medium]

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:
Input: digits = ""
Output: []

Example 3:
Input: digits = "2"
Output: ["a","b","c"]
*/


void letterCombinationsHelper(int index, std::string comb, const std::string& digits, const std::unordered_map<char, std::string>& map, std::vector<std::string>& ret)
{
	if (comb.size() == digits.size())
	{
		ret.push_back(comb);
		return;
	}

	char c = digits[index];
	auto it = map.find(c);
	if (it == map.end())
		return;

	const std::string& str = it->second;

	for (char c : str)
		letterCombinationsHelper(index + 1, comb + c, digits, map, ret);
}

std::vector<std::string> letterCombinations(std::string digits)
{
	std::vector<std::string> ret;

	int size = digits.size();
	if (size == 0)
		return ret;
	
	std::unordered_map<char, std::string> map;
	map['2'] = "abc";
	map['3'] = "def";
	map['4'] = "ghi";
	map['5'] = "jkl";
	map['6'] = "mno";
	map['7'] = "qprs";
	map['8'] = "tuv";
	map['9'] = "wxyz";

	letterCombinationsHelper(0, "", digits, map, ret);

	return ret;
}

/*
	auto v1 = letterCombinations("23");
	auto v2 = letterCombinations("");
	auto v3 = letterCombinations("2");
*/