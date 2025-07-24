#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
// Count the number of ways
// Express everything in terms of (i,j)
// Explore all Possibilities
// Return summation of all possibilities
int f(int i, int j, string s, string t)
{
    if (j < 0)
    {
        return 1;
    }
    if (i < 0)
    {
        return 0;
    }
    if (s[i] == t[j])
    {
        return f(i - 1, j - 1, s, t) + f(i - 1, j, s, t);
    }
    else
    {
        return f(i - 1, j, s, t);
    }
}
// Time complexity is Exponential
// Space complexity is O(N+M)
int numDistinct(string s, string t)
{
    int n = s.size();
    int m = t.size();
    return f(n - 1, m - 1, s, t);
}

// Memoization
int f(int i, int j, string s, string t, vector<vector<int>> &dp)
{
    if (j < 0)
    {
        return 1;
    }
    if (i < 0)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (s[i] == t[j])
    {
        return dp[i][j] = f(i - 1, j - 1, s, t, dp) + f(i - 1, j, s, t, dp);
    }
    else
    {
        return dp[i][j] = f(i - 1, j, s, t, dp);
    }
    return -1;
}
int numDistinct(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return f(n - 1, m - 1, s, t, dp);
}

// Tabulation
int numDistinct(string s, string t)
{
    int n = s.size();
    int m = t.size();
    const int MOD = 1e9 + 7;
    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
            }
            else
            {
                dp[i][j] = (dp[i - 1][j]) % MOD;
            }
        }
    }
    return dp[n][m];
}

// Space Optimization
int numDistinct(string s, string t)
{
    int n = s.size();
    int m = t.size();
    const int MOD = 1e9 + 7;

    vector<long long> prev(m + 1, 0), curr(m + 1, 0);
    prev[0] = curr[0] = 1; // empty target string

    for (int i = 1; i <= n; i++)
    {
        curr[0] = 1; // Every row starts with 1
        for (int j = m; j >= 1; j--)
        {
            if (s[i - 1] == t[j - 1])
            {
                curr[j] = (prev[j - 1] + prev[j]) % MOD;
            }
            else
            {
                curr[j] = prev[j] % MOD;
            }
        }
        prev = curr;
    }

    return prev[m];
}