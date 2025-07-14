#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
using namespace std;
//Count the total number of ways
//Minimum or maximum output
//Try all possible ways
//All these statements signify to use DP
//Try to represent the problems in terms of index
//Do all possible stuufs on that index according to the problem statement
//Sum of all stuffs-Count all ways
//min(of all stuffs)=find minimum
//max(of all stuffs)=find maximum
int climbStairs(int n)
{
    int result=0;
    if(n<=1)
    {
        return 1;
    }
    vector<int> dp(n+1);
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}