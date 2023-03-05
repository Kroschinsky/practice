#pragma once

#include "TreeNode.h"

#include <deque>
#include <vector>
#include <queue>

/*
102. Binary Tree Level Order Traversal [Medium]

Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

Example 2:
Input: root = [1]
Output: [[1]]

Example 3:
Input: root = []
Output: []
*/

// BFS : Breadth First Search
std::vector<std::vector<int>> BinaryTreeLevelOrderTraversal(TreeNode* root)
{
	std::vector<std::vector<int>> ret;
	std::queue<TreeNode*> q;

	q.push(root);

	while (true)
	{
		int size = q.size();
		if (size == 0)
			break;

		std::vector<int> level;

		for (int i = 0; i < size; i++)
		{
			auto node = q.front();
			q.pop();
			if (!node)
				continue;

			level.push_back(node->m_val);
			q.push(node->m_left);
			q.push(node->m_right);
		}

		if (level.size() > 0)
			ret.push_back(level);
	}

	return ret;
}

/*
	auto n1 = TreeNode::createFromVector({ 3,9,20,0,0,15,7 });
	auto v1 = BinaryTreeLevelOrderTraversal(n1);

	auto n2 = TreeNode::createFromVector({ 1 });
	auto v2 = BinaryTreeLevelOrderTraversal(n2);

	auto v3 = BinaryTreeLevelOrderTraversal(nullptr);
*/