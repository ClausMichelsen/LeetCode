#include "ListNode.h"

#include <unordered_set>

using namespace std;



// Problem: https://leetcode.com/problems/linked-list-cycle/
bool LinkedListCycle_Regular(ListNode* head)
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



// Floyd's cycle-finding algorithm, a.k.a. "tortoise and hare algorithm".
bool LinkedListCycle_Floyd(ListNode* head)
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
