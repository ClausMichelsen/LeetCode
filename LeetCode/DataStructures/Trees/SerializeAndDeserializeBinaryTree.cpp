#include <sstream>

#include "Functions.h"
#include "TreeNode.h"

using namespace std;



// Problem: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
string SerializeAndDeserializeBinaryTree::serialize(TreeNode* root)
{
    ostringstream oss;
    serialize(root, oss);
    return oss.str();
}

TreeNode* SerializeAndDeserializeBinaryTree::deserialize(string data)
{
    istringstream iss(data);
    return deserialize(iss);
}

void SerializeAndDeserializeBinaryTree::serialize(TreeNode* node, ostringstream& oss)
{
    if (!node)
        oss << "* ";
    else
    {
        oss << node->val << " ";
        serialize(node->left, oss);
        serialize(node->right, oss);
    }
}

TreeNode* SerializeAndDeserializeBinaryTree::deserialize(istringstream& iss)
{
    string s;
    iss >> s;
    if (s == "*")
        return nullptr;

    TreeNode* node = new TreeNode(stoi(s));
    node->left = deserialize(iss);
    node->right = deserialize(iss);

    return node;
}
