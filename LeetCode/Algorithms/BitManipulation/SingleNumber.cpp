#include <vector>

using namespace std;



// Problem: https://leetcode.com/problems/single-number/
int SingleNumber(vector<int> nums)
{
    int result{};
    for (int n : nums)
        result ^= n;

    return result;
}
