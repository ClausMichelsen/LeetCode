#include <vector>

#include "ListNode.h"

using namespace std;



// Problem: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
ListNode* RemoveNthNodeFromEndOfList(ListNode* head, int n)
{
    // Time: O(n) Space: O(n)
    vector<ListNode*> nodes;
    ListNode* node{ head };
    while (node)
    {
        nodes.push_back(node);
        node = node->next;
    }

    const int indexToRemove{ static_cast<int>(nodes.size()) - n };
    if (n != nodes.size()) // Removing non-first node in list (1-based index from back).
        nodes[indexToRemove - 1]->next = nodes[indexToRemove]->next;
    if (!n && nodes.size() >= 2) // Removing last node in list
        nodes[nodes.size() - 2]->next = nullptr;

    if (n == nodes.size()) // Removing first node in list. Update pointer to return.
        head = head->next;

    return head;
}
