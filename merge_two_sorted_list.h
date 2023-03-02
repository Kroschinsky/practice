#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "listnode.h"

/*
Created: 27-02-23

21. Merge Two Sorted Lists

You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.

Example 1:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:
Input: list1 = [], list2 = []
Output: []

Example 3:
Input: list1 = [], list2 = [0]
Output: [0]
*/

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
{
	ListNode* start = new ListNode(0);
	ListNode* curr = start;

	while (list1 || list2)
	{
		if (list1 && !list2)
		{
			curr->next = new ListNode(list1->val);
			list1 = list1->next;
		}
		else if (!list1 && list2)
		{
			curr->next = new ListNode(list2->val);
			list2 = list2->next;
		}
		else 
		{
			if (list1->val < list2->val)
			{
				curr->next = new ListNode(list1->val);
				list1 = list1->next;
			}
			else
			{
				curr->next = new ListNode(list2->val);
				list2 = list2->next;
			}
		}

		curr = curr->next;
	}
	
	// prevent memory leak
	auto ret = start->next;
	start->next = nullptr;
	delete start;

	return ret;
}


ListNode* mergeTwoLists2(ListNode* list1, ListNode* list2)
{
	ListNode* start = new ListNode(0);
	ListNode* curr = start;

	// force lists same size
	while (list1 && list2)
	{
		if (list1->val < list2->val)
		{
			curr->next = new ListNode(list1->val);
			list1 = list1->next;
		}
		else
		{
			curr->next = new ListNode(list2->val);
			list2 = list2->next;
		}

		curr = curr->next;
	}

	// add rest of list1 or list2 if needed
	ListNode* last = nullptr;
	if (list1 != nullptr)
		last = list1;
	else if (list2 != nullptr)
		last = list2;

	if (last)
	{
		while (last)
		{
			curr->next = new ListNode(last->val);
			last = last->next;
			curr = curr->next;
		}
	}

	// prevent memory leak
	auto ret = start->next;
	start->next = nullptr;
	delete start;

	return ret;
}

/*
	//auto n1 = ListNode::createListNodeFromVector({ 1,2,4 });
	//auto n2 = ListNode::createListNodeFromVector({ 1,3,4 });

	auto n1 = ListNode::createListNodeFromVector({ -9, 3 });
	auto n2 = ListNode::createListNodeFromVector({  5, 7 });

	ListNode::printListNode(n1);
	ListNode::printListNode(n2);

	auto nResult = mergeTwoLists2(n1, n2);
	ListNode::printListNode(nResult);

	delete n1;
	delete n2;
	delete nResult;
*/