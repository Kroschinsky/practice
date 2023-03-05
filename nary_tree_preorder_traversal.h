#pragma once

#include "Node.h"

/*
589. N-ary Tree Preorder Traversal [Easy]

Given the root of an n-ary tree, return the preorder traversal of its nodes' values.
Nary-Tree input serialization is represented in their level order traversal. 
Each group of children is separated by the null value (See examples)

Example 1:
Input: root = [1,null,3,2,4,null,5,6]
Output: [1,3,5,6,2,4]

Example 2:
Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [1,2,3,6,7,11,14,4,8,12,5,9,13,10]

Constraints:
The number of nodes in the tree is in the range [0, 104].
0 <= Node.val <= 104
The height of the n-ary tree is less than or equal to 1000.
*/

void preorderHelper(std::vector<int>& v, Node* node)
{
	if (!node)
		return;

	v.push_back(node->m_value);

	for (auto& n : node->m_children)
		preorderHelper(v, n);
}

std::vector<int> preorder(Node* root)
{
	std::vector<int> ret;
	preorderHelper(ret, root);

	return ret;
}

/*
	// [1,3,5,6,2,4]
	auto t1 = Node::createFromVector({ 1,0,3,2,4,0,5,6 });
	auto v1 = preorder(t1);

	// [1,2,3,6,7,11,14,4,8,12,5,9,13,10]
	auto t2 = Node::createFromVector({ 1,0,2,3,4,5,0,0,6,7,0,8,0,9,10,0,0,11,0,12,0,13,0,0,14 });
	auto v2 = preorder(t2);
*/