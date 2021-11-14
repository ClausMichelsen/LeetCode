#include <vector>

using namespace std;



// Problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
int BestTimeToBuyAndSellStock(vector<int> prices)
{
    // Kadane - Time: O(n) Space: O(1)
    int curMax{ 0 };
    int totalMax{ 0 };
    for (int i{ 1 }; i < prices.size(); ++i)
    {
        curMax = max(0, curMax + prices[i] - prices[i - 1]);
        totalMax = max(totalMax, curMax);
    }

    return totalMax;
}
