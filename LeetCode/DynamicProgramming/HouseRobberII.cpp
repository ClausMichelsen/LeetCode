#include <vector>

using namespace std;



// Problem: https://leetcode.com/problems/house-robber-ii/
int HouseRobberII(vector<int>& nums, int left, int right);

int HouseRobberII(vector<int> nums)
{
    // Time: O(2n) = Space: O(1)
    if (nums.empty())
        return 0;
    if (nums.size() == 1)
        return nums[0];

    return max(HouseRobberII(nums, 0, static_cast<int>(nums.size()) - 2),
        HouseRobberII(nums, 1, static_cast<int>(nums.size()) - 1));
}

int HouseRobberII(vector<int>& nums, int left, int right)
{
    if (nums.empty())
        return 0;

    int prePreMax{ 0 }, preMax{ 0 };
    for (int i{ left }; i <= right; ++i)
    {
        const int value{ nums[i] };
        const int curMax{ max(prePreMax + value, preMax) };
        prePreMax = preMax;
        preMax = curMax;
    }

    return preMax;
}
