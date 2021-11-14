#include "ListNode.h"

#include <unordered_set>

using namespace std;



// Problem: https://leetcode.com/problems/linked-list-cycle/
bool LinkedListCycle_1(ListNode* head)
{
    // Time: O(n) Space: O(1)
    ListNode* walker{ head };
    ListNode* runner{ head };
    while (runner && runner->next)
    {
        walker = walker->next;
        runner = runner->next->next;
        if (walker == runner)
            return true;
    }

    return false;
}



bool LinkedListCycle_2(ListNode* head)
{
    // Time: O(n) Space: O(n)
    unordered_set<ListNode*> nodes;

    while (head)
    {
        if (nodes.count(head))
            return true;
        nodes.insert(head);
        head = head->next;
    }

    return false;
}
