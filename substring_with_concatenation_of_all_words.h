#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <string_view>

/*
30. Substring with Concatenation of All Words [hard]

You are given a string s and an array of strings words. All the strings of words are of the same length.
A concatenated string is a string that exactly contains all the strings of any permutation of words concatenated.
For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. 
"acdbef" is not a concatenated string because it is not the concatenation of any permutation of words.
Return an array of the starting indices of all the concatenated substrings in s. You can return the answer in any order.

Example 1:
Input: s = "barfoothefoobarman", words = ["foo","bar"]
Output: [0,9]

Explanation:
The substring starting at 0 is "barfoo". It is the concatenation of ["bar","foo"] which is a permutation of words.
The substring starting at 9 is "foobar". It is the concatenation of ["foo","bar"] which is a permutation of words.

Example 2:
Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
Output: []
Explanation:
There is no concatenated substring.

Example 3:
Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
Output: [6,9,12]

Explanation:
The substring starting at 6 is "foobarthe". It is the concatenation of ["foo","bar","the"].
The substring starting at 9 is "barthefoo". It is the concatenation of ["bar","the","foo"].
The substring starting at 12 is "thefoobar". It is the concatenation of ["the","foo","bar"].

Constraints:
1 <= s.length <= 104
1 <= words.length <= 5000
1 <= words[i].length <= 30
s and words[i] consist of lowercase English letters.
*/

std::vector<int> findSubstring(std::string s, std::vector<std::string> words)
{
	std::vector<int> ret;
	std::unordered_map< std::string_view, int > map;

	for (const auto& w : words)
	{
		map[w]++;
	}

	int size_words = words.size();
	int size = words[0].size();
	int size_s = s.size();

	for (int i = 0; i <= size_s - (size_words * size); ++i)
	{
		int check_count = size_words;
		std::unordered_map<std::string_view, int> check_map = map;

		for (int j = 0; j < size_words; ++j)
		{
			std::string_view w(&s[i + (j * size)], size);

			auto it = check_map.find(w);
			if (it != check_map.end())
			{
				if (it->second > 0)
					--check_count;

				check_map[w]--;
			}
		}

		if (check_count == 0)
		{
			ret.push_back(i);
		}
	}

	return ret;
}

/*
	std::vector<int> output_1 = findSubstring("barfoothefoobarman", { "foo","bar" });           // [0,9]
	std::vector<int> output_2 = findSubstring("wordgoodgoodgoodbestword", { "word","good","best","word" }); // []
	std::vector<int> output_3 = findSubstring("barfoofoobarthefoobarman", { "bar","foo","the" });   // [6,9,12]
	std::vector<int> output_4 = findSubstring("wordgoodgoodgoodbestword", { "word","good","best","good" }); // [8]
	std::vector<int> output_5 = findSubstring("lingmindraboofooowingdingbarrwingmonkeypoundcake", { "fooo","barr","wing","ding","wing" });    // [13]
	std::vector<int> output_6 = findSubstring("a", { "a" });           // [0]
	std::vector<int> output_7 = findSubstring("ababaab", { "ab","ba","ba" });           // [0]
*/