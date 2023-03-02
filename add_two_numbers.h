#pragma once

/*
Created: 26-02-23
Updated: 27-02-23

You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
*/

#include <iostream>
#include <string>
#include <vector>

#include "listnode.h"

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	int val1, val2;
	int carry = 0;
		
	ListNode* result = new ListNode(0);
	ListNode* curr = result;

	auto n1 = l1;
	auto n2 = l2;

	while (n1 || n2 || carry)
	{
		val1 = 0;
		if (n1)
		{
			val1 = n1->val;
			n1 = n1->next;
		}

		val2 = 0;
		if (n2)
		{
			val2 = n2->val;
			n2 = n2->next;
		}

		val1 = val1 + val2 + carry;
		carry = val1 / 10;

		curr->next = new ListNode(val1 % 10);
		curr = curr->next;
	}

	auto ret = result->next;
	result->next = nullptr;
	delete result;

	return ret;
}

/*
	auto n1 = ListNode::createListNodeFromVector({ 2,4,3 });
	auto n2 = ListNode::createListNodeFromVector({ 5,6,4 });
	ListNode::printListNode(n1);
	ListNode::printListNode(n2);

	auto nResult = addTwoNumbers(n1, n2);
	ListNode::printListNode(nResult);

	delete n1;
	delete n2;
	delete nResult;
*/