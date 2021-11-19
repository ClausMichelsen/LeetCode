#include <algorithm>
#include <stack>

#include "TreeNode.h"


using namespace std;



// Problem: https://leetcode.com/problems/maximum-depth-of-binary-tree/
int MaximumDepthOfBinaryTree_Iterative(TreeNode* root)
{
    // Time: O(n) Space: O(1)
    if (!root)
        return 0;

    int depth{};
    stack<TreeNode*> s;
    s.push(root);
    while (!s.empty())
    {
        const int count{ static_cast<int>(s.size()) };
        for (int i{}; i < count; ++i)
        {
            TreeNode* node{ s.top() };
            s.pop();

            if (node->left)  s.push(node->left);
            if (node->right) s.push(node->right);
        }
        
        ++depth;
    }

    return depth;
}



int MaximumDepthOfBinaryTree_Recursive(TreeNode* root)
{
    // Time: O(n) Space: O(n)
    return !root ? 0 : 1 + max(MaximumDepthOfBinaryTree_Recursive(root->left), MaximumDepthOfBinaryTree_Recursive(root->right));
}
