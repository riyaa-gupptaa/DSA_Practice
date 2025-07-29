#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
int f(int i, int j, vector<int> &nums)
{
    if (i > j)
    {
        return 0;
    }
    int maxi = INT_MIN;
    for (int ind = 1; ind <= j; ind++)
    {
        int cost = nums[i - 1] * nums[ind] * nums[j + 1] + f(i, ind - 1, nums) + f(ind + 1, j, nums);
        maxi = max(maxi, cost);
    }
    return maxi;
}
int maxCoins(vector<int> &nums)
{
    int n = nums.size();
    nums.push_back(1);
    nums.insert(nums.begin(), 1);
    return f(0, n - 1, nums);
}
// Exponetial Time complexity

// Memoization
int f(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
{
    if (i > j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int mini = INT_MIN;
    for (int ind = i; ind <= j; ind++)
    {
        int cost = nums[i - 1] * nums[ind] * nums[j + 1] + f(i, ind - 1, nums, dp) + f(ind + 1, j, nums, dp);
        mini = max(mini, cost);
    }
    return dp[i][j] = mini;
}
int maxCoins(vector<int> &nums)
{
    int n = nums.size();
    nums.push_back(1);
    nums.insert(nums.begin(), 1);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return f(1, n, nums, dp);
}

// Tabulation
int maxCoins(vector<int> &nums)
{
    int n = nums.size();
    nums.push_back(1);
    nums.insert(nums.begin(), 1);
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    for (int i = n; i >= 1; i--)
    {
        for (int j = i; j <= n; j++)
        {   if(i>j)
            {
                continue;
            }
            int mini = INT_MIN;
            for (int ind = i; ind <= j; ind++)
            {
                int cost = nums[i - 1] * nums[ind] * nums[j + 1] + dp[i][ind-1] + dp[ind+1][j];
                mini = max(mini, cost);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][n];
}