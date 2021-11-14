#include <set>
#include <vector>

using namespace std;



// Problem: https://leetcode.com/problems/contains-duplicate/
bool ContainsDuplicate(vector<int> nums)
{
    // Time: O(n) Space: O(n)
    std::set<int> s;
    for (auto i : nums)
    {
        if (s.count(i))
            return true;
        s.insert(i);
    }

    return false;
}


