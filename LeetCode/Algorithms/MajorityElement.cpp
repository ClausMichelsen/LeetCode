#include <algorithm>
#include <unordered_map>

using namespace std;



// Problem: https://leetcode.com/problems/majority-element/
// The Boyer-Moore Majority Vote Algorithm is superior to the below, but I wasn't familiar with it.
int MajorityElement(vector<int> nums)
{
    unordered_map<int, int> counts;
    for (int num : nums)
        ++counts[num];
    auto compare{ [](const auto& a, const auto& b) { return a.second < b.second; } };
    return max_element(begin(counts), end(counts), compare)->first;
}
