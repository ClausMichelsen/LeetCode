#include <algorithm>
#include <vector>

using namespace std;



// Problem: https://leetcode.com/problems/rotate-image/
void RotateImage(vector<vector<int>>& matrix)
{
    reverse(begin(matrix), end(matrix));
    for (int i{ 0 }; i < matrix.size(); ++i)
        for (int j{ i + 1 }; j < matrix[0].size(); ++j)
            swap(matrix[i][j], matrix[j][i]);
}
