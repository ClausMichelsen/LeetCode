#include <gtest\gtest.h>

#include "Functions.h"



TEST(DataStructures_Intervals, MergeIntervals)
{
    vector<vector<int>> result0 = MergeIntervals({ { 1, 3 }, { 2, 6 }, { 8, 10 }, { 15, 18 } });
    sort(begin(result0), end(result0));
    EXPECT_EQ(1, result0[0][0]);
    EXPECT_EQ(6, result0[0][1]);
    EXPECT_EQ(8, result0[1][0]);
    EXPECT_EQ(10, result0[1][1]);
    EXPECT_EQ(15, result0[2][0]);
    EXPECT_EQ(18, result0[2][1]);

    vector<vector<int>> result1 = MergeIntervals({ { 1, 4 }, { 4, 5 } });
    sort(begin(result1), end(result1));
    EXPECT_EQ(1, result1[0][0]);
    EXPECT_EQ(5, result1[0][1]);
};

TEST(DataStructures_Intervals, NonOverlappingIntervals)
{
    const int result0 = NonOverlappingIntervals({ {1, 2}, {2, 3}, {3, 4}, {1, 3} });
    EXPECT_EQ(1, result0);

    const int result1 = NonOverlappingIntervals({ {1, 2}, {1, 2}, {1, 2} });
    EXPECT_EQ(2, result1);

    const int result2 = NonOverlappingIntervals({ {1, 2}, {2, 3} });
    EXPECT_EQ(0, result2);
};

