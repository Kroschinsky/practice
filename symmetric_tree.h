#pragma once

#include "TreeNode.h"

/*
101. Symmetric Tree [Easy]

Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

Example 1:
Input: root = [1,2,2,3,4,4,3]
Output: true

Example 2:
Input: root = [1,2,2,null,3,null,3]
Output: false

Constraints:
The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100
*/

bool checkMirrorTree(TreeNode* t1, TreeNode* t2)
{
	if (!t1 && !t2)
		return true;

	if (!t1 || !t2)
		return false;

	return (t1->m_val == t2->m_val) && checkMirrorTree(t1->m_left, t2->m_right) && checkMirrorTree(t1->m_right, t2->m_left);
}

bool isSymmetricTree(TreeNode* root) 
{
	return checkMirrorTree(root, root);
}

/*
	this one not respect same sequence of TreeNode create from vector, so need to add one zero

	auto v1 = TreeNode::createFromVector({ 1,0,2,2,3,4,4,3 });
	bool b1 = isSymmetricTree(v1);

	auto v2 = TreeNode::createFromVector({ 1,0,2,2,0,3,0,3 });
	bool b2 = isSymmetricTree(v2);
*/