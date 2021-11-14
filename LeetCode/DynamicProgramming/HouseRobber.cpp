#include <vector>

using namespace std;



// Problem: https://leetcode.com/problems/house-robber/
int HouseRobber(vector<int>& nums, int house, vector<int>& memo);

int HouseRobber_Recursive(vector<int> nums)
{
    // Recursive with memoization - Time: O(n) Space: O(n)
    vector<int> memo(nums.size() + 1, -1);
    return HouseRobber(nums, static_cast<int>(nums.size()) - 1, memo);
}

int HouseRobber(vector<int>& nums, int house, vector<int>& memo)
{
    if (house < 0) return 0;
    if (memo[house] != -1) return memo[house];

    return memo[house] = max(HouseRobber(nums, house - 1, memo), HouseRobber(nums, house - 2, memo) + nums[house]);
}



int HouseRobber_Iterative1(vector<int> nums)
{
    // Iterative (bottom-up with memoization) - Time: O(n) Space: O(n)
    if (nums.empty())
        return 0;

    vector<int> dp(nums.size() + 1);
    dp[0] = 0;
    dp[1] = nums[0];

    for (int house{ 1 }; house < nums.size(); ++house)
    {
        dp[house + 1] = max(dp[house], dp[house - 1] + nums[house]);
    }

    return dp[nums.size()];
}



int HouseRobber_Iterative2(vector<int> nums)
{
    // Iterative (bottom-up with memoization) - Time: O(n) Space: O(1)
    if (nums.empty())
        return 0;

    int prePreMax{ 0 }, preMax{ 0 };
    for (int value : nums)
    {
        const int curMax{ max(prePreMax + value, preMax) };
        prePreMax = preMax;
        preMax = curMax;
    }

    return preMax;
}
