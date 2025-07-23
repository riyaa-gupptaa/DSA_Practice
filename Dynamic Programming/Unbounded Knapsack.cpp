#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
int f(int ind, int W, vector<int> &val, vector<int> &wt)
{
    if (ind == 0)
    {
        return (W / wt[0]) * val[0];
    }
    int notTake = 0 + f(ind - 1, W, wt, val);
    int take = INT_MIN;
    if (wt[ind] <= W)
    {
        take = val[ind] + f(ind, W - wt[ind], val, wt);
    }
    return max(take, notTake);
}
int knapSack(vector<int> &val, vector<int> &wt, int capacity)
{
    int n = val.size();
    return f(n - 1, capacity, val, wt);
}

// Memoization
int f(int ind, int W, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        return (W / wt[0]) * val[0];
    }
    if (dp[ind][W] != -1)
    {
        return dp[ind][W];
    }
    int notTake = 0 + f(ind - 1, W, val, wt, dp);
    int take = INT_MIN;
    if (wt[ind] <= W)
    {
        take = val[ind] + f(ind, W - wt[ind], val, wt, dp);
    }
    return dp[ind][W] = max(take, notTake);
}
int knapSack(vector<int> &val, vector<int> &wt, int capacity)
{
    // code here
    int n = val.size();
    vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
    return f(n - 1, capacity, val, wt, dp);
}

// Tabulation
int knapSack(vector<int> &val, vector<int> &wt, int capacity)
{
    int n = val.size();
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));
    for (int W = 0; W <= capacity; W++)
    {
        dp[0][W] = (int)(W / wt[0]) * val[0];
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int W = 0; W <= capacity; W++)
        {
            int notTake = 0 + dp[ind - 1][W];
            int take = 0;
            if (wt[ind] <= W)
            {
                take = val[ind] + dp[ind][W - wt[ind]];
            }
            dp[ind][W] = max(take, notTake);
        }
    }
    return dp[n - 1][capacity];
}

// Space Optmisation
int knapSack(vector<int> &val, vector<int> &wt, int capacity)
{
    int n = val.size();
    vector<int> prev(capacity + 1, 0), cur(capacity + 1, 0);
    for (int W = 0; W <= capacity; W++)
    {
        prev[W] = (int)(W / wt[0]) * val[0];
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int W = 0; W <= capacity; W++)
        {
            int notTake = 0 + prev[W];
            int take = 0;
            if (wt[ind] <= W)
            {
                take = val[ind] + cur[W - wt[ind]];
            }
            cur[W] = max(take, notTake);
        }
        prev = cur;
    }
    return prev[capacity];
}

//More Optimised
int knapSack(vector<int> &val, vector<int> &wt, int capacity)
{
    int n = val.size();
    vector<int> dp(capacity + 1, 0);

    for (int W = 0; W <= capacity; W++)
    {
        dp[W] = (int)(W / wt[0]) * val[0];
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int W = 0; W <= capacity; W++)
        {
            int notTake = dp[W];
            int take = 0;
            if (wt[ind] <= W)
            {
                take = val[ind] + dp[W - wt[ind]]; // dp instead of cur
            }
            dp[W] = max(take, notTake); // overwrite in place
        }
    }

    return dp[capacity];
}