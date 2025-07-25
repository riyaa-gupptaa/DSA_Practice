#include<iostream>
#include<vector>
#include<map>
using namespace std;
//Cannot buy right after selling
int f(int ind,int buy,vector<int> &prices,int n)
{
    if(ind>=n)//To avoid outofbound conditions
    {
        return 0;
    }
    if(buy==1)
    {
        return max(-prices[ind]+f(ind+1,0,prices,n),0+f(ind+1,1,prices,n));
    }
    return max(prices[ind]+f(ind+2,1,prices,n),0+f(ind+1,0,prices,n));
}
int maxProfit(vector<int> &prices)
{
    int n=prices.size();
    return f(0,1,prices,n);
}

//Dynamic Programming
int f(int ind,int buy,vector<int> &prices,int n,vector<vector<int>> &dp)
{
    if(ind>=n)//To avoid outofbound conditions
    {
        return 0;
    }
    if(dp[ind][buy]!=-1)
    {
        return dp[ind][buy];
    }
    if(buy==1)
    {
       return dp[ind][buy]=max(-prices[ind]+f(ind+1,0,prices,n,dp),0+f(ind+1,1,prices,n,dp));
    }
  return  dp[ind][buy]=max(prices[ind]+f(ind+2,1,prices,n,dp),0+f(ind+1,0,prices,n,dp));
}
int maxProfit(vector<int> &prices)
{
    int n=prices.size();
    vector<vector<int>> dp(n,vector<int>(2,-1));
    return f(0,1,prices,n,dp);
}

//Tabulation
int maxProfit(vector<int> &prices)
{
    int n=prices.size();
    vector<vector<int>> dp(n+2,vector<int>(2,0));
    for(int ind=n-1;ind>=0;ind--)
    {
        for(int buy=0;buy<=1;buy++)
        {
            if(buy==1)
            {
                dp[ind][buy]=max(-prices[ind]+dp[ind+1][0],0+dp[ind+1][1]);
            }
            else{
                dp[ind][buy]=max(prices[ind]+dp[ind+2][1],0+dp[ind+1][0]);
            }
        }
    }
    return dp[0][1];
}

//Space optimization
//We won't write the space optimization code because hypothetically we need 3 rows
//But we can optimise the time
int maxProfit(vector<int> &prices)
{
    int n=prices.size();
    vector<vector<int>> dp(n+2,vector<int>(2,0));
    for(int ind=n-1;ind>=0;ind--)
    {
        dp[ind][1]=max(-prices[ind]+dp[ind+1][0],0+dp[ind+1][1]);
        dp[ind][0]=max(prices[ind]+dp[ind+2][1],0+dp[ind+1][0]);
    }
    return dp[0][1];
}

//If we want to perform a space optimisation method
int maxProfit(vector<int> &prices)
{
    int n=prices.size();
    vector<int> front2(2,0);
    vector<int> front1(2,0);
    vector<int> curr(2,0);
    for(int ind=n-1;ind>=0;ind--)
    {
        curr[1]=max(-prices[ind]+front1[0],0+front1[1]);
        curr[0]=max(prices[ind]+front2[1],0+front2[0]);
        front2=front1;
        front1=curr;
    }
    return curr[1];
}
//Time complexity is O(N)
//Space complexity is O(6)