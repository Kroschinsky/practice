#pragma once

#include "listnode.h"

/*
Created: 01-03-23

876. Middle of the Linked List [Easy]

Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node.

Example 1:
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.

Example 2:
Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.

Constraints:
The number of nodes in the list is in the range [1, 100].
1 <= Node.val <= 100
*/

ListNode* middleNode(ListNode* head) 
{
	std::vector<ListNode*> vec;

	while (head)
	{
		vec.push_back(head);
		head = head->next;
	}

	return vec[vec.size() / 2];
}

ListNode* middleNode2(ListNode* head)
{
	ListNode* mid = head;
	ListNode* end = head;

	while (end && end->next)
	{
		mid = mid->next;
		end = end->next->next;
	}

	return mid;
}

/*
	auto v1 = ListNode::createListNodeFromVector({ 1,2,3,4,5 });        // {3,4,5}
	auto n1 = middleNode2(v1);
	ListNode::printListNode(n1);

	auto v2 = ListNode::createListNodeFromVector({ 1,2,3,4,5,6 });      // {4,5,6}
	auto n2 = middleNode2(v2);
	ListNode::printListNode(n2);
*/