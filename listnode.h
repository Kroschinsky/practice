#pragma once

#include <vector>

/*
Created: 26-02-23
Updated: 27-02-23
*/


class ListNode
{
public:

	ListNode();
	ListNode(int x);
	ListNode(int x, ListNode* next);

	~ListNode();

	static void printListNode(ListNode* l);
	static ListNode* createListNodeFromVector(std::vector<int> vec);
	static void ListCycle(ListNode* l, int pos);

	int val;
	ListNode* next;
};
