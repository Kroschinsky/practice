#pragma once

#include <string>
#include <algorithm>

/*
 2160. Minimum Sum of Four Digit Number After Splitting Digits [Easy]

You are given a positive integer num consisting of exactly four digits. Split num into two new integers new1 and new2 by using the digits found in num. 
Leading zeros are allowed in new1 and new2, and all the digits found in num must be used.
For example, given num = 2932, you have the following digits: two 2's, one 9 and one 3. Some of the possible pairs [new1, new2] are [22, 93], [23, 92], [223, 9] and [2, 329].
Return the minimum possible sum of new1 and new2.

Example 1:
Input: num = 2932
Output: 52
Explanation: Some possible pairs [new1, new2] are [29, 23], [223, 9], etc.
The minimum sum can be obtained by the pair [29, 23]: 29 + 23 = 52.

Example 2:
Input: num = 4009
Output: 13
Explanation: Some possible pairs [new1, new2] are [0, 49], [490, 0], etc. 
The minimum sum can be obtained by the pair [4, 9]: 4 + 9 = 13.
 
Constraints:
1000 <= num <= 9999
*/

int minimumSum(int num) 
{
	// low num (n1n3, n2n4)

	std::string s = std::to_string(num);
	std::sort(s.begin(), s.end());

	std::string s_new1 = "00";
	s_new1[0] = s[0];
	s_new1[1] = s[2];

	std::string s_new2 = "00";
	s_new2[0] = s[1];
	s_new2[1] = s[3];

	return std::stoi(s_new1) + std::stoi(s_new2);
}

/*
	int i1 = minimumSum(2932);
	int i2 = minimumSum(4009);
*/