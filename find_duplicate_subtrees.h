#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "TreeNode.h"

/*
652. Find Duplicate Subtrees [Medium]

Given the root of a binary tree, return all duplicate subtrees.
For each kind of duplicate subtrees, you only need to return the root node of any one of them.
Two trees are duplicate if they have the same structure with the same node values.

Example 1:
Input: root = [1,2,3,4,null,2,4,null,null,4]
Output: [[2,4],[4]]

Example 2:
Input: root = [2,1,1]
Output: [[1]]

Example 3:
Input: root = [2,2,2,3,null,3,null]
Output: [[2,3],[3]]
*/

std::string findDuplicateSubtreesHelper(TreeNode* root, std::vector<TreeNode*>& vec, std::map<std::string, int>& map)
{
	if (!root)
		return "x";

	std::string s = findDuplicateSubtreesHelper(root->m_left, vec, map) + "," + findDuplicateSubtreesHelper(root->m_right, vec, map) + ',' + std::to_string(root->m_val);
	map[s]++;

	if (map[s] == 2)
		vec.push_back(root);

	return s;
}

std::vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
{
	std::vector<TreeNode*> ret;
	std::map<std::string, int> map;
	findDuplicateSubtreesHelper(root, ret, map);

	std::reverse(ret.begin(), ret.end());

	return ret;
}

/*
	auto n1 = TreeNode::createFromVector({ 1,2,3,4,0,2,4,0,0,4 });
	auto t1 = findDuplicateSubtrees(n1);

	auto n2 = TreeNode::createFromVector({ 2,1,1 });
	auto t2 = findDuplicateSubtrees(n2);

	auto n3 = TreeNode::createFromVector({ 2,2,2,3,0,3,0 });
	auto t3 = findDuplicateSubtrees(n3);
*/