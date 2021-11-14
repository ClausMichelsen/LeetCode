#include <unordered_set>
#include <vector>

using namespace std;



// Problem: https://leetcode.com/problems/set-matrix-zeroes/
void SetMatrixZeroes(vector<vector<int>>& matrix)
{
	unordered_set<int> cols, rows;
	const int width{ static_cast<int>(matrix[0].size()) };
	const int height{ static_cast<int>(matrix.size()) };

	for (int y{ 0 }; y < height; ++y)
		for (int x{ 0 }; x < width; ++x)
			if (matrix[y][x] == 0)
			{
				cols.insert(x);
				rows.insert(y);
			}

	for (auto row : rows)
		for (int x{ 0 }; x < width; ++x)
			matrix[row][x] = 0;

	for (auto col : cols)
		for (int y{ 0 }; y < height; ++y)
			matrix[y][col] = 0;
}
