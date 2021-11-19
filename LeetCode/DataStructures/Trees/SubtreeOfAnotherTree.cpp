#include "TreeNode.h"



// Problem: https://leetcode.com/problems/subtree-of-another-tree/
bool ValidatePotentialSubTree(TreeNode* root, TreeNode* subRoot);

bool SubtreeOfAnotherTree(TreeNode* root, TreeNode* subRoot)
{
    if (!root)
        return false;

    if (root->val == subRoot->val && ValidatePotentialSubTree(root, subRoot))
        return true;

    return SubtreeOfAnotherTree(root->left, subRoot)
        || SubtreeOfAnotherTree(root->right, subRoot);
}

bool ValidatePotentialSubTree(TreeNode* root, TreeNode* subRoot)
{
    if (root->val != subRoot->val)
        return false;
    if (!root->left != !subRoot->left || !root->right != !subRoot->right)
        return false;

    if (root->left && !ValidatePotentialSubTree(root->left, subRoot->left))
        return false;
    if (root->right && !ValidatePotentialSubTree(root->right, subRoot->right))
        return false;

    return true;
}
