#include "ListNode.h"



// Problem: https://leetcode.com/problems/reverse-linked-list/
ListNode* ReverseLinkedList_Iterative(ListNode* head)
{
    // Time: O(n) Space: O(1)
    ListNode* node{ head };
    ListNode* prev{ nullptr };
    ListNode* newHead{ nullptr };
    while (node)
    {
        ListNode* const next{ node->next };
        if (!next)
            newHead = node;
        node->next = prev;
        prev = node;
        node = next;
    }

    return newHead;
}


ListNode* reverseList2(ListNode* prev, ListNode* node);

ListNode* ReverseLinkedList_Recursive(ListNode* head)
{
    // Time: O(n) Space: O(n)
    if (!head)
        return nullptr;

    ListNode* newHead = reverseList2(head, head->next);
    head->next = nullptr;
    return newHead;
}

ListNode* reverseList2(ListNode* prev, ListNode* node)
{
    if (!node) // We have reached the end.
        return prev;

    ListNode* newHead = reverseList2(node, node->next);
    node->next = prev;
    return newHead;
}
