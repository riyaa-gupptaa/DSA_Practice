#include<iostream>
#include<vector>
#include<map>
using namespace std;
//Multiple transactions are allowed
//Before buying the next stock, you should sell the previous stock you bought
//This uses a recursive approach
long f(int ind,int buy,vector<long> &values,int n)
{
    if(ind==n)
    {
        return 0;
    }
    long profit=0;
    if(buy)
    {
        profit=max(-values[ind]+f(ind+1,0,values,n),0+f(ind+1,1,values,n));
    }
    else{
        profit=max(values[ind]+f(ind+1,1,values,n),0+f(ind+1,0,values,n));
    }
    return profit;
}
int main()
{
    vector<long> values={7,1,5,3,6,4};
    int n=values.size();
    int profit=f(0,1,values,n);
    cout<<profit<<endl;
}

//We can further optimise the solution using dynamic programming
long f(int ind,int buy,long *values,int n,vector<vector<int>> &dp)
{
    if(ind==n)
    {
        return 0;
    }
    if(dp[ind][buy]!=-1)
    {
        return dp[ind][buy];
    }
    long profit=0;
    if(buy)
    {
        profit=max(-values[ind]+f(ind+1,0,values,n,dp),0+f(ind+1,1,values,n,dp));
    }
    else{
        profit=max(values[ind]+f(ind+1,1,values,n,dp),0+f(ind+1,0,values,n,dp));
    }
    return dp[ind][buy]=profit;
}
long getMaximumProfit(long *values,int n)
{
    vector<vector<int>> dp(n,vector<int>(2,-1));
    return f(0,1,values,n,dp);
}

//Tabulation method

long getMaximumProfit(long *values,int n)
{
    vector<vector<long>> dp(n+1,vector<long>(2,0));
    dp[n][0]=dp[n][1]=0;
    for(int ind=n-1;ind>=0;ind--)
    {
        for(int buy=0;buy<=1;buy++)
        {
            long profit=0;
            if(buy)
            {
                profit=max(-values[ind]+dp[ind+1][0],0+dp[ind+1][1]);
            }
            else{
                profit=max(values[ind]+dp[ind+1][1],0+dp[ind+1][0]);
            }
            dp[ind][buy]=profit; 
        }
    }
    return dp[0][1];
}

//One more method 
long getMaximumProfit(long *values,int n)
{
    vector<long> ahead(2,0), curr(2,0);
    ahead[0]=ahead[1]=0;
    for(int ind=n-1;ind>=0;ind--)
    {
        for(int buy=0;buy<=1;buy++)
        {
            long profit=0;
            if(buy)
            {
                profit=max(-values[ind]+ahead[0],0+ahead[1]);
            }
            else{
                profit=max(values[ind]+ahead[1],0+ahead[0]);
            }
            curr[buy]=profit;
        }
        ahead=curr;
    }
    return ahead[1];
}

//One more way
long getMaximumProfit(long *values,int n)
{
    long aheadNotBuy,aheadBuy,currBuy,currNotBuy;
    aheadNotBuy=aheadBuy=0;
    for(int ind=n-1;ind>=0;ind--)
    {
        for(int buy=0;buy<=1;buy++)
        {
            currBuy=max(-values[ind]+aheadNotBuy,0+aheadBuy);
            currNotBuy=max(values[ind]+aheadBuy,0+aheadNotBuy);
        }
        aheadBuy=currBuy;
        aheadNotBuy=currNotBuy;
    }
    return aheadBuy;
}