#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
// n is the rod length
int f(int ind, int n, vector<int> &cuts)
{
    if (ind == 0)
    {
        return (n * cuts[0]);
    }
    int notTake = f(ind - 1, n, cuts);
    int take = INT_MIN;
    int rodlength = ind + 1;
    if (rodlength <= n)
    {
        take = cuts[ind] + f(ind, n - rodlength, cuts);
    }
    return max(notTake, take);
}
int minCost(vector<int> &cuts)
{
    int n = cuts.size();
    return f(n - 1, n, cuts);
}
// Time complexity is Exponential
// Space complexity is O(Target)

// Memoization
int f(int ind, int n, vector<int> &price, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        return n * price[0];
    }
    if (dp[ind][n] != -1)
    {
        return dp[ind][n];
    }
    int notTake = f(ind - 1, n, price, dp);
    int take = INT_MIN;
    int rodlength = ind + 1;
    if (rodlength <= n)
    {
        take = price[ind] + f(ind, n - rodlength, price, dp); // FIXED
    }
    return dp[ind][n] = max(notTake, take);
}

int cutRod(vector<int> &price)
{
    int n = price.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return f(n - 1, n, price, dp);
}

// Tabulation
int cutRod(vector<int> &price)
{
    int n = price.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = i * price[0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            int notTake = dp[i - 1][j];
            int take = INT_MIN;
            int rodlength = i + 1;
            if (rodlength <= j)
            {
                take = price[i] + dp[i][j - rodlength];
            }
            dp[i][j] = max(take, notTake);
        }
    }
    return dp[n - 1][n];
}

// Space Optimization
int cutRod(vector<int> &price)
{
    int n = price.size();
    vector<int> prev(n + 1, 0), curr(n + 1, 0);

    // Base case
    for (int length = 0; length <= n; length++)
    {
        prev[length] = length * price[0];
    }

    for (int i = 1; i < n; i++)
    {
        int rodlength = i + 1;
        for (int length = 0; length <= n; length++)
        {
            int notTake = prev[length];
            int take = INT_MIN;
            if (rodlength <= length)
            {
                take = price[i] + curr[length - rodlength];
            }
            curr[length] = max(take, notTake);
        }
        prev = curr;
    }

    return prev[n];
}