#include <gtest\gtest.h>

#include <algorithm>

#include "Functions.h"
#include "TreeNode.h"

using namespace std;



TEST(Tree, BinaryTreeLevelOrderTraversal_Iterative)
{
    TreeNode* tree0{ new TreeNode{ 3, new TreeNode{ 9 }, new TreeNode{ 20, new TreeNode{ 15 }, new TreeNode{ 7 } } } };
    vector<vector<int>> result0 = BinaryTreeLevelOrderTraversal_Iterative(tree0);
    sort(begin(result0), end(result0));
    EXPECT_EQ(3, result0.size());
    EXPECT_EQ(3, result0[0][0]);
    EXPECT_EQ(9, result0[1][0]);
    EXPECT_EQ(20, result0[1][1]);
    EXPECT_EQ(15, result0[2][0]);
    EXPECT_EQ(7, result0[2][1]);

    TreeNode* tree1{ new TreeNode{ 1 } };
    vector<vector<int>> result1 = BinaryTreeLevelOrderTraversal_Iterative(tree1);
    EXPECT_EQ(1, result1.size());
    EXPECT_EQ(1, result1[0][0]);

    vector<vector<int>> result2 = BinaryTreeLevelOrderTraversal_Iterative(nullptr);
    EXPECT_EQ(0, result2.size());
};

TEST(Tree, BinaryTreeLevelOrderTraversal_Recursive)
{
    TreeNode* tree0{ new TreeNode{ 3, new TreeNode{ 9 }, new TreeNode{ 20, new TreeNode{ 15 }, new TreeNode{ 7 } } } };
    vector<vector<int>> result0 = BinaryTreeLevelOrderTraversal_Recursive(tree0);
    sort(begin(result0), end(result0));
    EXPECT_EQ(3, result0.size());
    EXPECT_EQ(3, result0[0][0]);
    EXPECT_EQ(9, result0[1][0]);
    EXPECT_EQ(20, result0[1][1]);
    EXPECT_EQ(15, result0[2][0]);
    EXPECT_EQ(7, result0[2][1]);

    TreeNode* tree1{ new TreeNode{ 1 } };
    vector<vector<int>> result1 = BinaryTreeLevelOrderTraversal_Recursive(tree1);
    EXPECT_EQ(1, result1.size());
    EXPECT_EQ(1, result1[0][0]);

    vector<vector<int>> result2 = BinaryTreeLevelOrderTraversal_Recursive(nullptr);
    EXPECT_EQ(0, result2.size());
};

TEST(DataStructures_Trees, InvertBinaryTree)
{
    TreeNode* input0 = new TreeNode{ 4, new TreeNode{ 2, new TreeNode{ 1 }, new TreeNode{ 3 } }, new TreeNode{ 7, new TreeNode{ 6 }, new TreeNode{ 9 } } };
    TreeNode* output0 = InvertBinaryTree(input0);
    EXPECT_EQ(4, output0->val);
    EXPECT_EQ(9, output0->left->left->val);
    EXPECT_EQ(1, output0->right->right->val);

    TreeNode* input1 = new TreeNode{ 2, new TreeNode{ 1 }, new TreeNode{ 3 } };
    TreeNode* output1 = InvertBinaryTree(input1);
    EXPECT_EQ(2, output1->val);
    EXPECT_EQ(3, output1->left->val);
    EXPECT_EQ(1, output1->right->val);

    TreeNode* output2 = InvertBinaryTree(nullptr);
    EXPECT_EQ(nullptr, output2);
};

TEST(DataStructures_Trees, KthSmallestElementInBST_Iterative)
{
    TreeNode* tree0{ new TreeNode{ 3, new TreeNode{ 1, nullptr, new TreeNode{ 2 } }, new TreeNode{ 4 } } };
    int x0 = 1;
    int val0 = KthSmallestElementInBST_Iterative(tree0, x0);
    EXPECT_EQ(1, val0);

    TreeNode* tree1{ new TreeNode{ 5, new TreeNode{ 3, new TreeNode{ 2, new TreeNode{ 1 }, nullptr }, new TreeNode{ 4 } }, new TreeNode{ 6 } } };
    int x1 = 3;
    int val1 = KthSmallestElementInBST_Iterative(tree1, x1);
    EXPECT_EQ(3, val1);
};

TEST(DataStructures_Trees, KthSmallestElementInBST_Recursive)
{
    TreeNode* tree0{ new TreeNode{ 3, new TreeNode{ 1, nullptr, new TreeNode{ 2 } }, new TreeNode{ 4 } } };
    int x0 = 1;
    int val0 = KthSmallestElementInBST_Recursive(tree0, x0);
    EXPECT_EQ(1, val0);

    TreeNode* tree1{ new TreeNode{ 5, new TreeNode{ 3, new TreeNode{ 2, new TreeNode{ 1 }, nullptr }, new TreeNode{ 4 } }, new TreeNode{ 6 } } };
    int x1 = 3;
    int val1 = KthSmallestElementInBST_Recursive(tree1, x1);
    EXPECT_EQ(3, val1);
};

