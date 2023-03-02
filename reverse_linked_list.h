#pragma once

#include "listnode.h"

/*
Created : 28-02-23
 
206. Reverse Linked List [Easy]
Given the head of a singly linked list, reverse the list, and return the reversed list.

Example 1:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2:
Input: head = [1,2]
Output: [2,1]

Example 3:
Input: head = []
Output: []
*/

ListNode* reverseList(ListNode* head) 
{
	ListNode* last = nullptr;
	ListNode* curr = nullptr;

	while (head)
	{
		curr = new ListNode(head->val);
		curr->next = last;
		last = curr;	

		head = head->next;
	}

	return curr;
}

/*
    std::vector<std::vector<int>> examples =
    {
        { 1,2,3,4,5 },
        { 1,2 },
        { }
    };

    for (auto& v : examples)
    {
        auto n1 = ListNode::createListNodeFromVector(v);
        ListNode::printListNode(n1);
        auto a1 = reverseList(n1);
        ListNode::printListNode(a1);

        delete n1;
        delete a1;
    }
*/