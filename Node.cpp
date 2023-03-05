#include "Node.h"

#include <queue>

Node::Node()
{
}

Node::Node(int value)
	: m_value(value)
{
}

Node::Node(int value, std::vector<Node*> children)
	: m_value(value)
	, m_children(children)
{
}

Node::~Node()
{
	for (Node* node : m_children)
		delete node;

	m_children.clear();
}

Node* Node::createFromVector(std::vector<int> vec)
{
	int size = vec.size();
	if (size == 0)
		return nullptr;

	std::queue<Node*> q;

	int index = 2;
	Node* node = new Node(vec[0]);
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

			while (size > index)
			{
				if (vec[index] == 0)
				{
					index++;
					break;
				}

				auto n_node = new Node(vec[index]);
				n->m_children.push_back(n_node);
				q.push(n_node);

				index++;
			}
		}
	}

	return node;
}
