#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
int f(int ind, int jumps, vector<int> &nums)
{
    int n = nums.size();
    if (ind >= n - 1)
    {
        return jumps;
    }
    int mini = INT_MAX;
    for (int i = 1; i <= nums[ind]; i++)
    {
        mini = min(mini, f(ind + i, jumps + 1, nums));
    }
    return mini;
}
int jump(vector<int> &nums)
{
    int n = nums.size();
    return f(0, 0, nums);
}
// Time complexity is exponential
// Space complexity is O(N)

// Memoized
int f(int ind, vector<int> &nums, vector<int> &dp)
{
    int n = nums.size();
    if (ind >= n - 1)
    {
        return 0;
    }
    if (dp[ind] != -1)
    {
        return dp[ind];
    }
    int mini = INT_MAX;
    for (int i = 1; i <= nums[ind]; i++)
    {
        if (ind + 1 < n)
        {
            int jumps = f(ind + i, nums, dp);
            if (jumps != INT_MAX)
            {
                mini=min(mini,1+jumps);
            }
        }
    }
    return dp[ind]=mini;
}
int jump(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);
    return f(0,nums,dp);
}
//Time complexity is O(N*N)
//Space complexity is O(N*N)

//Greedy Algorithm
int jump(vector<int> &nums)
{
    int n=nums.size();
    int jumps=0,l=0,r=0;
    while(r<n-1)
    {
        int farthest=0;
        for(int ind=l;ind<=r;ind++)
        {
            farthest=max(ind+nums[ind],farthest);
        }
        l=r+1;
        r=farthest;
        jumps=jumps+1;
    }
    return jumps;
}
//Time complexity is O(N)
//Space complexity is O(1)