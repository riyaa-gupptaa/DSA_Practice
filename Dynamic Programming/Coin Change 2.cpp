#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
int f(int ind, int amount, vector<int> &coins)
{
    if(ind==0)
    {
        return (amount%coins[0]==0);
    }
    int notTake = f(ind - 1, amount, coins);
    int take = 0;
    if (coins[ind] <= amount)
    {
        take = f(ind, amount - coins[ind],coins);
    }
    return notTake+take;
}
int change(int amount, vector<int> &coins)
{
    int n=coins.size();
    return f(n-1,amount,coins);
}
//Time complexity is Exponential
//Space complexity O(target)->Worst case

//Memoization
int f(int ind,int amount,vector<int> &coins,vector<vector<int>> &dp)
{
    int n=coins.size();
    if(ind==0)
    {
        return (amount%coins[0]==0);
    }
    if(dp[ind][amount]!=-1)
    {
        return dp[ind][amount];
    }
    int notTake=f(ind-1,amount,coins,dp);
    int take=0;
    if(coins[ind]<=amount)
    {
        take=f(ind,amount-coins[ind],coins,dp);
    }
    return dp[ind][amount]=take+notTake;
}
int change(int amount,vector<int> &coins)
{
    int n=coins.size();
    vector<vector<int>> dp(n,vector<int>(amount+1,-1));
    return f(n-1,amount,coins,dp);
}
//Time complexity is O(N*target)
//Space complexity is O(N*target)+O(target)

//Tabulation
int change(int amount,vector<int> &coins)
{
    int n=coins.size();
    vector<vector<int>> dp(n,vector<int>(amount+1,0));
    for(int t=0;t<=amount;t++)
    {
        dp[0][t]=(t%coins[0]==0);
    }
    for(int ind=1;ind<n;ind++)
    {
        for(int t=0;t<=amount;t++)
        {
            long long notTake=dp[ind-1][t];
            long long take=0;
            if(coins[ind]<=t)
            {
                take=dp[ind][t-coins[ind]];
            }
            dp[ind][t]=take+notTake;
        }
    }
    return dp[n-1][amount];
}

//Space Optimised
int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<int> prev(amount + 1, 0), curr(amount + 1, 0);

    // Base Case
    for (int t = 0; t <= amount; t++) {
        prev[t] = (t % coins[0] == 0);
    }

    for (int ind = 1; ind < n; ind++) {
        for (int t = 0; t <= amount; t++) {
            int notTake = prev[t];
            int take = 0;
            if (coins[ind] <= t) {
                take = curr[t - coins[ind]];
            }
            curr[t] = take + notTake;
        }
        prev = curr;
    }

    return prev[amount];
}