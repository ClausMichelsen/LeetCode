#include <vector>

using namespace std;



// Problem: https://leetcode.com/problems/number-of-longest-increasing-subsequence/
int NumberOfLongestIncreasingSubsequence(vector<int> nums)
{
    const int len{ static_cast<int>(nums.size()) };
    int result{};
    int max_len{};
    vector<int> lengths(len, 1);
    vector<int> counts(len, 1);
    for (int i{}; i < len; ++i)
    {
        for (int j{}; j < i; ++j)
        {
            if (nums[i] > nums[j])
            {
                if (lengths[i] == lengths[j] + 1) // Equal length?
                    counts[i] += counts[j];

                if (lengths[i] < lengths[j] + 1) // Longer?
                {
                    lengths[i] = lengths[j] + 1;
                    counts[i] = counts[j];
                }
            }
        }

        if (max_len == lengths[i]) // Have we found a new subsequence of existing longest length?
            result += counts[i];

        if (max_len < lengths[i]) // Have we found a longer subsequence?
        {
            max_len = lengths[i];
            result = counts[i];
        }
    }

    return result;
}
