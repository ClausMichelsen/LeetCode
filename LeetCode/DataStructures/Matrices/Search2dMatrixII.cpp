#include <vector>

using namespace std;



// Problem: https://leetcode.com/problems/search-a-2d-matrix-ii/
bool Search2dMatrixII(vector<vector<int>> matrix, int target)
{
    const int cx{ static_cast<int>(matrix[0].size()) };
    const int cy{ static_cast<int>(matrix.size()) };
    int x{ cx - 1 };
    int y{};
    while (x >= 0 && y < cy)
    {
        if (matrix[y][x] == target)
            return true;

        if (matrix[y][x] >= target)
            --x;
        else
            ++y;
    }

    return false;
}
