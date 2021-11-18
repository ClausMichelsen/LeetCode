#include <unordered_set>

using namespace std;



// Problem: https://leetcode.com/problems/happy-number/
bool HappyNumber(int n)
{
	// Time: O(1) Space: O(1)
	unordered_set<int> nums;

	while (n != 1)
	{
		if (nums.count(n))
			return false;

		nums.insert(n);

		int sum{};
		while (n)
		{
			const int digit{ n % 10 };
			sum += digit * digit;
			n /= 10;
		}

		n = sum;
	}

	return true;
}