TEST(DataStructures_Trees, MaximumDepthOfBinaryTree_Iterative)
{
    TreeNode* input0 = new TreeNode{ 3, new TreeNode{ 9 }, new TreeNode{ 20, new TreeNode{ 15 }, new TreeNode{ 7 } } };
    const int depth0 = MaximumDepthOfBinaryTree_Iterative(input0);
    EXPECT_EQ(3, depth0);

    TreeNode* input1 = new TreeNode{ 1, nullptr, new TreeNode{ 2 } };
    const int depth1 = MaximumDepthOfBinaryTree_Iterative(input1);
    EXPECT_EQ(2, depth1);

    const int depth2 = MaximumDepthOfBinaryTree_Iterative(nullptr);
    EXPECT_EQ(0, depth2);

    TreeNode* input3 = new TreeNode{ 0 };
    const int depth3 = MaximumDepthOfBinaryTree_Iterative(input3);
    EXPECT_EQ(1, depth3);
};

TEST(DataStructures_Trees, MaximumDepthOfBinaryTree_Recursive)
{
    TreeNode* input0 = new TreeNode{ 3, new TreeNode{ 9 }, new TreeNode{ 20, new TreeNode{ 15 }, new TreeNode{ 7 } } };
    const int depth0 = MaximumDepthOfBinaryTree_Recursive(input0);
    EXPECT_EQ(3, depth0);

    TreeNode* input1 = new TreeNode{ 1, nullptr, new TreeNode{ 2 } };
    const int depth1 = MaximumDepthOfBinaryTree_Recursive(input1);
    EXPECT_EQ(2, depth1);

    const int depth2 = MaximumDepthOfBinaryTree_Recursive(nullptr);
    EXPECT_EQ(0, depth2);

    TreeNode* input3 = new TreeNode{ 0 };
    const int depth3 = MaximumDepthOfBinaryTree_Recursive(input3);
    EXPECT_EQ(1, depth3);
};

TEST(DataStructures_Trees, SameTree)
{
    TreeNode* input0_0 = new TreeNode{ 1, new TreeNode{ 2 }, new TreeNode{ 3 } };
    TreeNode* input0_1 = new TreeNode{ 1, new TreeNode{ 2 }, new TreeNode{ 3 } };
    const bool same0 = SameTree(input0_0, input0_1);
    EXPECT_EQ(true, same0);

    TreeNode* input1_0 = new TreeNode{ 1, new TreeNode{ 2 }, nullptr };
    TreeNode* input1_1 = new TreeNode{ 1, nullptr, new TreeNode{ 2 } };
    const bool same1 = SameTree(input1_0, input1_1);
    EXPECT_EQ(false, same1);

    TreeNode* input2_0 = new TreeNode{ 1, new TreeNode{ 2 }, new TreeNode{ 1 } };
    TreeNode* input2_1 = new TreeNode{ 1, new TreeNode{ 1 }, new TreeNode{ 2 } };
    const bool same2 = SameTree(input2_0, input2_1);
    EXPECT_EQ(false, same2);
};

TEST(DataStructures_Trees, SerializeAndDeserializeBinaryTree)
{
    SerializeAndDeserializeBinaryTree serializer0;
    TreeNode* input0 = new TreeNode{ 1, new TreeNode{ 2 }, new TreeNode{ 3, new TreeNode{ 4 }, new TreeNode{ 5 } } };
    TreeNode* output0 = serializer0.deserialize(serializer0.serialize(input0));
    const bool same0 = SameTree(input0, output0);
    EXPECT_EQ(true, same0);

    SerializeAndDeserializeBinaryTree serializer1;
    TreeNode* output1 = serializer1.deserialize(serializer0.serialize(nullptr));
    EXPECT_EQ(nullptr, output1);

    SerializeAndDeserializeBinaryTree serializer2;
    TreeNode* input2 = new TreeNode{ 1 };
    TreeNode* output2 = serializer2.deserialize(serializer2.serialize(input2));
    const bool same2 = SameTree(input2, output2);
    EXPECT_EQ(true, same2);

    SerializeAndDeserializeBinaryTree serializer3;
    TreeNode* input3 = new TreeNode{ 1, new TreeNode{ 2 }, nullptr };
    TreeNode* output3 = serializer3.deserialize(serializer3.serialize(input3));
    const bool same3 = SameTree(input3, output3);
    EXPECT_EQ(true, same3);
};

TEST(DataStructures_Trees, SubtreeOfAnotherTree)
{
    TreeNode* root0{ new TreeNode{3, new TreeNode{4, new TreeNode{1, nullptr, nullptr}, new TreeNode{2, nullptr, nullptr}}, new TreeNode{5, nullptr, nullptr}} };
    TreeNode* subRoot0{ new TreeNode{4, new TreeNode{1, nullptr, nullptr}, new TreeNode{2, nullptr, nullptr}} };
    bool result0 = SubtreeOfAnotherTree(root0, subRoot0);
    EXPECT_EQ(true, result0);

    TreeNode* root1{ new TreeNode{1, new TreeNode{1, nullptr, nullptr}, nullptr} };
    TreeNode* subRoot1{ new TreeNode{1, nullptr, nullptr} };
    bool result1 = SubtreeOfAnotherTree(root1, subRoot1);
    EXPECT_EQ(true, result1);
};

TEST(DataStructures_Trees, ValidateBinarySearchTree)
{
    TreeNode* bst0{ new TreeNode{2, new TreeNode{1, nullptr, nullptr}, new TreeNode{3, nullptr, nullptr}} };
    bool valid0 = ValidateBinarySearchTree(bst0);
    EXPECT_EQ(true, valid0);

    TreeNode* bst1{ new TreeNode{5, new TreeNode{1, nullptr, nullptr}, new TreeNode{4, new TreeNode{3, nullptr, nullptr}, new TreeNode{6, nullptr, nullptr}}} };
    bool valid1 = ValidateBinarySearchTree(bst1);
    EXPECT_EQ(false, valid1);
};
