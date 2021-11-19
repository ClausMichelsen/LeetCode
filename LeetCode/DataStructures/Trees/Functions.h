#pragma once


#include <sstream>
#include <vector>

#include "TreeNode.h"

using namespace std;



vector<vector<int>> BinaryTreeLevelOrderTraversal_Iterative(TreeNode* root);
vector<vector<int>> BinaryTreeLevelOrderTraversal_Recursive(TreeNode* root);
TreeNode* InvertBinaryTree(TreeNode* root);
int KthSmallestElementInBST_Iterative(TreeNode* root, int& k);
int KthSmallestElementInBST_Recursive(TreeNode* root, int& k);
int MaximumDepthOfBinaryTree_Iterative(TreeNode* root);
int MaximumDepthOfBinaryTree_Recursive(TreeNode* root);
bool SameTree(TreeNode* p, TreeNode* q);
bool SubtreeOfAnotherTree(TreeNode* root, TreeNode* subRoot);
bool ValidateBinarySearchTree(TreeNode* root);

class SerializeAndDeserializeBinaryTree
{
public:
    string serialize(TreeNode* root);
    TreeNode* deserialize(string data);

private:
    void serialize(TreeNode* node, ostringstream& oss);
    TreeNode* deserialize(istringstream& iss);
};
