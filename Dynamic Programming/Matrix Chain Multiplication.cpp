#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
// MCM-Matrix Chain Multiplicaton
// Start with entire block/array f(i,j)
// Try all partitions(Run a loop to try all partitions)
// Return the best possible 2 partitions
int f(int i, int j, vector<int> &arr)
{
    if (i == j)
    {
        return 0;
    }
    int mini = 1e9;
    for (int k = i; k < j ; k++)
    {
        int steps = (arr[i - 1] * arr[k] * arr[j]) + f(i, k, arr) + f(k + 1, j, arr);
        mini = min(mini, steps);
    }
    return mini;
}
int matrixMultiplication(vector<int> &arr)
{
    int n=arr.size();
    return f(1,n-1,arr);
}
//Time complexity is Exponential

//Memoization
int f(int i,int j,vector<int> &arr,vector<vector<int>> &dp)
{
    if(i==j)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int mini=1e9;
    for(int k=i;k<j;k++)
    {
        int steps=arr[i-1]*arr[k]*arr[j]+f(i,k,arr,dp)+f(k+1,j,arr,dp);
        if(steps<mini)
        {
            mini=steps;
        }
    }
    return dp[i][j]=mini;
}
int matrixMultiplication(vector<int> &arr)
{
    int n=arr.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    return f(1,n-1,arr,dp);
}