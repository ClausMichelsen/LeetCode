#include <gtest\gtest.h>

#include "Algorithms.h"



TEST(Algorithms, BestTimeToBuyAndSellStock)
{
    const int profit0 = BestTimeToBuyAndSellStock({ 7,1,5,3,6,4 });
    EXPECT_EQ(5, profit0);

    const int profit1 = BestTimeToBuyAndSellStock({ 7,6,4,3,1 });
    EXPECT_EQ(0, profit1);
};

TEST(Algorithms, BinarySearch)
{
    const int result0 = BinarySearch({ -1,0,3,5,9,12 }, 9);
    EXPECT_EQ(4, result0);

    const int result1 = BinarySearch({ -1,0,3,5,9,12 }, 2);
    EXPECT_EQ(-1, result1);
};

TEST(Algorithms, BitwiseAndOfNumbersRange_Iterative)
{
    int result0 = BitwiseAndOfNumbersRange_Iterative(5, 7);
    EXPECT_EQ(4, result0);

    int result1 = BitwiseAndOfNumbersRange_Iterative(0, 0);
    EXPECT_EQ(0, result1);

    int result2 = BitwiseAndOfNumbersRange_Iterative(1, 2147483647);
    EXPECT_EQ(0, result2);
};

TEST(Algorithms, BitwiseAndOfNumbersRange_Recursive)
{
    int result0 = BitwiseAndOfNumbersRange_Recursive(5, 7);
    EXPECT_EQ(4, result0);

    int result1 = BitwiseAndOfNumbersRange_Recursive(0, 0);
    EXPECT_EQ(0, result1);

    int result2 = BitwiseAndOfNumbersRange_Recursive(1, 2147483647);
    EXPECT_EQ(0, result2);
};

TEST(Algorithms, ContainerWithMostWater)
{
    const int water0 = ContainerWithMostWater({ 1,8,6,2,5,4,8,3,7 });
    EXPECT_EQ(49, water0);

    const int water1 = ContainerWithMostWater({ 1,1 });
    EXPECT_EQ(1, water1);

    const int water2 = ContainerWithMostWater({ 4,3,2,1,4 });
    EXPECT_EQ(16, water2);

    const int water3 = ContainerWithMostWater({ 1,2,1 });
    EXPECT_EQ(2, water3);

};

TEST(Algorithms, ContainsDuplicate)
{
    bool dup0 = ContainsDuplicate({ 1,2,3,1 });
    EXPECT_EQ(true, dup0);

    bool dup1 = ContainsDuplicate({ 1,2,3,4 });
    EXPECT_EQ(false, dup1);

    bool dup2 = ContainsDuplicate({ 1,1,1,3,3,4,3,2,4,2 });
    EXPECT_EQ(true, dup2);

};

TEST(Algorithms, FindMinimumInRotatedSortedArray)
{
    int min0 = FindMinimumInRotatedSortedArray({ 3,4,5,1,2 });
    EXPECT_EQ(1, min0);

    int min1 = FindMinimumInRotatedSortedArray({ 4,5,6,7,0,1,2 });
    EXPECT_EQ(0, min1);

    int min2 = FindMinimumInRotatedSortedArray({ 11,13,15,17 });
    EXPECT_EQ(11, min2);

    int min3 = FindMinimumInRotatedSortedArray({ 1 });
    EXPECT_EQ(1, min3);

    int min4 = FindMinimumInRotatedSortedArray({ 2,1 });
    EXPECT_EQ(1, min4);

    int min5 = FindMinimumInRotatedSortedArray({ 5,1,2,3,4 });
    EXPECT_EQ(1, min5);

    int min6 = FindMinimumInRotatedSortedArray({ 3,1,2 });
    EXPECT_EQ(1, min6);
};

TEST(Algorithms, HappyNumber)
{
    const bool happy0 = HappyNumber(19);
    EXPECT_EQ(true, happy0);

    const bool happy1 = HappyNumber(2);
    EXPECT_EQ(false, happy1);
};

