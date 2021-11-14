#include <vector>

using namespace std;



// Problem: https://leetcode.com/problems/maximum-product-subarray/
int MaximumProductSubarray(vector<int> nums)
{
    // Time: O(n) Space: O(1)
    int result{ nums[0] };
    for (int i{ 1 }, minr{ result }, maxr{ result }; i < nums.size(); ++i)
    {
        if (nums[i] < 0)
            swap(minr, maxr);

        maxr = max(nums[i], maxr * nums[i]);
        minr = min(nums[i], minr * nums[i]);

        result = max(maxr, result);
    }

    return result;
}
