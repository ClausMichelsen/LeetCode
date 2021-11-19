#include <algorithm>

#include "TreeNode.h"

using namespace std;



// Problem: https://leetcode.com/problems/invert-binary-tree/
TreeNode* InvertBinaryTree(TreeNode* root)
{
    if (!root)
        return nullptr;

    swap(root->left, root->right);
    InvertBinaryTree(root->left);
    InvertBinaryTree(root->right);

    return root;
}
