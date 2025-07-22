#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
// Express in terms of (ind,W)
// Explore all possibilities
int f(int ind, int W, vector<int> &val, vector<int> &wt)
{
    if (ind == 0)
    {
        if (wt[0] <= W)
        {
            return val[0];
        }
        else
        {
            return 0;
        }
    }
    int notTake = 0 + f(ind - 1, W, val, wt);
    int take = INT_MIN;
    if (wt[ind] <= W)
    {
        take = val[ind] + f(ind - 1, W - wt[ind], val, wt);
    }
    return max(notTake, take);
}
int knapsack(int W, vector<int> &val, vector<int> &wt)
{
    int n = val.size();
    return f(n - 1, W, val, wt);
}
// Time complexity is O(2^n)
// Space complexity is O(N)

// Memoization
int f(int ind, int W, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (wt[0] <= W)
        {
            return val[0];
        }
        else
        {
            return 0;
        }
    }
    if (dp[ind][W] != -1)
    {
        return dp[ind][W];
    }
    int notTake = 0 + f(ind - 1, W, val, wt, dp);
    int take = INT_MIN;
    if (wt[ind] <= W)
    {
        take = val[ind] + f(ind - 1, W - wt[ind], val, wt, dp);
    }
    return dp[ind][W] = max(notTake, take);
}
int knapsack(int W, vector<int> &val, vector<int> &wt)
{
    int n = val.size();
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    return f(n - 1, W, val, wt, dp);
}

// Tabulation
// Base Case
// Ind,wt
// Copy the recursion
int knapsack(int W, vector<int> &val, vector<int> &wt)
{
    int n = val.size();
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));
    for (int w = wt[0]; w <= W; w++)
    {
        dp[0][w] = val[0];
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int w = 0; w <= W; w++)
        {
            int notTake = dp[ind - 1][w];
            int take = INT_MIN;
            if (wt[ind] <= w)
            {
                take = val[ind] + dp[ind - 1][w - wt[ind]];
            }
            dp[ind][w] = max(take, notTake);
        }
    }
    return dp[n - 1][W];
}

// Space Optimization
int knapsack(int W, vector<int> &val, vector<int> &wt)
{
    int n = val.size();
    vector<int> prev(W + 1, 0), curr(W + 1, 0);

    // Initialize base case
    for (int w = wt[0]; w <= W; w++)
    {
        prev[w] = val[0];
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int w = 0; w <= W; w++)
        {
            int notTake = prev[w];
            int take = INT_MIN;
            if (wt[ind] <= w)
            {
                take = val[ind] + prev[w - wt[ind]];
            }
            curr[w] = max(take, notTake);
        }
        prev = curr;
    }

    return prev[W];
}
// Space complexity is O(2*W)

// Further Optimization
int knapsack(int W, vector<int> &val, vector<int> &wt)
{
    int n = val.size();
    vector<int> dp(W + 1, 0);

    for (int w = wt[0]; w <= W; w++)
    {
        dp[w] = val[0];
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int w = W; w >= 0; w--)
        {
            if (wt[ind] <= w)
            {
                dp[w] = max(dp[w], val[ind] + dp[w - wt[ind]]);
            }
        }
    }

    return dp[W];
}