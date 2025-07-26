#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
// Power set
// Recursion
// Various Subsequences-print all subsequences
// Check for increase
// Store the longest
// Express everything in terms of (ind)
// Explore all the paths
// Take the max length(notTake,Take)
int f(int ind, int prev_ind, vector<int> &nums, vector<vector<int>> &dp)
{
    int n = nums.size();
    if (ind == n)
    {
        return 0;
    }
    if (dp[ind][prev_ind] != -1)
    {
        return dp[ind][prev_ind];
    }
    int len = 0 + f(ind + 1, prev_ind, nums, dp);
    if (prev_ind == -1 || nums[ind] > nums[prev_ind])
    {
        len = max(len, 1 + f(ind + 1, ind, nums, dp));
    }
    return dp[ind][prev_ind] = len;
}
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return f(0, -1, nums, dp);
}
// Time complexity of O(2^n)
// Space complexity of O(N)

// Memoization
int f(int ind, int prev_ind, vector<int> &nums, vector<vector<int>> &dp)
{
    if (ind == nums.size())
        return 0;

    if (dp[ind][prev_ind + 1] != -1)
        return dp[ind][prev_ind + 1];

    int notTake = f(ind + 1, prev_ind, nums, dp);

    int take = 0;
    if (prev_ind == -1 || nums[ind] > nums[prev_ind])
        take = 1 + f(ind + 1, ind, nums, dp);

    return dp[ind][prev_ind + 1] = max(take, notTake);
}
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return f(0, -1, nums, dp);
}

// Tabulation
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0)); // dp[ind][prev_ind+1]

    // Fill the table from bottom to top
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--)
        {
            int notTake = dp[ind + 1][prev_ind + 1];
            int take = 0;
            if (prev_ind == -1 || nums[ind] > nums[prev_ind])
            {
                take = 1 + dp[ind + 1][ind + 1];
            }
            dp[ind][prev_ind + 1] = max(take, notTake);
        }
    }

    return dp[0][0]; // ind=0, prev_ind=-1 → mapped to dp[0][0]
}
// Time: O(n²)
// Space: O(n²)

// Space Optimization
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> next(n + 1, 0), curr(n + 1, 0);

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--)
        {
            int notTake = next[prev_ind + 1];
            int take = 0;
            if (prev_ind == -1 || nums[ind] > nums[prev_ind])
            {
                take = 1 + next[ind + 1];
            }
            curr[prev_ind + 1] = max(take, notTake);
        }
        next = curr;
    }

    return next[0];
}
