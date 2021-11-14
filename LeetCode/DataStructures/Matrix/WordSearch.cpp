#include <string>
#include <vector>

using namespace std;



bool exist(const vector<vector<char>>& board, const string& word, int pos, int x, int y, int cx, int cy, vector<vector<bool>>& visited);



// Problem: https://leetcode.com/problems/word-search/
bool WordSearch(vector<vector<char>> board, string word)
{
    // Time: O(m*n*4^l) Space: O(m*n + l)
    const int cx{ static_cast<int>(board[0].size()) };
    const int cy{ static_cast<int>(board.size()) };
    for (int x{ 0 }; x < cx; ++x)
    {
        for (int y{ 0 }; y < cy; ++y)
        {
            if (board[y][x] == word[0])
            {
                vector<vector<bool>> visited(cy, vector<bool>(cx));
                if (exist(board, word, 0, x, y, cx, cy, visited))
                    return true;
            }
        }
    }

    return false;
}

bool exist(const vector<vector<char>>& board, const string& word, int pos, int x, int y, int cx, int cy, vector<vector<bool>>& visited)
{
    if (word[pos] == board[y][x] && pos == word.length() - 1)
        return true;
    if (word[pos] != board[y][x])
        return false;

    visited[y][x] = true;

    if (x > 0 && !visited[y][x - 1] && exist(board, word, pos + 1, x - 1, y, cx, cy, visited))
        return true;
    if (y > 0 && !visited[y - 1][x] && exist(board, word, pos + 1, x, y - 1, cx, cy, visited))
        return true;
    if (x < cx - 1 && !visited[y][x + 1] && exist(board, word, pos + 1, x + 1, y, cx, cy, visited))
        return true;
    if (y < cy - 1 && !visited[y + 1][x] && exist(board, word, pos + 1, x, y + 1, cx, cy, visited))
        return true;

    visited[y][x] = false;

    return false;
}