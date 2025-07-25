#include<iostream>
#include<vector>
using namespace std;
//Maximum k transactions allowed

int maximumProfit(vector<int> &prices,int n,int k)
{
    vector<vector<int>> after(2,vector<int>(k+1,0));
    vector<vector<int>> curr(2,vector<int> (k+1,0));
    for(int ind=n-1;ind>=0;ind--)
    {
        for(int buy=0;buy<=1;buy++)
        {
            for(int cap=1;cap<=k;cap++)
            {
                if(buy==1)
                {
                    curr[buy][cap]=max(-prices[ind]+after[0][cap],0+after[1][cap]);
                }
                else{
                    curr[buy][cap]=max(prices[ind]+after[1][cap-1],0+after[0][cap]);
                }
            }
        }
        after=curr;
    }
    return after[1][k];
}

//Another approach
int f(int ind,int tranNo,vector<int> &prices,int n,int k)
{
    if(ind==n||tranNo==2*k)
    {
        return 0;
    }
    if(tranNo%2==0)
    {
        return max(-prices[ind]+f(ind+1,tranNo+1,prices,n,k),0+f(ind+1,tranNo,prices,n,k));
    }
    return max(prices[ind]+f(ind+1,tranNo+1,prices,n,k),0+f(ind+1,tranNo,prices,n,k));
}
int maximumProfit(vector<int> &prices,int n,int k)
{
    return f(0,0,prices,n,k);
}

//Memoization code
int f(int ind,int tranNo,vector<int> &prices,int n,int k,vector<vector<int>> &dp)
{
    if(ind==n||tranNo==2*k)
    {
        return 0;
    }
    if(dp[ind][tranNo]!=-1)
    {
        return dp[ind][tranNo];
    }
    if(tranNo%2==0)
    {
        return max(-prices[ind]+f(ind+1,tranNo+1,prices,n,k,dp),0+f(ind+1,tranNo,prices,n,k,dp));
    }
    return max(prices[ind]+f(ind+1,tranNo+1,prices,n,k,dp),0+f(ind+1,tranNo,prices,n,k,dp));
}
int maximumProfit(vector<int> &prices,int n,int k)
{
    vector<vector<int>> dp(n,vector<int>(2*k,-1));
    return f(0,0,prices,n,k,dp);
}

//Tabulation
int maximumProfit(vector<int> &prices,int n,int k)
{
    vector<vector<int>> dp(n+1,vector<int>(2*k+1,-1));
    for(int ind=n-1;ind>=0;ind--)
    {
        for(int tranNo=2*k-1;tranNo>=0;tranNo--)
        {
            if(tranNo%2==0)
            {
                dp[ind][tranNo]=max(-prices[ind]+dp[ind+1][tranNo+1],0+dp[ind+1][tranNo]);
            }
            else{
            dp[ind][tranNo]=max(prices[ind]+dp[ind+1][tranNo+1],0+dp[ind+1][tranNo]); 
            }
        }
    }
    return dp[0][0];
}

//Space optimization
int maximumProfit(vector<int> &prices,int n,int k)
{
    vector<int> after(2*k+1,0);
    vector<int> curr(2*k+1,0);
    for(int ind=n-1;ind>=0;ind--)
    {
        for(int tranNo=2*k-1;tranNo>=0;tranNo--)
        {
            if(tranNo%2==0)
            {
                curr[tranNo]=max(-prices[ind]+after[tranNo+1],0+after[tranNo]);
            }
            else{
            curr[tranNo]=max(prices[ind]+after[tranNo+1],0+after[tranNo]); 
            }
        }
        after=curr;
    }
    return after[0];
}
//Time complexity is O(N*K)