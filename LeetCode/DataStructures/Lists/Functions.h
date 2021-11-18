#pragma once


#include <vector>

#include "ListNode.h"

using namespace std;



bool LinkedListCycle_Floyd(ListNode* head);
bool LinkedListCycle_Regular(ListNode* head);
ListNode* MergeKSortedLists(vector<ListNode*> lists);
ListNode* MergeTwoSortedLists(ListNode* l1, ListNode* l2);
ListNode* RemoveNthNodeFromEndOfList(ListNode* head, int n);
void ReorderList(ListNode* head);
ListNode* ReverseLinkedList_Iterative(ListNode* head);
ListNode* ReverseLinkedList_Recursive(ListNode* head);
