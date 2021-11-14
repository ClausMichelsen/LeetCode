#include <vector>

using namespace std;


// Problem: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
int FindMinimumInRotatedSortedArray(vector<int> nums)
{
    // Time: O(logn) Space: O(1)
    int low{ 0 };
    int high{ static_cast<int>(nums.size() - 1) };

    while (low < high)
    {
        if (nums[low] < nums[high])
            return nums[low];

        const int mid{ low + (high - low) / 2 };
        if (nums[mid] >= nums[low])
            low = mid + 1;
        else
            high = mid;
    }

    return nums[low];
}
