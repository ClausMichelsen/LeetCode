#include <algorithm>
#include <vector>

using namespace std;



// Problem: https://leetcode.com/problems/3sum/
vector<vector<int>> ThreeSum(vector<int> nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    for (int i{ 0 }; i < nums.size(); ++i)
    {
        if ((i != 0) && (nums[i] == nums[i - 1]))
            continue;

        const int n{ nums[i] };

        int left{ i + 1 }, right{ static_cast<int>(nums.size() - 1) };

        while (left < right)
        {
            if (left == i)
            {
                ++left;
                continue;
            }
            if (right == i)
            {
                --right;
                continue;
            }

            const int j{ n + nums[left] + nums[right] };
            if (!j)
            {
                vector<int> r{ n, nums[left], nums[right] };
                sort(r.begin(), r.end());
                result.push_back(r);

                // skip duplicate pairs 
                // brings the pointer to the last occurence of a repeated number in nums
                while (right - 1 >= left && nums[right - 1] == nums[right])
                    right--;
                while (left + 1 < right && nums[left + 1] == nums[left])
                    left++;

                // since we have skipped duplicates and are on the last occurence of the duplicate we need to update the pointers
                left++;
                right--;
            }
            else if (j < 0)
                ++left;
            else
                --right;
        }
    }

    return result;
}
