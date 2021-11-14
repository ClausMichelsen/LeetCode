#include <algorithm>
#include <string>
#include <vector>

using namespace std;



// Problem: https://leetcode.com/problems/word-break/
bool WordBreak_1(string s, vector<string> wordDict)
{
    vector<bool> hits(static_cast<int>(s.length()) + 1, false);
    hits[0] = true;

    for (int i{ 0 }; i < s.length(); ++i)
    {
        if (!hits[i])
            continue;

        for (string word : wordDict)
        {
            if (s.find(word, i) == i)
            {
                hits[i + word.length()] = true;
            }
        }
    }

    return hits[s.length()];
}

bool WordBreak_2(string s, vector<string> wordDict)
{
    if (wordDict.size() == 0) return false;

    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;

    for (int i = 1; i <= s.size(); i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (dp[j])
            {
                string word = s.substr(j, i - j);
                if (find(begin(wordDict), end(wordDict), word) != wordDict.end())
                {
                    dp[i] = true;
                    break; //next i
                }
            }
        }
    }

    return dp[s.size()];
}

bool WordBreak_3(string s, vector<string> wordDict)
{
    vector<int> hits;
    hits.push_back(0);

    bool hit_found;

    do
    {
        hit_found = false;
        for (int hit : hits)
        {
            for (const string& word : wordDict)
            {
                if (s.find(word, hit) != hit)
                    continue;

                const int new_hit{ hit + static_cast<int>(word.length()) };
                if (find(begin(hits), end(hits), new_hit) != end(hits))
                    continue;

                hits.push_back(new_hit);
                hit_found = true;
            }
        }
    } while (hit_found);

    sort(begin(hits), end(hits));
    return hits.back() == s.length();
}
