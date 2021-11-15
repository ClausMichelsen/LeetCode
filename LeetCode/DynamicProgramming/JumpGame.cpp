#include <vector>

using namespace std;



// Problem: https://leetcode.com/problems/jump-game/
bool JumpGame(vector<int> nums)
{
    // Time: O(n) Space: O(1)
    for (int i{ 0 }, distance{ 0 }; i < nums.size(), i <= distance; ++i)
    {
        distance = max(distance, i + nums[i]);
        if (distance >= nums.size() - 1)
            return true;
    }

    return false;
}
