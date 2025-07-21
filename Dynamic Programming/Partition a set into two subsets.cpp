#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include<algorithm>
#include<numeric>
using namespace std;
//Subset Sum-> Tabulation-If we check for a target==k
//We can derive if every possible target between 1 and k is possible or not
int minimumDifference(vector<int>& nums)
{
    int n=nums.size();
    int mini=1e9;
    int totSum = accumulate(nums.begin(), nums.end(), 0);
    vector<vector<bool>> dp(n, vector<bool>(totSum + 1, false));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    if (nums[0] <= totSum)
        dp[0][nums[0]] = true;
    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= totSum; target++)
        {
            bool nottake = dp[ind-1][target];
            bool take = false;
            if (target >= nums[ind])
            {
                take = dp[ind-1][target-nums[ind]];
            }
            dp[ind][target] = take || nottake;
        }
    }
    //dp[n-1][col->0----totSum]
    for(int s1=0;s1<=totSum/2;s1++)
    {
        if(dp[n-1][s1]==true)
        {
            mini=min(mini,abs(totSum-s1)-s1);
        }
    }
    return mini;
}