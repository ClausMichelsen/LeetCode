#include <vector>

using namespace std;



// Problem: https://leetcode.com/problems/sort-colors/
void SortColors(vector<int>& nums)
{
	// Time: O(n) Space: O(1)
	int left{};
	int mid{};
	int right{ static_cast<int>(nums.size()) - 1 };
	while (mid <= right)
	{
		if (nums[mid] == 0)
		{
			swap(nums[left++], nums[mid++]);
		}
		else if (nums[mid] == 1)
		{
			++mid;
		}
		else if (nums[mid] == 2)
		{
			swap(nums[mid], nums[right--]);
		}
	}
}
