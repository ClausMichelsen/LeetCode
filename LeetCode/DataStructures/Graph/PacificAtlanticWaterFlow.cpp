#include <vector>

using namespace std;



// Problem: https://leetcode.com/problems/pacific-atlantic-water-flow/
void PacificAtlanticWaterFlow(vector<vector<int>>& heights, vector<vector<bool>>& visited_and_accepted, int y, int x);

vector<vector<int>> PacificAtlanticWaterFlow(vector<vector<int>> heights)
{
    vector<vector<bool>> atlantic(heights.size(), vector<bool>(heights[0].size(), false));
    vector<vector<bool>> pacific(heights.size(), vector<bool>(heights[0].size(), false));

    for (int y{ 0 }; y < heights.size(); ++y)
    {
        PacificAtlanticWaterFlow(heights, pacific, y, 0);
        PacificAtlanticWaterFlow(heights, atlantic, y, static_cast<int>(heights[0].size()) - 1);
    }

    for (int x{ 0 }; x < heights[0].size(); ++x)
    {
        PacificAtlanticWaterFlow(heights, pacific, 0, x);
        PacificAtlanticWaterFlow(heights, atlantic, static_cast<int>(heights.size()) - 1, x);
    }

    vector<vector<int>> result;
    for (int y{ 0 }; y < heights.size(); ++y)
    {
        for (int x{ 0 }; x < heights[0].size(); ++x)
        {
            if (atlantic[y][x] && pacific[y][x])
                result.push_back({ y, x });
        }
    }

    return result;
}

void PacificAtlanticWaterFlow(vector<vector<int>>& heights, vector<vector<bool>>& visited_and_accepted, int y, int x)
{
    visited_and_accepted[y][x] = true;

    if (x < heights[0].size() - 1 && !visited_and_accepted[y][x + 1] && heights[y][x] <= heights[y][x + 1])
        PacificAtlanticWaterFlow(heights, visited_and_accepted, y, x + 1);

    if (y < heights.size() - 1 && !visited_and_accepted[y + 1][x] && heights[y][x] <= heights[y + 1][x])
        PacificAtlanticWaterFlow(heights, visited_and_accepted, y + 1, x);

    if (x > 0 && !visited_and_accepted[y][x - 1] && heights[y][x] <= heights[y][x - 1])
        PacificAtlanticWaterFlow(heights, visited_and_accepted, y, x - 1);

    if (y > 0 && !visited_and_accepted[y - 1][x] && heights[y][x] <= heights[y - 1][x])
        PacificAtlanticWaterFlow(heights, visited_and_accepted, y - 1, x);
}
