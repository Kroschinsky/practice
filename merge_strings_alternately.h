#pragma once

#include <string>
#include <algorithm>

/*
 1768. Merge Strings Alternately [Easy]

You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1.
If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string. 

Example 1:
Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r

Example 2:
Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b 
word2:    p   q   r   s
merged: a p b q   r   s

Example 3:
Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"
Explanation: Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q 
merged: a p b q c   d

Constraints:
1 <= word1.length, word2.length <= 100
word1 and word2 consist of lowercase English letters.
*/

std::string mergeAlternately(std::string word1, std::string word2)
{
	std::string ret = "";

	int size1 = word1.size();
	int size2 = word2.size();
	int index1 = 0;
	int index2 = 0;

	for(int i = 0; i < size1+size2; i++)
	{
		if ((i % 2 == 0 && size1 > index1) || index2 >= size2)
		{
			ret += word1[index1];
			index1++;
		}
		else
		{
			ret += word2[index2];
			index2++;
		}
	}

	return ret;
}

std::string mergeAlternately2(std::string word1, std::string word2)
{
	int size1 = word1.size();
	int size2 = word2.size();

	std::string ret;
	ret.resize(size1 + size2);

	int ix1 = 0;
	int ix2 = 0;
	int end = 0;

	while (ix1 < size1 && ix2 < size2)
	{
		ret[end++] = word1[ix1++];
		ret[end++] = word2[ix2++];
	}

	if (ix1 < size1)
		std::memcpy(&ret[end], &word1[ix1], size1 - ix1);
	else if (ix2 < size2)
		std::memcpy(&ret[end], &word2[ix2], size2 - ix2);

	return ret;
}

/*
	std::string s1 = mergeAlternately2("abc", "pqr");
	std::string s2 = mergeAlternately2("ab", "pqrs");
	std::string s3 = mergeAlternately2("abcd", "pq");
*/