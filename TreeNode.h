#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class TreeNode
{
public:

	TreeNode();
	TreeNode(int x);
	TreeNode(int x, TreeNode* left, TreeNode* right);
	~TreeNode();

	static TreeNode* createFromVector(std::vector<int> vec);
	static TreeNode* createFromVector2(std::vector<int> vec);

	int m_val = 0;
	TreeNode* m_left = nullptr;
	TreeNode* m_right = nullptr;

private:

	static void createFromVectorHelper(TreeNode* node, std::vector<int>& vec, int index);

};

