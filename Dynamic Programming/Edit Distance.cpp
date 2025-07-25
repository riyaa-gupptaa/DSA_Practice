#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
// String Matching
// insert of the same character
// delete and try findig somewhere else
// relace and match

// Recursion
// Express in terms of (i,j)
// Explore all paths of matching
// Return min(all paths)
// Base case

// if(s1[i]==s2[j]) return 0+f(i-1,j-1)
// Condition for insert 1+f(i,j-1)
// Condition for Delete 1+f(i-1,j)
// Condition for replace 1+f(i-1,j-1)
int f(int ind1, int ind2, string word1, string word2)
{
    if (ind1 < 0)
    {
        return ind2 + 1;
    }
    if (ind2 < 0)
    {
        return ind1 + 1;
    }
    if (word1[ind1] == word2[ind2])
    {
        return f(ind1 - 1, ind2 - 1, word1, word2);
    }
    return 1 + min(f(ind1 - 1, ind2, word1, word2), min(f(ind1, ind2 - 1, word1, word2), f(ind1 - 1, ind2 - 1, word1, word2)));
}
int minDistance(string word1, string word2)
{
    int n = word1.size();
    int m = word2.size();
    return f(n - 1, m - 1, word1, word2);
}

// Memoization
int f(int ind1, int ind2, string word1, string word2, vector<vector<int>> &dp)
{
    if (ind1 < 0)
    {
        return ind2 + 1;
    }
    if (ind2 < 0)
    {
        return ind1 + 1;
    }
    if (dp[ind1][ind2] != -1)
    {
        return dp[ind1][ind2];
    }
    if (word1[ind1] == word2[ind2])
    {
        return dp[ind1][ind2] = f(ind1 - 1, ind2 - 1, word1, word2, dp);
    }
    return dp[ind1][ind2] = 1 + min(f(ind1 - 1, ind2, word1, word2, dp),
                                    min(f(ind1, ind2 - 1, word1, word2, dp),
                                        f(ind1 - 1, ind2 - 1, word1, word2, dp)));
}
int minDistance(string word1, string word2)
{
    int n = word1.size();
    int m = word2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return f(n - 1, m - 1, word1, word2, dp);
}

// Tabulation
int minDistance(string word1, string word2)
{
    int n = word1.size();
    int m = word2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = i;
    }
    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = j;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
            }
        }
    }
    return dp[n][m];
}

// Space Optimisation
int minDistance(string word1, string word2)
{
    int n = word1.size();
    int m = word2.size();

    vector<int> prev(m + 1, 0), curr(m + 1, 0);

    for (int j = 0; j <= m; j++)
    {
        prev[j] = j; // base case for converting "" to word2
    }

    for (int i = 1; i <= n; i++)
    {
        curr[0] = i; // base case for converting word1 to ""
        for (int j = 1; j <= m; j++)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                curr[j] = prev[j - 1];
            }
            else
            {
                curr[j] = 1 + min({prev[j], curr[j - 1], prev[j - 1]});
            }
        }
        prev = curr; // move current row to previous for next iteration
    }

    return prev[m];
}
