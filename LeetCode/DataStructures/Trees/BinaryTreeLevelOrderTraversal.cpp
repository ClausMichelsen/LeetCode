#include <queue>
#include <vector>

#include "TreeNode.h"

using namespace std;



// Problem: https://leetcode.com/problems/binary-tree-level-order-traversal/
vector<vector<int>> BinaryTreeLevelOrderTraversal_Iterative(TreeNode* root)
{
    // Queue approach
    if (!root)
        return {};

    queue<TreeNode*> q;
    q.push(root);
    vector<vector<int>> nodes;
    while (!q.empty())
    {
        vector<int> v;
        const int len{ static_cast<int>(q.size()) };  // Deliberately out-of-date by the queue::push calls in the loop.
        for (int i{ 0 }; i < len; ++i)
        {
            TreeNode* node = q.front();
            q.pop();
            v.push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        nodes.push_back(v);
    }

    return nodes;
}




void FindNodes(TreeNode* node, int level, vector<vector<int>>& nodes);

vector<vector<int>> BinaryTreeLevelOrderTraversal_Recursive(TreeNode* root)
{
    vector<vector<int>> nodes;
    FindNodes(root, 0, nodes);
    return nodes;
}

void FindNodes(TreeNode* node, int level, vector<vector<int>>& nodes)
{
    if (!node)
        return;

    if (nodes.size() < level + 1)
        nodes.resize(level + 1);

    nodes[level].push_back(node->val);
    FindNodes(node->left, level + 1, nodes);
    FindNodes(node->right, level + 1, nodes);
}
