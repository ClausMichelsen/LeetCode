#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;



// Problem: https://leetcode.com/problems/max-points-on-a-line/
[[nodiscard]] int GreatestCommonDenominator(int a, int b) noexcept;

// TODO
int maxPoints(vector<vector<int>> points)
{
    const int count{ static_cast<int>(points.size()) };
    int result{};
    for (int i{}; i < count; ++i)
    {
        unordered_map<string, int> counter;
        int dup{ 1 };
        for (int j{ i + 1 }; j < count; ++j)
        {
            if (points[j][0] == points[i][0] && points[j][1] == points[i][1])
            {
                ++dup;
            }
            else
            {
                const int dx{ points[j][0] - points[i][0] };
                const int dy{ points[j][1] - points[i][1] };
                const int gcd{ GreatestCommonDenominator(dx, dy) };
                ++counter[to_string(dx / gcd) + '_' + to_string(dy / gcd)];
            }
        }

        result = max(result, dup);
        for (auto p : counter)
        {
            result = max(result, p.second + dup);
        }
    }
    
    return result;
}

[[nodiscard]] int GreatestCommonDenominator(int a, int b) noexcept
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }

    return a;
}
