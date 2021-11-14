#include "ListNode.h"



// Problem: https://leetcode.com/problems/merge-two-sorted-lists/
ListNode* MergeTwoSortedLists(ListNode* l1, ListNode* l2)
{
    // Time: O(m+n) Space: O(1)
    ListNode* list{ 0 };
    ListNode* back{ 0 };

    while (l1 || l2)
    {
        if ((l1 && l2 && l1->val <= l2->val) || (l1 && !l2))
        {
            if (list) // Implies 'back' set too.
                back->next = l1;
            else
                list = l1;

            back = l1;
            l1 = l1->next;
        }
        else
        {
            if (list)
                back->next = l2;
            else
                list = l2;

            back = l2;
            l2 = l2->next;
        }
    }

    return list;
}
