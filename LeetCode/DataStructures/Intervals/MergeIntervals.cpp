#include <algorithm>
#include <vector>

using namespace std;



// Problem: https://leetcode.com/problems/merge-intervals/
vector<vector<int>> MergeIntervals(vector<vector<int>> intervals)
{
    vector<vector<int>> result;

    sort(intervals.begin(), intervals.end(), [](const auto& interval0, const auto& interval1) { return interval0[0] < interval1[0]; });

    vector<int> interval{ -1, -1 };
    for (int i{ 0 }; i < intervals.size(); ++i)
    {
        if (intervals[i][0] > interval[1] && interval[1] != -1)
        {   // This interval comes after our active one.
            result.push_back(interval);
            interval[0] = -1;
            interval[1] = -1;
        }

        if (interval[0] == -1)
            interval[0] = intervals[i][0];
        else
            interval[0] = min(interval[0], intervals[i][0]);

        if (interval[1] == -1)
            interval[1] = intervals[i][1];
        else
            interval[1] = max(interval[1], intervals[i][1]);

        if (i == intervals.size() - 1)
            result.push_back(interval);
    }

    return result;
}
