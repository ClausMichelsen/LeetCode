#include <gtest\gtest.h>

#include "Functions.h"



TEST(DynamicProgramming, ClimbingStairs)
{
    int ways0 = ClimbingStairs(2);
    EXPECT_EQ(2, ways0);

    int ways1 = ClimbingStairs(3);
    EXPECT_EQ(3, ways1);

    int ways3 = ClimbingStairs(10);
    EXPECT_EQ(89, ways3);
};

TEST(DynamicProgramming, CoinChange)
{
    int coins0 = CoinChange({ 1,2,5 }, 11);
    EXPECT_EQ(3, coins0);

    int coins1 = CoinChange({ 2 }, 3);
    EXPECT_EQ(-1, coins1);

    int coins2 = CoinChange({ 1 }, 0);
    EXPECT_EQ(0, coins2);

    int coins3 = CoinChange({ 1 }, 1);
    EXPECT_EQ(1, coins3);

    int coins4 = CoinChange({ 1 }, 2);
    EXPECT_EQ(2, coins4);

    int coins5 = CoinChange({ 2,5,10,1 }, 27);
    EXPECT_EQ(4, coins5);
};

TEST(DynamicProgramming, CombinationSumIV)
{
    int count0 = CombinationSumIV({ 1,2,3 }, 4);
    EXPECT_EQ(7, count0);

    int count1 = CombinationSumIV({ 9 }, 3);
    EXPECT_EQ(0, count1);
};

TEST(DynamicProgramming, HouseRobber_Iterative1)
{
    int money0 = HouseRobber_Iterative1({ 1,2,3,1 });
    EXPECT_EQ(4, money0);

    int money1 = HouseRobber_Iterative1({ 2,7,9,3,1 });
    EXPECT_EQ(12, money1);

    int money2 = HouseRobber_Iterative1({ 104,209,137,52,158,67,213,86,141,110,151,127,238,147,169,138,240,185,246,225,147,203,83,83,131,227,54,78,165,180,214,151,111,161,233,147,124,143 });
    EXPECT_EQ(3176, money2);
};

TEST(DynamicProgramming, HouseRobber_Iterative2)
{
    int money0 = HouseRobber_Iterative2({ 1,2,3,1 });
    EXPECT_EQ(4, money0);

    int money1 = HouseRobber_Iterative2({ 2,7,9,3,1 });
    EXPECT_EQ(12, money1);

    int money2 = HouseRobber_Iterative2({ 104,209,137,52,158,67,213,86,141,110,151,127,238,147,169,138,240,185,246,225,147,203,83,83,131,227,54,78,165,180,214,151,111,161,233,147,124,143 });
    EXPECT_EQ(3176, money2);
};

TEST(DynamicProgramming, HouseRobber_Recursive)
{
    int money0 = HouseRobber_Recursive({ 1,2,3,1 });
    EXPECT_EQ(4, money0);

    int money1 = HouseRobber_Recursive({ 2,7,9,3,1 });
    EXPECT_EQ(12, money1);

    int money2 = HouseRobber_Recursive({ 104,209,137,52,158,67,213,86,141,110,151,127,238,147,169,138,240,185,246,225,147,203,83,83,131,227,54,78,165,180,214,151,111,161,233,147,124,143 });
    EXPECT_EQ(3176, money2);
};

TEST(DynamicProgramming, HouseRobberII)
{
    int money0 = HouseRobberII({ 2,3,2 });
    EXPECT_EQ(3, money0);

    int money1 = HouseRobberII({ 1,2,3,1 });
    EXPECT_EQ(4, money1);

    int money2 = HouseRobberII({ 1,2,3 });
    EXPECT_EQ(3, money2);
};

TEST(DynamicProgramming, LongestCommonSubsequence)
{
    int len0 = LongestCommonSubsequence("abcde", "ace");
    EXPECT_EQ(3, len0);

    int len1 = LongestCommonSubsequence("abc", "abc");
    EXPECT_EQ(3, len1);

    int len2 = LongestCommonSubsequence("abc", "def");
    EXPECT_EQ(0, len2);
};

TEST(DynamicProgramming, LongestIncreasingSubsequence)
{
    int len0 = LongestIncreasingSubsequence({ 10,9,2,5,3,7,101,18 });
    EXPECT_EQ(4, len0);

    int len1 = LongestIncreasingSubsequence({ 0,1,0,3,2,3 });
    EXPECT_EQ(4, len1);

    int len2 = LongestIncreasingSubsequence({ 7,7,7,7,7,7,7 });
    EXPECT_EQ(1, len2);
};

TEST(DynamicProgramming, WordBreak_1)
{
    bool success0 = WordBreak_1("leetcode", { "leet", "code" });
    EXPECT_EQ(true, success0);

    bool success1 = WordBreak_1("applepenapple", { "apple","pen" });
    EXPECT_EQ(true, success1);

    bool success2 = WordBreak_1("catsandog", { "cats","dog","sand","and","cat" });
    EXPECT_EQ(false, success2);


    bool success3 = WordBreak_1("aaaaaaa", { "aaaa","aaa" });
    EXPECT_EQ(true, success3);

    bool success4 = WordBreak_1("aaaaaaaa", { "aaaa","aa","a" });
    EXPECT_EQ(true, success4);
};

TEST(DynamicProgramming, WordBreak_2)
{
    bool success0 = WordBreak_2("leetcode", { "leet", "code" });
    EXPECT_EQ(true, success0);

    bool success1 = WordBreak_2("applepenapple", { "apple","pen" });
    EXPECT_EQ(true, success1);

    bool success2 = WordBreak_2("catsandog", { "cats","dog","sand","and","cat" });
    EXPECT_EQ(false, success2);


    bool success3 = WordBreak_2("aaaaaaa", { "aaaa","aaa" });
    EXPECT_EQ(true, success3);

    bool success4 = WordBreak_2("aaaaaaaa", { "aaaa","aa","a" });
    EXPECT_EQ(true, success4);
};

TEST(DynamicProgramming, WordBreak_3)
{
    bool success0 = WordBreak_3("leetcode", { "leet", "code" });
    EXPECT_EQ(true, success0);

    bool success1 = WordBreak_3("applepenapple", { "apple","pen" });
    EXPECT_EQ(true, success1);

    bool success2 = WordBreak_3("catsandog", { "cats","dog","sand","and","cat" });
    EXPECT_EQ(false, success2);


    bool success3 = WordBreak_3("aaaaaaa", { "aaaa","aaa" });
    EXPECT_EQ(true, success3);

    bool success4 = WordBreak_3("aaaaaaaa", { "aaaa","aa","a" });
    EXPECT_EQ(true, success4);
};
