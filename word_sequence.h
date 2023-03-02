#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>

/*
Created : 26-02-23

A precedence rule is given as "P>E", which means that letter "P" is followed directly by the letter "E".
Write a function, given an array of precedence rules, that finds the word represented by the given rules.

Note: Each represented word contains a set of unique characters, i.e. the word does not contain duplicate letters.

Examples:

	auto s1 = findWord({ "P>E","E>R","R>U" });														// PERU
	auto s2 = findWord({ "I>N","A>I","P>A","S>P" });												// SPAIN
	auto s3 = findWord({ "U>N", "G>A", "R>Y", "H>U", "N>G", "A>R" });								// HUNGARY
	auto s4 = findWord({ "I>F", "W>I", "S>W", "F>T" });												// SWIFT
	auto s5 = findWord({ "R>T", "A>L", "P>O", "O>R", "G>A", "T>U", "U>G" });						// PORTUGAL
	auto s6 = findWord({ "W>I", "R>L", "T>Z", "Z>E", "S>W", "E>R", "L>A", "A>N", "N>D", "I>T" });	// SWITZERLAND

*/

std::string findWord(std::vector<std::string> v)
{
	std::string ret = "";
	std::map<char, char> map;
	std::set<char> count;

	int size = v.size();

	for (int i = 0; i < size; i++)
	{
		char c1 = v[i][0];
		char c2 = v[i][2];

		map[c1] = c2;
		
		auto it = count.find(c2);
		if (it == count.end())
			count.insert(c2);
	}

	// find first
	char first;

	for (int i = 0; i < size; i++)
	{
		char c1 = v[i][0];

		auto it = count.find(c1);
		if (it == count.end())
		{
			first = c1;
			break;
		}
	}

	// get string with map
	ret = first;
	char next = first;
	
	while (true)
	{
		auto it = map.find(next);
		if (it != map.end())
		{
			ret += it->second;
			next = it->second;
		}
		else
		{
			break;
		}
	}

	return ret;
}