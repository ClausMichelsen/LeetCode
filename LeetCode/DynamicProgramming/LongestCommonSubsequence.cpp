#include <string>
#include <vector>

using namespace std;



// Problem: https://leetcode.com/problems/longest-common-subsequence/
int LongestCommonSubsequence(string a, string b)
{
    vector<vector<int>> tab(a.size() + 1, vector<int>(b.size() + 1, 0));
    for (int ia{ 1 }; ia <= a.size(); ++ia)
    {
        for (int ib{ 1 }; ib <= b.size(); ++ib)
        {
            if (a[ia - 1] == b[ib - 1])
                tab[ia][ib] = tab[ia - 1][ib - 1] + 1;
            else
                tab[ia][ib] = max(tab[ia - 1][ib], tab[ia][ib - 1]);
        }
    }

    return tab.back().back();
}
