#pragma once

#include <vector>
#include <stack>
#include "TreeNode.h"

/*
94. Binary Tree Inorder Traversal [Easy]

Given the root of a binary tree, return the inorder traversal of its nodes' values.

Example 1:
Input: root = [1,null,2,3]
Output: [1,3,2]

Example 2:
Input: root = []
Output: []

Example 3:
Input: root = [1]
Output: [1]

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*/

void inorderTraversalInOrder(std::vector<int>& ret, TreeNode* root)
{
	if (!root)
		return;

	inorderTraversalInOrder(ret, root->m_left);
	ret.push_back(root->m_val);
	inorderTraversalInOrder(ret, root->m_right);
}

std::vector<int> inorderTraversal(TreeNode* root) 
{
	std::vector<int> ret;
	inorderTraversalInOrder(ret, root);

	return ret;
}

std::vector<int> inorderTraversal2(TreeNode* root)
{
	std::vector<int> ret;
	std::stack<TreeNode*> helper;

	while (true)
	{
		if (root)
		{
			helper.push(root);
			root = root->m_left;
		}
		else
		{
			if (helper.empty())
				break;

			root = helper.top();
			helper.pop();

			ret.push_back(root->m_val);
			root = root->m_right;
		}
	}

	return ret;
}

/*
	auto v1 = TreeNode::createFromVector({ 1,0,2,3 });
	auto n1 = inorderTraversal2(v1);
*/