#include "TreeNode.h"



// Problem: https://leetcode.com/problems/same-tree/
bool SameTree(TreeNode* p, TreeNode* q)
{
    if (!p || !q)
        return p == q;

    if (p->val != q->val)
        return false;

    return SameTree(p->left, q->left) && SameTree(p->right, q->right);
}
