#include <queue>
#include <vector>

#include "ListNode.h"

using namespace std;



// Problem: https://leetcode.com/problems/merge-k-sorted-lists/
ListNode* MergeKSortedLists(vector<ListNode*> lists)
{
    vector<ListNode*>::iterator it = remove_if(begin(lists), end(lists), [](const auto* l) { return !l; });
    if (it != lists.end())
        lists.erase(it, end(lists));

    auto comp{ [](const auto* l, const auto* r) { return l->val > r->val; } };
    priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> sorted_lists(begin(lists), end(lists), comp);

    ListNode* root{};
    ListNode* last{};
    while (!sorted_lists.empty())
    {
        ListNode* ln{ sorted_lists.top() };
        if (!root)
            root = ln;
        if (last)
            last->next = ln;
        last = ln;
        sorted_lists.pop();

        if (ln->next)
            sorted_lists.push(ln->next);
    }

    return root;
}
