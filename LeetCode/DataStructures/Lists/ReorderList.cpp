#include <vector>

#include "ListNode.h"

using namespace std;



// Problem: https://leetcode.com/problems/reorder-list/
void ReorderList(ListNode* head)
{
    vector<ListNode*> nodes;

    ListNode* node{ head };
    int count{ 0 };
    while (node)
    {
        nodes.push_back(node);
        node = node->next;
        ++count;
    }

    int left{ 1 };
    int right{ count - 1 };
    ListNode* node2{ head };
    for (int i{ 1 }; i < count; ++i)
    {
        if (i % 2)
            node2 = node2->next = nodes[right--];
        else
            node2 = node2->next = nodes[left++];
    }

    node2->next = nullptr;
}
