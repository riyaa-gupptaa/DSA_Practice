#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
using namespace std;
int f(int ind,vector<int> &nums)
{
    if(ind==0)
    {
        return nums[0];
    }
    if(ind<0)
    {
        return 0;
    }
    int pick=nums[ind]+f(ind-2,nums);
    int npick=0+f(ind-1,nums);
    return max(pick,npick);
}
int rob(vector<int> &nums)
{
    int n=nums.size();
    return f(n-1,nums);
}

//Memoization
int f(int ind,vector<int> &nums,vector<int> &dp)
{
    if(ind==0)
    {
        return nums[0];
    }
    if(ind<0)
    {
        return 0;
    }
    if(dp[ind]!=-1)
    {
        return dp[ind];
    }
    int pick=nums[ind]+f(ind-2,nums,dp);
    int npick=0+f(ind-1,nums,dp);
    return dp[ind]=max(pick,npick);
}
int rob(vector<int> &nums)
{
    int n=nums.size();
    vector<int> dp(n,-1);
    return f(n-1,nums,dp);
}
//Time complexity is O(N)
//Space complexity is O(N)+O(N)

//Tabulation
int rob(vector<int> &nums)
{
    int n=nums.size();
    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return nums[0];
    }
    vector<int> dp(n,0);
    dp[0]=nums[0];
    dp[1]=max(nums[0],nums[1]);
    for(int i=2;i<n;i++)
    {
        dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
    }
    return dp[n-1];
}
//Space optimization
int rob(vector<int> &nums)
{
    int prev=nums[0];
    int prev2=0;
    for(int i=1;i<nums.size();i++)
    {
        int take=nums[i];
        if(i>1)
        {
            take+=prev2;
        }
        int ntake=0+prev;
        int curi=max(take,ntake);
        prev2=prev;
        prev=curi;
    }
    return prev;
}
//Time complexity is O(N)
//Space complexity is O(1)