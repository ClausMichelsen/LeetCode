#include <vector>

using namespace std;



// Problem: https://leetcode.com/problems/binary-search/
int BinarySearch(vector<int> nums, int target)
{
    // Time: O(logN) Space: O(1)
    int low{ 0 };
    int high{ static_cast<int>(nums.size()) - 1 };

    while (low <= high)
    {
        const int mid{ (low + high) / 2 };
        if (nums[mid] == target)
            return mid;

        if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}