TEST(Algorithms, MajorityElement)
{
    const int element0 = MajorityElement({ 3, 2, 3 });
    EXPECT_EQ(3, element0);

    const int element1 = MajorityElement({ 2, 2, 1, 1, 1, 2, 2 });
    EXPECT_EQ(2, element1);
};

TEST(Algorithms, MaximumProductSubarray)
{
    const int spa0 = MaximumProductSubarray({ 2, 3, -2, 4 });
    EXPECT_EQ(6, spa0);

    const int spa1 = MaximumProductSubarray({ -2, 0, -1 });
    EXPECT_EQ(0, spa1);
};

TEST(Algorithms, MaxSubarray)
{
    const int sa0 = MaxSubarray({ -2, 1, -3, 4, -1, 2, 1, -5, 4 });
    EXPECT_EQ(6, sa0);

    const int sa1 = MaxSubarray({ 1 });
    EXPECT_EQ(1, sa1);

    const int sa2 = MaxSubarray({ 5, 4, -1, 7, 8 });
    EXPECT_EQ(23, sa2);

    const int sa3 = MaxSubarray({ -1 });
    EXPECT_EQ(-1, sa3);
};

TEST(Algorithms, SingleNumber)
{
    const int result0 = SingleNumber({ 2, 2, 1 });
    EXPECT_EQ(1, result0);

    const int result1 = SingleNumber({ 4, 1, 2, 1, 2 });
    EXPECT_EQ(4, result1);

    const int result2 = SingleNumber({ 1 });
    EXPECT_EQ(1, result2);
};

TEST(Algorithms, SortColors)
{
    vector<int> colors0{ 2, 0, 2, 1, 1, 0 };
    SortColors(colors0);
    EXPECT_EQ(6, colors0.size());
    EXPECT_EQ(0, colors0[0]);
    EXPECT_EQ(0, colors0[1]);
    EXPECT_EQ(1, colors0[2]);
    EXPECT_EQ(1, colors0[3]);
    EXPECT_EQ(2, colors0[4]);
    EXPECT_EQ(2, colors0[5]);

    vector<int> colors1{ 2, 0, 1 };
    SortColors(colors1);
    EXPECT_EQ(3, colors1.size());
    EXPECT_EQ(0, colors1[0]);
    EXPECT_EQ(1, colors1[1]);
    EXPECT_EQ(2, colors1[2]);

    vector<int> colors2{ 0 };
    SortColors(colors2);
    EXPECT_EQ(1, colors2.size());
    EXPECT_EQ(0, colors2[0]);

    vector<int> colors3{ 1 };
    SortColors(colors3);
    EXPECT_EQ(1, colors3.size());
    EXPECT_EQ(1, colors3[0]);

    vector<int> colors4{ 1,2,2,2,2,0,0,0,1,1 };
    SortColors(colors4);
    EXPECT_EQ(0, colors4[0]);
    EXPECT_EQ(2, colors4[9]);
};

TEST(Algorithms, TwoSum)
{
    vector<int> indicies0 = TwoSum({ 2,7,11,15 }, 9);
    sort(begin(indicies0), end(indicies0));
    EXPECT_EQ(0, indicies0[0]);
    EXPECT_EQ(1, indicies0[1]);

    vector<int> indicies1 = TwoSum({ 3,2,4 }, 6);
    sort(begin(indicies1), end(indicies1));
    EXPECT_EQ(1, indicies1[0]);
    EXPECT_EQ(2, indicies1[1]);

    vector<int> indicies2 = TwoSum({ 3,3 }, 6);
    sort(begin(indicies2), end(indicies2));
    EXPECT_EQ(0, indicies2[0]);
    EXPECT_EQ(1, indicies2[1]);

};

TEST(Algorithms, ThreeSum)
{
    vector<vector<int>> result0 = ThreeSum({ -1,0,1,2,-1,-4 });
    EXPECT_EQ(2, result0.size());

    vector<vector<int>> result1 = ThreeSum({});
    EXPECT_EQ(0, result1.size());

    vector<vector<int>> result2 = ThreeSum({ 0 });
    EXPECT_EQ(0, result2.size());
};
