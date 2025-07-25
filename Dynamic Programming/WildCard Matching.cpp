#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
// Express (i,j)
// Explore comparisons
// Out of all comparisons, if anyone can, you return true
bool f(int i, int j, string &s, string &p)
{
    // Base cases
    if (i < 0 && j < 0)
        return true;
    if (j < 0 && i >= 0)
        return false;
    if (i < 0 && j >= 0)
    {
        for (int k = 0; k <= j; k++)
        {
            if (p[k] != '*')
                return false;
        }
        return true;
    }

    // Match or '?'
    if (s[i] == p[j] || p[j] == '?')
    {
        return f(i - 1, j - 1, s, p);
    }

    // '*' can match zero or more characters
    if (p[j] == '*')
    {
        return f(i - 1, j, s, p) || f(i, j - 1, s, p);
    }

    return false;
}
bool isMatch(string s, string p)
{
    int n = s.size();
    int m = p.size();
    return f(n - 1, m - 1, s, p);
}
// Time complexity is exponential
// Space complexity is O(N+M)

// Memoization
bool f(int i, int j, string &s, string &p, vector<vector<int>> &dp)
{
    if (i < 0 && j < 0)
        return true;
    if (j < 0 && i >= 0)
        return false;
    if (i < 0 && j >= 0)
    {
        for (int k = 0; k <= j; k++)
        {
            if (p[k] != '*')
                return false;
        }
        return true;
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s[i] == p[j] || p[j] == '?')
    {
        return dp[i][j] = f(i - 1, j - 1, s, p, dp);
    }

    if (p[j] == '*')
    {
        return dp[i][j] = f(i - 1, j, s, p, dp) || f(i, j - 1, s, p, dp);
    }

    return dp[i][j] = false;
}

bool isMatch(string s, string p)
{
    int n = s.size();
    int m = p.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f(n - 1, m - 1, s, p, dp);
}

// Tabulation
bool isMatch(string s, string p)
{
    int n = s.size();
    int m = p.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

    // Base case: empty string and empty pattern match
    dp[0][0] = true;

    // Handle patterns like *, **, ***... matching with empty string
    for (int j = 1; j <= m; j++)
    {
        if (p[j - 1] == '*')
            dp[0][j] = dp[0][j - 1];
    }

    // Fill the table
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (p[j - 1] == '*')
            {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
            else
            {
                dp[i][j] = false;
            }
        }
    }

    return dp[n][m];
}

// Space Optimisation
bool isMatch(string s, string p)
{
    int n = s.size();
    int m = p.size();
    vector<bool> prev(m + 1, false), cur(m + 1, false);

    // Base case: empty string and empty pattern match
    prev[0] = true;

    // Initialize first row: pattern can match empty string only if it's all '*'
    for (int j = 1; j <= m; j++)
    {
        prev[j] = prev[j - 1] && (p[j - 1] == '*');
    }

    for (int i = 1; i <= n; i++)
    {
        cur[0] = false; // non-empty string can't match empty pattern
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
            {
                cur[j] = prev[j - 1];
            }
            else if (p[j - 1] == '*')
            {
                cur[j] = prev[j] || cur[j - 1];
            }
            else
            {
                cur[j] = false;
            }
        }
        prev = cur;
    }

    return prev[m];
}
