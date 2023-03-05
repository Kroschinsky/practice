#pragma once

#include "listnode.h"

/*
Created: 04-03-23

19. Remove Nth Node From End of List [Medium]

Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:
Input: head = [1], n = 1
Output: []

Example 3:
Input: head = [1,2], n = 1
Output: [1]

Constraints:
The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
*/

ListNode* removeNthFromEnd(ListNode* head, int n) 
{
	ListNode* start = head;
	std::vector<ListNode*> vec;

	while (head)
	{
		vec.push_back(head);
		head = head->next;
	}
	
	int size = vec.size();
	int idx = size - n - 1;

	if (idx < 0)
	{
		start = vec[0]->next;
	}
	if (idx >= 0)
	{
		auto node1 = vec[idx];
		node1->next = nullptr;

		idx = size - n + 1;
		if (idx < size)
			node1->next = vec[idx];
	}

	return start;
}

ListNode* removeNthFromEnd2(ListNode* head, int n)
{
	if (!head)
		return nullptr;

	ListNode* slow = head;
	ListNode* fast = head;
	ListNode* prev = nullptr;
	
	// distance n between slow and fast
	for (int i = 0; i < n-1; i++)
		fast = fast->next;

	while (fast && fast->next)
	{
		prev = slow;
		slow = slow->next;
		fast = fast->next;
	}

	if (!prev)
		return head->next;

	prev->next = slow->next;

	return head;
}

/*
	auto v1 = ListNode::createListNodeFromVector({ 1,2,3,4,5 });
	ListNode::printListNode(v1);
	auto n1 = removeNthFromEnd2(v1, 2);
	ListNode::printListNode(n1);

	auto v2 = ListNode::createListNodeFromVector({1});
	ListNode::printListNode(v2);
	auto n2 = removeNthFromEnd2(v2, 1);
	ListNode::printListNode(n2);

	auto v3 = ListNode::createListNodeFromVector({ 1,2 });
	ListNode::printListNode(v3);
	auto n3 = removeNthFromEnd2(v3, 1);
	ListNode::printListNode(n3);

	auto v4 = ListNode::createListNodeFromVector({ 1,2 });
	ListNode::printListNode(v4);
	auto n4 = removeNthFromEnd2(v4, 2);
	ListNode::printListNode(n4);
*/