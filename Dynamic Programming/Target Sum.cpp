#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
int findWays(vector<int> &arr, int target)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }
    if (arr[0] <= target)
    {
        dp[0][arr[0]] = 1;
    }
    if (arr[0] == 0)
        dp[0][0] = 2;
    for (int i = 1; i < n; i++)
    {
        for (int s = 0; s <= target; s++)
        {
            int notTake = dp[i - 1][s];
            int take = 0;
            if (arr[i] <= s)
            {
                take = dp[i - 1][s - arr[i]];
            }
            dp[i][s] = notTake + take;
        }
    }
    return dp[n - 1][target];
}
int countPartitions(vector<int> &arr, int d)
{
    int n = arr.size();
    int totSum = accumulate(arr.begin(), arr.end(), 0);
    if (totSum - d < 0 || (totSum - d) % 2)
    {
        return false;
    }
    return findWays(arr, (totSum - d) / 2);
}
int findTargetSumWays(vector<int> &nums, int target)
{
    return countPartitions(nums, target);
}