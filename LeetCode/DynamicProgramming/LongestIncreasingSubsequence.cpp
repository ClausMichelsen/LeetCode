#include <vector>

using namespace std;



// Problem: https://leetcode.com/problems/longest-increasing-subsequence/
int LongestIncreasingSubsequence(vector<int> nums)
{
    vector<int> incs;
    for (int num : nums)
    {
        auto it{ lower_bound(begin(incs), end(incs), num) };
        if (it == end(incs))
            incs.push_back(num);
        else
            *it = num;
    }

    return static_cast<int>(incs.size());
}
