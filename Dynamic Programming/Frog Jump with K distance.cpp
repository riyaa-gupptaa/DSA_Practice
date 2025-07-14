#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
using namespace std;
int f(int ind,vector<int> &heights,int k)
{
    if(ind==0)
    {
        return 0;
    }
    int minSteps=INT_MAX;
    for(int j=1;j<=k;j++)
    {
        if(ind-j>=0)
        {
        int jump=f(ind-j,heights,k)+abs(heights[ind]-heights[ind-j]);
        minSteps=min(minSteps,jump);
        }
    }
    return minSteps;
}
//Memoization
int f(int ind,vector<int> &heights,vector<int> &dp,int k)
{
    if(ind==0)
    {
        return 0;
    }
    if(dp[ind]!=-1)
    {
        return dp[ind];
    }
    int minSteps=INT_MAX;
    for(int j=1;j<=k;j++)
    {
        if(ind-j>=0)
        {
        int jump=f(ind-j,heights,dp,k)+abs(heights[ind]-heights[ind-j]);
        minSteps=min(minSteps,jump);
        }
    }
    return dp[ind]=minSteps;
}
//Time complexity is O(N)*k
//Space complexity is O(N)+O(N)

//Tabulation
int frogJumps(int n,vector<int> &heights,int k)
{
    vector<int> dp(n,0);
    dp[0]=0;
    for(int i=1;i<n;++i)
    {
        int minSteps=INT_MAX;
        for(int j=1;j<=k;++j)
        {
            if(i-j>=0)
            {
                int jump=dp[i-j]+abs(heights[i]-heights[i-j]);
                minSteps=min(minSteps,jump);
            }
        }
        dp[i]=minSteps;
    }
    return dp[n-1];
}
//Time Complexity is O(N*k)
//Space complexity is O(N)

//Space optimization
int frogJump(int n, vector<int>& heights, int k) {
    vector<int> dp(n, 0);
    dp[0] = 0;

    for (int i = 1; i < n; ++i) {
        int minSteps = INT_MAX;
        for (int j = 1; j <= k; ++j) {
            if (i - j >= 0) {
                int jump = dp[i - j] + abs(heights[i] - heights[i - j]);
                minSteps = min(minSteps, jump);
            }
        }
        dp[i] = minSteps;
    }

    return dp[n - 1];
}