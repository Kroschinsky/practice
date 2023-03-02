#include "TreeNode.h"

TreeNode::TreeNode() 
	: m_val(0)
	, m_left(nullptr)
	, m_right(nullptr) 
{
}

TreeNode::TreeNode(int x) 
	: m_val(x)
	, m_left(nullptr)
	, m_right(nullptr) 
{
}

TreeNode::TreeNode(int x, TreeNode* left, TreeNode* right) 
	: m_val(x)
	, m_left(left)
	, m_right(right) 
{
}

TreeNode::~TreeNode()
{
	if (m_left)
		delete m_left;

	if (m_right)
		delete m_right;
}

TreeNode* TreeNode::createFromVector(std::vector<int> vec)
{
	int size = vec.size();
	if (size == 0)
		return nullptr;

	TreeNode* start = new TreeNode(vec[0]);
	createFromVectorHelper(start, vec, 0);

	return start;
}

void TreeNode::createFromVectorHelper(TreeNode* node, std::vector<int>& vec, int index)
{
	int size = vec.size();
	int left = (2 * index) + 1;
	int right = (2 * index) + 2;

	if (left < size)
	{
		if (vec[left] != 0)
		{
			node->m_left = new TreeNode(vec[left]);
			createFromVectorHelper(node->m_left, vec, ++index);
		}

		if (right < size && vec[right] != 0)
		{
			node->m_right = new TreeNode(vec[right]);
			createFromVectorHelper(node->m_right, vec, ++index);
		}
	}
}
