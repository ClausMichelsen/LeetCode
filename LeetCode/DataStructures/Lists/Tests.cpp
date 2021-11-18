#include <gtest\gtest.h>

#include "Functions.h"
#include "ListNode.h"



TEST(DataStructures_Lists, LinkedListCycle_Floyd)
{
    ListNode ln0_3{ -4, nullptr };
    ListNode ln0_2{ 0, &ln0_3 };
    ListNode ln0_1{ 2, &ln0_2 };
    ListNode ln0_0{ 3, &ln0_1 };
    ln0_3.next = &ln0_0;
    bool cycle0 = LinkedListCycle_Floyd(&ln0_0);
    EXPECT_EQ(true, cycle0);

    ListNode ln1_1{ 2, nullptr };
    ListNode ln1_0{ 1, &ln1_1 };
    ln1_1.next = &ln1_0;
    bool cycle1 = LinkedListCycle_Floyd(&ln1_0);
    EXPECT_EQ(true, cycle1);

    ListNode ln2_0{ 1, nullptr };
    bool cycle2 = LinkedListCycle_Floyd(&ln2_0);
    EXPECT_EQ(false, cycle2);
};

TEST(DataStructures_Lists, LinkedListCycle_Regular)
{
    ListNode ln0_3{ -4, nullptr };
    ListNode ln0_2{ 0, &ln0_3 };
    ListNode ln0_1{ 2, &ln0_2 };
    ListNode ln0_0{ 3, &ln0_1 };
    ln0_3.next = &ln0_0;
    bool cycle0 = LinkedListCycle_Regular(&ln0_0);
    EXPECT_EQ(true, cycle0);

    ListNode ln1_1{ 2, nullptr };
    ListNode ln1_0{ 1, &ln1_1 };
    ln1_1.next = &ln1_0;
    bool cycle1 = LinkedListCycle_Regular(&ln1_0);
    EXPECT_EQ(true, cycle1);

    ListNode ln2_0{ 1, nullptr };
    bool cycle2 = LinkedListCycle_Regular(&ln2_0);
    EXPECT_EQ(false, cycle2);
};

TEST(DataStructures_Lists, MergeKSortedLists)
{
    ListNode l0_2{ 5, nullptr };
    ListNode l0_1{ 4, &l0_2 };
    ListNode l0_0{ 1, &l0_1 };
    ListNode l1_2{ 4, nullptr };
    ListNode l1_1{ 3, &l1_2 };
    ListNode l1_0{ 1, &l1_1 };
    ListNode l2_1{ 6, nullptr };
    ListNode l2_0{ 2, &l2_1 };
    ListNode* mergedKLists0returned = MergeKSortedLists({ &l0_0, &l1_0, &l2_0 });
    EXPECT_EQ(1, mergedKLists0returned->val);
    EXPECT_EQ(nullptr, mergedKLists0returned->next->next->next->next->next->next->next->next);

    ListNode* mergedKLists1returned = MergeKSortedLists({ nullptr, nullptr });
    EXPECT_EQ(nullptr, mergedKLists1returned);
};

TEST(DataStructures_Lists, MergeTwoSortedLists)
{
    ListNode ln0_1_2{ 4, nullptr };
    ListNode ln0_1_1{ 2, &ln0_1_2 };
    ListNode ln0_1_0{ 1, &ln0_1_1 };
    ListNode ln0_2_2{ 4, nullptr };
    ListNode ln0_2_1{ 3, &ln0_2_2 };
    ListNode ln0_2_0{ 1, &ln0_2_1 };
    ListNode* merged0 = MergeTwoSortedLists(&ln0_1_0, &ln0_2_0);
    EXPECT_EQ(1, merged0->val);
    EXPECT_EQ(1, merged0->next->val);
    EXPECT_EQ(2, merged0->next->next->val);
    EXPECT_EQ(3, merged0->next->next->next->val);
    EXPECT_EQ(4, merged0->next->next->next->next->val);
    EXPECT_EQ(4, merged0->next->next->next->next->next->val);
    EXPECT_EQ(nullptr, merged0->next->next->next->next->next->next);
};

TEST(DataStructures_Lists, RemoveNthNodeFromEndOfList)
{
    ListNode ln0_4{ 5, nullptr };
    ListNode ln0_3{ 4, &ln0_4 };
    ListNode ln0_2{ 3, &ln0_3 };
    ListNode ln0_1{ 2, &ln0_2 };
    ListNode ln0_0{ 1, &ln0_1 };
    ListNode* ln0 = RemoveNthNodeFromEndOfList(&ln0_0, 2);
    EXPECT_EQ(1, ln0->val);
    EXPECT_EQ(2, ln0->next->val);
    EXPECT_EQ(3, ln0->next->next->val);
    EXPECT_EQ(5, ln0->next->next->next->val);
    EXPECT_EQ(nullptr, ln0->next->next->next->next);

    ListNode ln1_0{ 1, nullptr };
    ListNode* ln1 = RemoveNthNodeFromEndOfList(&ln1_0, 1);
    EXPECT_EQ(nullptr, ln1);

    ListNode ln2_1{ 2, nullptr };
    ListNode ln2_0{ 1, &ln2_1 };
    ListNode* ln2 = RemoveNthNodeFromEndOfList(&ln2_0, 1);
    EXPECT_EQ(1, ln2->val);
    EXPECT_EQ(nullptr, ln2->next);
};

