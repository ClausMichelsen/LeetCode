#include <limits>

#include "TreeNode.h"

using namespace std;



// Problem: https://leetcode.com/problems/validate-binary-search-tree/
bool ValidateBinarySearchTree(TreeNode* node, long lower, long upper);

bool ValidateBinarySearchTree(TreeNode* root)
{
    return ValidateBinarySearchTree(root, numeric_limits<long>::min(), numeric_limits<long>::max());
}

bool ValidateBinarySearchTree(TreeNode* node, long lower, long upper)
{
    if (!node) return true;

    if (lower < node->val && node->val < upper) {
        return ValidateBinarySearchTree(node->left, lower, node->val) && 
               ValidateBinarySearchTree(node->right, node->val, upper);
    }

    return false;
}
