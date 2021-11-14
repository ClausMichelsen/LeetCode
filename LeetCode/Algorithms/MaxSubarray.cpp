#include <limits>
#include <vector>

using namespace std;



// Problem: https://leetcode.com/problems/maximum-subarray/
// Implemented using Kadane's algorithm: https://en.wikipedia.org/wiki/Maximum_subarray_problem#Kadane's_algorithm
int MaxSubarray(vector<int> nums)
{
    // Time: O(n) Space: O(1)
    int curSum{ 0 };
    int maxSum{ nums[0] };
    for (int num : nums)
    {
        curSum = max(curSum + num, num);
        maxSum = max(maxSum, curSum);
    }

    return maxSum;
}
