#pragma once

#include <vector>

class Node
{
public:

	Node();
	Node(int value);
	Node(int value, std::vector<Node*> children);

	~Node();

	static Node* createFromVector(std::vector<int> vec);

	int m_value = 0;
	std::vector<Node*> m_children;

private:

};

