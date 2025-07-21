#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
// Express in terms of (ind,target)
// Explore all possibilities
// Sum of all the possibilities and return
int MOD = 1e9 + 7;
int f(int ind, int target, vector<int> &arr)
{
    if (target == 0)
    {
        return 1;
    }
    if (ind == 0)
    {
        return (arr[ind] == target);
    }
    int notPick = f(ind - 1, target, arr);
    int pick = 0;
    if (arr[ind] <= target)
    {
        pick = arr[ind] + f(ind - 1, target - arr[ind], arr);
    }
    return pick + notPick;
}
int perfectSum(vector<int> &arr, int target)
{
    int n = arr.size();
    return f(n - 1, target, arr);
}
//Time complexity-O(2^n)
//Space Complexity-O(N)

// Using memoization
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
int perfectSum(vector<int> &arr, int target)
{
    // code here
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return f(n - 1, target, arr, dp);
}
//Time complexity is O(N*Sum)
//Space complexity is O(N*Sum)

//Tabulation
int perfectSum(vector<int> &arr, int target)
{
    int n=arr.size();
    vector<vector<int>> dp(n,vector<int>(target+1,0));
    for(int i=0;i<n;i++)
    {
        dp[i][0]=1;
    }
    if(arr[0]<=target)
    {
    dp[0][arr[0]]=1;
    }
    if (arr[0] == 0)
        dp[0][0] = 2;
    for(int i=1;i<n;i++)
    {
        for(int s=0;s<=target;s++)
        {
            int notTake=dp[i-1][s];
            int take=0;
            if(arr[i]<=s)
            {
                take=dp[i-1][s-arr[i]];
            }
            dp[i][s]=notTake+take;
        }
    }
    return dp[n-1][target];
}