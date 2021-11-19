#include <stack>

#include "TreeNode.h"

using namespace std;



// Problem: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
int KthSmallestElementInBST_Iterative(TreeNode* root, int& k)
{
    stack<TreeNode*> nodes;
    TreeNode* p{ root };
    while (p || !nodes.empty())
    {
        while (p)
        {
            nodes.push(p);
            p = p->left;
        }

        p = nodes.top();
        nodes.pop();
        if (!--k)
            return p->val;
        p = p->right;
    }

    return root->val;
}


int KthSmallestElementInBST_Recursive(TreeNode* root, int& k)
{
    int x;
    if (root->left)
        if (-1 != (x = KthSmallestElementInBST_Recursive(root->left, k)))
            return x;
    if (!--k)
        return root->val;
    if (root->right)
        if (-1 != (x = KthSmallestElementInBST_Recursive(root->right, k)))
            return x;

    return -1;
}
