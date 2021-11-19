#include <vector>

using namespace std;



// Problem: https://leetcode.com/problems/spiral-matrix/
vector<int> SpiralOrder(vector<vector<int>> matrix)
{
    vector<int> result;

    int min_x{ 0 }, min_y{ 0 };
    int max_x{ static_cast<int>(matrix[0].size()) }, max_y{ static_cast<int>(matrix.size()) };
    const int max_count{ max_x * max_y };

    int x{ min_x }, y{ min_y };
    while (result.size() < max_count)
    {
        for (x = min_x; x < max_x; ++x)
            result.push_back(matrix[y][x]);
        ++min_y;
        --x;

        for (y = min_y; y < max_y; ++y)
            result.push_back(matrix[y][x]);
        --max_x;
        --y;

        if (result.size() == max_count)
            break;

        for (x = max_x - 1; x >= min_x; --x)
            result.push_back(matrix[y][x]);
        --max_y;
        ++x;

        for (y = max_y - 1; y >= min_y; --y)
            result.push_back(matrix[y][x]);
        ++min_x;
        ++y;
    }

    return result;
}
