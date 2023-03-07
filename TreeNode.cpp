#include "TreeNode.h"

#include <queue>

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

	std::queue<TreeNode*> q;

	int index = 2;
	TreeNode* node = new TreeNode(vec[0]);
	q.push(node);

	while (true)
	{
		int q_size = q.size();
		if (q_size == 0)
			break;

		for (int i = 0; i < q_size; i++)
		{
			auto n = q.front();
			q.pop();

			if (size <= index)
				continue;

			if (vec[index] == 0)
			{
				index++;
				break;
			}

			auto n_node = new TreeNode(vec[index]);
			n->m_left = n_node;
			q.push(n_node);

			index++;

			if (size <= index)
				continue;

			if (vec[index] == 0)
			{
				index++;
				break;
			}

			n_node = new TreeNode(vec[index]);
			n->m_right = n_node;
			q.push(n_node);

			index++;
		}
	}

	return node;
}

TreeNode* TreeNode::createFromVector2(std::vector<int> vec)
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
