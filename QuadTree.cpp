#include "QuadTree.h"

QuadTreeNode::QuadTreeNode()
{
}

QuadTreeNode::QuadTreeNode(bool val, bool isLeaf)
	: m_val(val)
	, m_isLeaf(isLeaf)
{
}

QuadTreeNode::QuadTreeNode(bool val, bool isLeaf, QuadTreeNode* tLeft, QuadTreeNode* tRight, QuadTreeNode* bLeft, QuadTreeNode* bRight)
	: m_val(val)
	, m_isLeaf(isLeaf)
	, m_topLeft(tLeft)
	, m_topRight(tRight)
	, m_bottomLeft(bLeft)
	, m_bottomRight(bRight)
{
}

QuadTreeNode::~QuadTreeNode()
{
	if (m_topLeft)
		delete m_topLeft;
	if (m_topRight)
		delete m_topRight;
	if (m_bottomLeft)
		delete m_bottomLeft;
	if (m_bottomRight)
		delete m_bottomRight;
}

void QuadTreeNode::print(QuadTreeNode* node)
{
	if (!node)
		return;

	std::cout << "[" << (int)node->m_isLeaf << "," << (int)node->m_val << "] ";

	print(node->m_topLeft);
	print(node->m_topRight);
	print(node->m_bottomLeft);
	print(node->m_bottomRight);
}

