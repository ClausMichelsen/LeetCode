#include <vector>

using namespace std;



// Problem: https://leetcode.com/problems/number-of-islands/
bool FindIsland(vector<vector<char>>& grid, int cx, int cy, int x, int y, int island);

int NumberOfIslands(vector<vector<char>> grid)
{
    // Time: O(n) Space: O(1)
    int islands{};
    int cx{ static_cast<int>(grid[0].size()) };
    int cy{ static_cast<int>(grid.size()) };
    for (int x{ 0 }; x < cx; ++x)
    {
        for (int y{ 0 }; y < cy; ++y)
        {
            if (FindIsland(grid, cx, cy, x, y, islands))
                ++islands;
        }
    }

    return islands;
}

bool FindIsland(vector<vector<char>>& grid, int cx, int cy, int x, int y, int island)
{
    if (grid[y][x] == '0')
        return false;
    if (grid[y][x] != '1')
        return false;

    grid[y][x] = '2';
    if (y > 0) FindIsland(grid, cx, cy, x, y - 1, island);
    if (x > 0) FindIsland(grid, cx, cy, x - 1, y, island);
    if (y < cy - 1) FindIsland(grid, cx, cy, x, y + 1, island);
    if (x < cx - 1) FindIsland(grid, cx, cy, x + 1, y, island);

    return true;
}