TEST(DataStructures_Lists, ReorderList)
{
    ListNode* ln0 = new ListNode{ 1, new ListNode{2, new ListNode{3, new ListNode{4, nullptr}}} };
    ReorderList(ln0);
    EXPECT_EQ(1, ln0->val);
    EXPECT_EQ(4, ln0->next->val);
    EXPECT_EQ(2, ln0->next->next->val);
    EXPECT_EQ(3, ln0->next->next->next->val);
    EXPECT_EQ(nullptr, ln0->next->next->next->next);

    ListNode* ln1 = new ListNode{ 1, new ListNode{2, new ListNode{3, new ListNode{4, new ListNode{5, nullptr}}}} };
    ReorderList(ln1);
    EXPECT_EQ(1, ln1->val);
    EXPECT_EQ(5, ln1->next->val);
    EXPECT_EQ(2, ln1->next->next->val);
    EXPECT_EQ(4, ln1->next->next->next->val);
    EXPECT_EQ(3, ln1->next->next->next->next->val);
    EXPECT_EQ(nullptr, ln1->next->next->next->next->next);
};

TEST(DataStructures_Lists, ReverseLinkedList_Iterative)
{
    ListNode lnRev0_4{ 5, nullptr };
    ListNode lnRev0_3{ 4, &lnRev0_4 };
    ListNode lnRev0_2{ 3, &lnRev0_3 };
    ListNode lnRev0_1{ 2, &lnRev0_2 };
    ListNode lnRev0_0{ 1, &lnRev0_1 };
    ListNode* ln0 = ReverseLinkedList_Iterative(&lnRev0_0);
    EXPECT_EQ(5, ln0->val);
    EXPECT_EQ(4, ln0->next->val);
    EXPECT_EQ(3, ln0->next->next->val);
    EXPECT_EQ(2, ln0->next->next->next->val);
    EXPECT_EQ(1, ln0->next->next->next->next->val);
    EXPECT_EQ(nullptr, ln0->next->next->next->next->next);

    ListNode lnRev1_1{ 2, nullptr };
    ListNode lnRev1_0{ 1, &lnRev1_1 };
    ListNode* ln1 = ReverseLinkedList_Iterative(&lnRev1_0);
    EXPECT_EQ(2, ln1->val);
    EXPECT_EQ(1, ln1->next->val);
    EXPECT_EQ(nullptr, ln1->next->next);

    ListNode lnRev2_0{ 1, nullptr };
    ListNode* ln2 = ReverseLinkedList_Iterative(&lnRev2_0);
    EXPECT_EQ(1, ln2->val);
    EXPECT_EQ(nullptr, ln2->next);

    ListNode* ln3 = ReverseLinkedList_Iterative(nullptr);
    EXPECT_EQ(nullptr, ln3);
};

TEST(DataStructures_Lists, ReverseLinkedList_Recursive)
{
    ListNode lnRev0_4{ 5, nullptr };
    ListNode lnRev0_3{ 4, &lnRev0_4 };
    ListNode lnRev0_2{ 3, &lnRev0_3 };
    ListNode lnRev0_1{ 2, &lnRev0_2 };
    ListNode lnRev0_0{ 1, &lnRev0_1 };
    ListNode* ln0 = ReverseLinkedList_Recursive(&lnRev0_0);
    EXPECT_EQ(5, ln0->val);
    EXPECT_EQ(4, ln0->next->val);
    EXPECT_EQ(3, ln0->next->next->val);
    EXPECT_EQ(2, ln0->next->next->next->val);
    EXPECT_EQ(1, ln0->next->next->next->next->val);
    EXPECT_EQ(nullptr, ln0->next->next->next->next->next);

    ListNode lnRev1_1{ 2, nullptr };
    ListNode lnRev1_0{ 1, &lnRev1_1 };
    ListNode* ln1 = ReverseLinkedList_Recursive(&lnRev1_0);
    EXPECT_EQ(2, ln1->val);
    EXPECT_EQ(1, ln1->next->val);
    EXPECT_EQ(nullptr, ln1->next->next);

    ListNode lnRev2_0{ 1, nullptr };
    ListNode* ln2 = ReverseLinkedList_Recursive(&lnRev2_0);
    EXPECT_EQ(1, ln2->val);
    EXPECT_EQ(nullptr, ln2->next);

    ListNode* ln3 = ReverseLinkedList_Recursive(nullptr);
    EXPECT_EQ(nullptr, ln3);
};
