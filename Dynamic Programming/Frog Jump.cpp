#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
using namespace std;
//For memoization remember which of the parameters are changing
//Recursive Solution
int f(int ind,vector<int> &height)
{
    if(ind==0)
    {
        return 0;
    }
    int left=f(ind-1,height)+abs(height[ind]-height[ind-1]);
    int right=INT_MAX;
    if(ind>1)
    {
        right=f(ind-2,height)+abs(height[ind]-height[ind-2]);
    }
    return min(left,right);
}
int minCost(vector<int> &height)
{
    int n=height.size();
    return f(n-1,height);
}
//Using Dynamic Programming
int f(int ind,vector<int> &height,vector<int> &dp)
{
    if(ind==0)
    {
        return 0;
    }
    if(dp[ind]!=-1)
    {
        return dp[ind];
    }
    int left=f(ind-1,height,dp)+abs(height[ind]-height[ind-1]);
    int right=INT_MAX;
    if(ind>1)
    {
        right=f(ind-2,height,dp)+abs(height[ind]-height[ind-2]);
    }
    return dp[ind]=min(left,right);
}
int minCost(vector<int> &height)
{
    int n=height.size();
    vector<int> dp(n+1,-1);
    return f(n-1,height,dp);
}
//Tabulation
int frogjump(int n,vector<int> &heights)
{
    vector<int> dp(n,0);
    dp[0]=0;
    for(int i=1;i<heights.size();i++)
    {
        int fs=dp[i-1]+abs(heights[i]-heights[i-1]);
        int ss=INT_MAX;
        if(i>1)
        {
            ss=dp[i-2]+abs(heights[i]-heights[i-2]);
        }
        dp[i]=min(fs,ss);
    }
    return dp[n-1];
}