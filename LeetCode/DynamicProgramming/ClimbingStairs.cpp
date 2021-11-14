#include <vector>

using namespace std;



// Problem: https://leetcode.com/problems/climbing-stairs/
int ClimbingStairs(int n)
{
    vector<int> ways(max(n, 2));
    ways[0] = 1;
    ways[1] = 2;
    for (int i{ 2 }; i < n; ++i)
    {
        ways[i] = ways[i - 1] + ways[i - 2];
    }

    return ways[n - 1];
}
