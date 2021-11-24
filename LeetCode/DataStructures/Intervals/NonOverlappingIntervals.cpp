#include <algorithm>
#include <vector>

using namespace std;



// Problem: https://leetcode.com/problems/non-overlapping-intervals/
int NonOverlappingIntervals(vector<vector<int>> intervals)
{
    const int len{static_cast<int>(intervals.size())};
    sort(begin(intervals), end(intervals), [](const auto& left, const auto& right) { return left[0] < right[0]; });
    int result{};
    int prev{};
    for (int i{ 1 }; i < len; ++i)
    {
        if (intervals[i][0] < intervals[prev][1])
        {
            ++result;
            if (intervals[i][1] < intervals[prev][1])
                prev = i;
        }
        else
        {
            prev = i;
        }
    }

    return result;
}
