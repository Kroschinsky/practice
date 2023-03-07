#pragma once

#include "TreeNode.h"

/*
617. Merge Two Binary Trees [Easy]

You are given two binary trees root1 and root2.
Imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not. 
You need to merge the two trees into a new binary tree. The merge rule is that if two nodes overlap, 
then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of the new tree.

Return the merged tree.
Note: The merging process must start from the root nodes of both trees.

Example 1:
Input: root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
Output: [3,4,5,5,4,null,7]

Example 2:
Input: root1 = [1], root2 = [1,2]
Output: [2,2]

Constraints:
The number of nodes in both trees is in the range [0, 2000].
-104 <= Node.val <= 104
*/

TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) 
{
	if (!root1 && !root2)
		return nullptr;

	int val1 = 0;
	int val2 = 0;

	TreeNode* l1 = nullptr;
	TreeNode* l2 = nullptr;
	TreeNode* r1 = nullptr;
	TreeNode* r2 = nullptr;

	if (root1)
	{
		val1 = root1->m_val;
		l1 = root1->m_left;
		r1 = root1->m_right;
	}

	if (root2)
	{
		val2 = root2->m_val;
		l2 = root2->m_left;
		r2 = root2->m_right;
	}

	TreeNode* node = new TreeNode(val1 + val2);
	node->m_left = mergeTrees(l1, l2);
	node->m_right = mergeTrees(r1, r2);

	return node;
}

TreeNode* mergeTrees2(TreeNode* root1, TreeNode* root2)
{
	if (!root1)
		return root2;

	if (!root2)
		return root1;

	root1->m_val += root2->m_val;
	root1->m_left = mergeTrees2(root1->m_left, root2->m_left);
	root1->m_right = mergeTrees2(root1->m_right, root2->m_right);

	return root1;
}

/*
	auto va1 = TreeNode::createFromVector({ 1,3,2,5 });
	auto vb1 = TreeNode::createFromVector({ 2,1,3,0,4,0,7 });
	auto t1 = mergeTrees2(va1, vb1);

	auto va2 = TreeNode::createFromVector({ 1 });
	auto vb2 = TreeNode::createFromVector({ 1,2 });
	auto t2 = mergeTrees2(va2, vb2);
*/