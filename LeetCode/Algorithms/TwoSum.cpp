#include <unordered_map>
#include <vector>

using namespace std;



// Problem: https://leetcode.com/problems/two-sum/
vector<int> TwoSum(vector<int> nums, int target)
{
    // Time: O(n) Space: O(n)
    vector<int> result;
    unordered_map<int, size_t> hm;
    const int size{ static_cast<int>(nums.size()) };
    for (int i{ 0 }; i < size; ++i)
    {
        const int n{ nums[i] };
        const auto it{ hm.find(target - n) };
        if (it != hm.end())
        {
            result.push_back(i);
            result.push_back(static_cast<int>(it->second));
            return result;
        }

        hm[n] = i;
    }

    return result;
}
