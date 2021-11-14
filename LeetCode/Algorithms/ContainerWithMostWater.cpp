#include <vector>

using namespace std;



// Problem: https://leetcode.com/problems/container-with-most-water/
int ContainerWithMostWater(vector<int> height)
{
    // Time: O(n) Space: O(1)
    int left{ 0 };
    int right{ static_cast<int>(height.size()) - 1 };
    int water{};
    while (left < right)
    {
        const int cur_height{ min(height[left], height[right]) };
        water = max(water, (right - left) * cur_height);
        while (height[left] <= cur_height && left < right)
            ++left;
        while (height[right] <= cur_height && left < right)
            --right;
    }

    return water;
}
