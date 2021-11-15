#include <string>
#include <vector>


using namespace std;



// Problem: https://leetcode.com/problems/decode-ways/
int DecodeWays_Tabulation(string s)
{
    // Time: O(n) Space: O(n)
    const int len{ static_cast<int>(s.size()) };
    vector<int> dp(len + 1);
    dp[len] = 1;
    for (int i{ len - 1 }; i >= 0; --i)
    {
        if (s[i] == '0')
        {
            dp[i] = 0;
        }
        else
        {
            dp[i] = dp[i + 1];
            if (i < len - 1 && (s[i] == '1' || s[i] == '2' && s[i + 1] < '7'))
                dp[i] += dp[i + 2];
        }
    }
    return s.empty() ? 0 : dp[0];
}



int DecodeWays_Recursive(string s, int i, vector<int>& memo);

int DecodeWays_Recursive(string s)
{
    // Time: O(n) Space: O(n)
    vector<int> memo(s.length(), 0);
    return DecodeWays_Recursive(s, 0, memo);
}

int DecodeWays_Recursive(string s, int i, vector<int>& memo)
{
    const int len{ static_cast<int>(s.length()) };

    if (i == len) return 1;
    if (s[i] == '0') return 0;
    if (memo[i] > 0) return memo[i];

    int res{ DecodeWays_Recursive(s, i + 1, memo) };
    if (i < len - 1) // At least two digits left.
        if (s[i] == '1' || (s[i] == '2' && s[i + 1] < '7')) // Legal two-digit number.
            res += DecodeWays_Recursive(s, i + 2, memo);

    return memo[i] = res;
}
