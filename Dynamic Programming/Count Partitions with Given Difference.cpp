#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
int MOD = 1e9 + 7;
int f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (target == 0 && arr[0] == 0)
            return 2; // pick and not pick
        if (target == 0 || target == arr[0])
            return 1;
        return 0;
    }
    if (dp[ind][target] != -1)
    {
        return dp[ind][target];
    }
    int notPick = f(ind - 1, target, arr, dp);
    int pick = 0;
    if (arr[ind] <= target)
    {
        pick = f(ind - 1, target - arr[ind], arr, dp);
    }
    return dp[ind][target] = (pick + notPick) % MOD;
}
int findWays(vector<int> &arr, int target)
{
    // code here
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return f(n - 1, target, arr, dp);
}
int countPartitions(vector<int>& arr, int d)
{
    int n=arr.size();
    int totSum=accumulate(arr.begin(),arr.end(),0);
    if(totSum-d<0||(totSum-d)%2)
    {
        return false;
    }
    return findWays(arr,(totSum-d)/2);
}
//Optimized
int f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (target == 0 && arr[0] == 0)
            return 2; // pick and not pick
        if (target == 0 || target == arr[0])
            return 1;
        return 0;
    }
    if (dp[ind][target] != -1)
    {
        return dp[ind][target];
    }
    int notPick = f(ind - 1, target, arr, dp);
    int pick = 0;
    if (arr[ind] <= target)
    {
        pick = f(ind - 1, target - arr[ind], arr, dp);
    }
    return dp[ind][target] = (pick + notPick) % MOD;
}
int findWays(vector<int> &arr, int target)
{
    // code here
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return f(n - 1, target, arr, dp);
}
int countPartitions(vector<int>& arr, int d)
{
    int n=arr.size();
    int totSum=accumulate(arr.begin(),arr.end(),0);
    if(totSum-d<0||(totSum-d)%2)
    {
        return false;
    }
    return findWays(arr,(totSum-d)/2);
}