#pragma once

#include "TreeNode.h"
#include <stack>

/*
98. Validate Binary Search Tree [Medium]

Given the root of a binary tree, determine if it is a valid binary search tree (BST).
A valid BST is defined as follows:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

Example 1:
Input: root = [2,1,3]
Output: true

Example 2:
Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.

Constraints:
The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1
*/

bool isValidBSTHelper(TreeNode* node, long long left, long long right)
{
    if (!node)
        return true;

    if ((long long)node->m_val >= right || (long long)node->m_val <= left)
        return false;

    return isValidBSTHelper(node->m_left, left, node->m_val) && isValidBSTHelper(node->m_right, node->m_val, right);
}

bool isValidBST(TreeNode* root) 
{
    return isValidBSTHelper(root, LLONG_MIN, LLONG_MAX);
}


bool isValidBSTHelper2(TreeNode* node, TreeNode* left, TreeNode* right)
{
    if (!node)
        return true;

    if ((right && node->m_val >= right->m_val) || ((left) && node->m_val <= left->m_val))
        return false;

    return isValidBSTHelper2(node->m_left, left, node) && isValidBSTHelper2(node->m_right, node, right);
}

bool isValidBST2(TreeNode* root)
{
    return isValidBSTHelper2(root, nullptr, nullptr);
}


void isValidBSTHelper3(TreeNode* node, std::vector<int>& data)
{
    if (!node)
        return;

    isValidBSTHelper3(node->m_left, data);
    data.push_back(node->m_val);
    isValidBSTHelper3(node->m_right, data);
}

bool isValidBST3(TreeNode* root)
{
    std::vector<int> data;
    isValidBSTHelper3(root, data);

    int size = data.size();

    for (int i = 0; i < size - 1; i++)
    {
        if (data[i] >= data[i + 1])
            return false;
    }

    return true;
}

bool isValidBST4(TreeNode* root)
{
    if (!root)
        return true;

    std::stack<TreeNode*> nodes;
    TreeNode* prev_node = nullptr;
    
    while (root || !nodes.empty())
    {
        while (root)
        {
            nodes.push(root);
            root = root->m_left;
        }

        root = nodes.top();
        nodes.pop();

        if (prev_node && root->m_val <= prev_node->m_val)
            return false;

        prev_node = root;
        root = root->m_right;
    }
    
    return true;
}

/*
    Fixed input array data

    std::vector<std::pair<std::vector<int>, bool>> tests =
    {
        {{2,0,1,3}, true},
        {{5,0,1,4,0,3,6}, false},
        {{5,0,4,6,0,3,7}, false},
        {{2,0,2,2}, false},
        {{2147483647}, true},
    };

    for (auto& pair : tests)
    {
        auto node = TreeNode::createFromVector(pair.first);
        if (isValidBST2(node) == pair.second)
            std::cout << "True" << std::endl;
        else
            std::cout << "False" << std::endl;
    }
*/