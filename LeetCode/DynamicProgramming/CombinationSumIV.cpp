#include <vector>

using namespace std;



// Problem: 
int CombinationSumIV(vector<int> nums, int target)
{
    vector<unsigned int> combos(target + 1, 0);
    combos[0] = 1;

    for (int i{ 1 }; i <= target; ++i)
    {
        for (int num : nums)
        {
            if (i >= num)
                combos[i] += combos[i - num];
        }
    }

    return combos.back();
}
