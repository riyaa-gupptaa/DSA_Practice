#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
using namespace std;
// Generate all subsequences and choose if any of them gives a sum of k
bool f(int ind, int sum, vector<int> &arr)
{
    if (sum == 0)
    {
        return true;
    }
    if (ind == 0)
    {
        return arr[0] == sum;
    }
    bool nottake = f(ind - 1, sum, arr);
    bool take = false;
    if (sum >= arr[ind])
    {
        take = f(ind - 1, sum - arr[ind], arr);
    }
    return take || nottake;
}
bool isSubsetSum(vector<int> &arr, int sum)
{
    int n = arr.size();
    return f(n - 1, sum, arr);
}
// Time complexity is O(2^n)
// Space complexity is O(n)

// There are overlapping subproblems,hence we need memoization
bool f(int ind, int sum, vector<int> &arr, vector<vector<int>> &dp)
{
    if (sum == 0)
    {
        return true;
    }
    if (ind == 0)
    {
        return arr[0] == sum;
    }
    if (dp[ind][sum] != -1)
    {
        return dp[ind][sum];
    }
    bool nottake = f(ind - 1, sum, arr, dp);
    bool take = false;
    if (sum >= arr[ind])
    {
        take = f(ind - 1, sum - arr[ind], arr, dp);
    }
    return dp[ind][sum] = take || nottake;
}
bool isSubsetSum(vector<int> &arr, int sum)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    return f(n - 1, sum, arr, dp);
}
// Time complexity is O(N*target)
// Space complexity is O(N*target)+O(N)

// Tabulation
bool isSubsetSum(vector<int> &arr, int sum)
{
    int n = arr.size();
    vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    if (arr[0] <= sum)
        dp[0][arr[0]] = true;
    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= sum; target++)
        {
            bool nottake = dp[ind-1][target];
            bool take = false;
            if (target >= arr[ind])
            {
                take = dp[ind-1][target-arr[ind]];
            }
            dp[ind][target] = take || nottake;
        }
    }
    return dp[n-1][sum];
}

//Space Optimization
bool isSubsetSum(vector<int> &arr, int sum)
{
    int n=arr.size();
    vector<bool> curr(sum+1,0),prev(sum+1,0);
    prev[0]=curr[0]=true;
    prev[arr[0]]=true;
    for(int ind=1;ind<n;ind++)
    {
        for(int target=1;target<=sum;target++)
        {
            bool nottake=prev[target];
            bool take=false;
            if(arr[ind]<=target)
            {
                take=prev[target-arr[ind]];
            }
            curr[target]=take|nottake;
        }
        prev=curr;
    }
    return prev[sum];
}