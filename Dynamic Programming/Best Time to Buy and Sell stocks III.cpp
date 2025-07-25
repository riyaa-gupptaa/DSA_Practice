#include<iostream>
#include<vector>
#include<map>
using namespace std;
//Maximum of 2 transactions are allowed
int f(int ind,int buy,int cap,vector<int> &prices,int n)
{
    if(ind==n||cap==0)
    {
        return 0;
    }
    if(buy==1)
    {
        return max(-prices[ind]+f(ind+1,0,cap,prices,n),0+f(ind+1,1,cap,prices,n));
    }
    else{
        return max(-prices[ind]+f(ind+1,1,cap-1,prices,n),0+f(ind+1,0,cap,prices,n));
    }
}
int maxProfit(vector<int> &prices,int n)
{
    return f(0,1,2,prices,n);
}

//Using dynamic programming
int f(int ind,int buy,int cap,vector<int> &prices,int n,vector<vector<vector<int>>> &dp)
{
    if(ind==n||cap==0)
    {
        return 0;
    }
    if(dp[ind][buy][cap]!=-1)
    {
        return dp[ind][buy][cap];
    }
    if(buy==1)
    {
        return dp[ind][buy][cap]=max(-prices[ind]+f(ind+1,0,cap,prices,n,dp),0+f(ind+1,1,cap,prices,n,dp));
    }
    else{
        return dp[ind][buy][cap]=max(prices[ind]+f(ind+1,0,cap-1,prices,n,dp),0+f(ind+1,1,cap,prices,n,dp));
    }
}
int maxProfit(vector<int> &prices,int n)
{
    vector<vector<vector<int>>> dp(n,vector<vector<int>> (2,vector<int> (3,-1)));
    return f(0,1,2,prices,n,dp);
}

//It won't be accepted because we are still having auxiliary stack space

//Tabulation [Bottom to top recursion]
int maxProfit(vector<int> &prices,int n)
{
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2,vector<int> (3,0)));
    for(int ind=n-1;ind>=0;ind--)
    {
        for(int buy=0;buy<=1;buy++)
        {
            for(int cap=1;cap<=2;cap++)
            {
                //For every cap 0, the value is 0
                if(buy==1)
                {
                    dp[ind][buy][cap]=max(-prices[ind]+dp[ind+1][0][cap],0+dp[ind+1][1][cap]);
                }
                else{
                    dp[ind][buy][cap]=max(prices[ind]+dp[ind+1][1][cap-1],0+dp[ind+1][0][cap]);
                } 
            }
        }
    }
    return dp[0][1][2];
}

//Space Optimization n*2*3
int maxProfit(vector<int> &prices,int n)
{
    vector<vector<int>> after(2,vector<int> (3,0));
    vector<vector<int>> curr(2,vector<int> (3,0));
    for(int ind=n-1;ind>=0;ind--)
    {
        for(int buy=0;buy<=1;buy++)
        {
            for(int cap=1;cap<=2;cap++)
            {
                //For every cap 0, the value is 0
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
    return after[1][2];
}
//Time complexity is O(N*2*3)
//Space complexity is constant as of now