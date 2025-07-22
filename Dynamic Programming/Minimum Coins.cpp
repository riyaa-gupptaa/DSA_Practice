#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
int f(int ind, int amount, vector<int> &coins)
{
    if (ind == 0)
    {
        if (amount % coins[ind] == 0)
        {
            return amount / coins[ind];
        }
        else
        {
            return 1e9;
        }
    }
    int notTake = 0 + f(ind - 1, amount, coins);
    int take = INT_MAX;
    if (coins[ind] <= amount)
    {
        int take = 1 + f(ind - 1, amount - coins[ind], coins);
    }
    return min(take, notTake);
}
int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    return f(n - 1, amount, coins);
}
// Time complexity is O(2^n)
// Space complexity is O(target)

// Memoization
int f(int ind, int amount, vector<int> &coins, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (amount % coins[0] == 0)
            return amount / coins[0];
        else
            return 1e9; // impossible case
    }

    if (dp[ind][amount] != -1)
        return dp[ind][amount];

    int notTake = f(ind - 1, amount, coins, dp);
    int take = 1e9;
    if (coins[ind] <= amount)
    {
        take = 1 + f(ind, amount - coins[ind], coins, dp); // same index since infinite supply
    }

    return dp[ind][amount] = min(take, notTake);
}
int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    int ans = f(n - 1, amount, coins, dp);
    return (ans >= 1e9) ? -1 : ans;
}

// Tabulation
int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

    // Initialize the base case (first row)
    for (int t = 0; t <= amount; t++)
    {
        if (t % coins[0] == 0)
            dp[0][t] = t / coins[0];
        else
            dp[0][t] = 1e9;
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int t = 0; t <= amount; t++)
        {
            int notTake = dp[ind - 1][t];
            int take = 1e9;
            if (coins[ind] <= t)
                take = 1 + dp[ind][t - coins[ind]];

            dp[ind][t] = min(take, notTake);
        }
    }

    int ans = dp[n - 1][amount];
    return (ans >= 1e9) ? -1 : ans;
}

// Space Optimisation
int coinChange(vector<int> &coins, int amount)
{
    vector<int> prev(amount + 1, 1e9);

    // Base case for the first coin
    for (int t = 0; t <= amount; t++)
    {
        if (t % coins[0] == 0)
            prev[t] = t / coins[0];
    }

    // Process the rest of the coins
    for (int i = 1; i < coins.size(); i++)
    {
        for (int t = 0; t <= amount; t++)
        {
            int notTake = prev[t];
            int take = 1e9;
            if (coins[i] <= t)
                take = 1 + prev[t - coins[i]];

            prev[t] = min(take, notTake);
        }
    }

    return (prev[amount] >= 1e9) ? -1 : prev[amount];
}