#include <map>

using namespace std;



// Problem: https://leetcode.com/problems/unique-paths/
int UniquePaths(int m, int n, map<pair<int, int>, int>& memo);

int UniquePaths(int m, int n)
{
    map<pair<int, int>, int> memo;
    return UniquePaths(m, n, memo);
}

int UniquePaths(int m, int n, map<pair<int, int>, int>& memo)
{
    if (!m || !n) return 0;
    if (m == 1 && n == 1) return 1;
    if (memo.count({ m, n })) return memo[{m, n}];

    return memo[{m, n}] = UniquePaths(m - 1, n, memo) + UniquePaths(m, n - 1, memo);
}
