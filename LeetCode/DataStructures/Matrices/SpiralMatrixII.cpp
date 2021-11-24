#include <vector>

using namespace std;



// Problem: https://leetcode.com/problems/spiral-matrix-ii/
vector<vector<int>> SpiralMatrixII(int n)
{
    vector<vector<int>> result(n, vector<int>(n));

    int min_x{ 0 }, min_y{ 0 };
    int max_x{ n }, max_y{ n };
    const int max_count{ max_x * max_y };

    int x{ min_x }, y{ min_y };
    int cell{ 1 };
    while (cell <= max_count)
    {
        for (x = min_x; x < max_x; ++x)
            result[y][x] = cell++;
        ++min_y;
        --x;

        for (y = min_y; y < max_y; ++y)
            result[y][x] = cell++;
        --max_x;
        --y;

        if (result.size() == max_count)
            break;

        for (x = max_x - 1; x >= min_x; --x)
            result[y][x] = cell++;
        --max_y;
        ++x;

        for (y = max_y - 1; y >= min_y; --y)
            result[y][x] = cell++;
        ++min_x;
        ++y;
    }

    return result;
}
