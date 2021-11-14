#include <vector>

using namespace std;



// Problem: https://leetcode.com/problems/coin-change/
int CoinChange(vector<int> coins, int amount)
{
    vector<int> tab(amount + 1, amount + 1);
    tab[0] = 0;

    for (int coin : coins)
        for (int i{ coin }; i <= amount; ++i)
            tab[i] = min(tab[i], tab[i - coin] + 1);

    return tab.back() > amount ? -1 : tab.back();
}
