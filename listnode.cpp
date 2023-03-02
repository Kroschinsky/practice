#include "listnode.h"

#include <iostream>
#include <string>
#include <vector>

ListNode::ListNode()
	: val(0)
	, next(nullptr)
{
}

ListNode::ListNode(int x) 
	: val(x)
	, next(nullptr) 
{
}

ListNode::ListNode(int x, ListNode* next) 
	: val(x)
	, next(next) 
{
}

ListNode::~ListNode()
{
	if (next)
		delete next;
}

void ListNode::printListNode(ListNode* l)
{
	std::cout << "[";

	ListNode* next = l;

	while (next)
	{
		std::cout << next->val;
		if (next->next)
			std::cout << ",";

		next = next->next;
	}

	std::cout << "]" << std::endl;
}

ListNode* ListNode::createListNodeFromVector(std::vector<int> vec)
{
	ListNode* start = nullptr;
	ListNode* curr = nullptr;

	for (int v : vec)
	{
		if (!start)
		{
			start = new ListNode(v);
			curr = start;
		}
		else
		{
			curr->next = new ListNode(v);
			curr = curr->next;
		}
	}

	return start;
}