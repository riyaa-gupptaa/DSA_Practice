#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
// Such problems are solved using front Partition

// Express everything in terms of ind
// Explore all possibilities
// Take the min of all possibilities
// Write the base class
bool isPalindrome(int i, int j, string s)
{
    while (i < j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int f(int i, int n, string &str, vector<int> &dp)
{
    if (i == n)
    {
        return 0;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }
    int minCost = INT_MAX;
    for (int j = i; j < n; j++)
    {
        if (isPalindrome(i, j, str))
        {
            int cost = 1 + f(j + 1, n, str, dp);
            minCost = min(minCost, cost);
        }
    }
    return dp[i] = minCost;
}
int minCut(string s)
{
    int n = s.size();
    vector<int> dp(n, -1);
    return f(0, n, s, dp) - 1;
}

// Tabulation
class Solution
{
public:
    bool isPalindrome(int i, int j, const string &s)
    {
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    int minCut(string s)
    {
        int n = s.length();
        vector<int> dp(n + 1, 0); // dp[i] = min cuts needed for substring s[i...n-1]

        // Fill from right to left
        for (int i = n - 1; i >= 0; i--)
        {
            int minCost = INT_MAX;
            for (int j = i; j < n; j++)
            {
                if (isPalindrome(i, j, s))
                {
                    int cost = 1 + dp[j + 1];
                    minCost = min(minCost, cost);
                }
            }
            dp[i] = minCost;
        }

        return dp[0] - 1;
    }
};

// Space Optimization
class Solution
{
public:
    int minCut(string s)
    {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        vector<vector<bool>> isPal(n, vector<bool>(n, false));

        // Precompute palindromes in O(n^2)
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                if (s[i] == s[j] && (j - i <= 2 || isPal[i + 1][j - 1]))
                {
                    isPal[i][j] = true;
                }
            }
        }

        // dp[i] = min cuts needed for s[i..n-1]
        for (int i = n - 1; i >= 0; i--)
        {
            int minCost = INT_MAX;
            for (int j = i; j < n; j++)
            {
                if (isPal[i][j])
                {
                    int cost = 1 + dp[j + 1];
                    minCost = min(minCost, cost);
                }
            }
            dp[i] = minCost;
        }

        return dp[0] - 1;
    }
};
