#include <string>
#include <vector>

using namespace std;



// Problem: https://leetcode.com/problems/delete-operation-for-two-strings/
// Solution adapted from "Edit Distance": https://leetcode.com/problems/edit-distance/
int DeleteOperationForTwoStrings(string word1, string word2)
{
    // Time: O(m*n) Space: O(m*n)
    const int len1{ static_cast<int>(word1.length()) };
    const int len2{ static_cast<int>(word2.length()) };

    vector<vector<int>> tab(len1 + 1, vector<int>(len2 + 1));
    for (int i1{ 1 }; i1 <= len1; ++i1)
        tab[i1][0] = i1;
    for (int i2{ 1 }; i2 <= len2; ++i2)
        tab[0][i2] = i2;

    for (int i1{ 1 }; i1 <= len1; ++i1)
    {
        for (int i2{ 1 }; i2 <= len2; ++i2)
        {
            if (word1[i1 - 1] == word2[i2 - 1])
            {
                tab[i1][i2] = tab[i1 - 1][i2 - 1];
            }
            else
            {
                const int deleting{ tab[i1][i2 - 1] + 1 };
                const int inserting{ tab[i1 - 1][i2] + 1 };
                tab[i1][i2] = min(deleting, inserting);
            }
        }
    }

    return tab.back().back();
}
