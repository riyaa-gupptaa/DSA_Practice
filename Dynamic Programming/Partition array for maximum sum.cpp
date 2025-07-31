#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
int f(int ind, vector<int> &arr, int k)
{
    int n = arr.size();
    if (ind == n)
    {
        return 0;
    }
    int len = 0;
    int maxi = INT_MIN;
    int maxAns = INT_MIN;
    for (int j = ind; j < min(ind + k, n); j++)
    {
        len++;
        maxi = max(maxi, arr[j]);
        int sum = len * maxi + f(j + 1, arr, k);
        maxAns = max(maxAns, sum);
    }
    return maxAns;
}
int maxSumAfterPartitioning(vector<int> &arr, int k)
{
    int n = arr.size();
    return f(0, arr, k);
}
// Time complexity is O(N)*O(K)
// Space complexity is O(N)+O(N)

// Memoization
int f(int ind, vector<int> &arr, int k, vector<int> &dp)
{
    int n = arr.size();
    if (ind == n)
    {
        return 0;
    }
    if (dp[ind] != -1)
    {
        return dp[ind];
    }
    int len = 0;
    int maxi = INT_MIN;
    int maxAns = INT_MIN;
    for (int j = ind; j < min(ind + k, n); j++)
    {
        len++;
        maxi = max(maxi, arr[j]);
        int sum = len * maxi + f(j + 1, arr, k, dp);
        maxAns = max(maxAns, sum);
    }
    return dp[ind] = maxAns;
}
int maxSumAfterPartitioning(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> dp(n, -1);
    return f(0, arr, k, dp);
}

// Tabulation
int maxSumAfterPartitioning(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> dp(n + 1, 0); // dp[i] = max sum for subarray starting at i

    for (int i = n - 1; i >= 0; i--)
    {
        int maxInPartition = 0;
        int maxSum = 0;
        for (int j = i; j < min(n, i + k); j++)
        {
            maxInPartition = max(maxInPartition, arr[j]);
            int partitionSize = j - i + 1;
            maxSum = max(maxSum, maxInPartition * partitionSize + dp[j + 1]);
        }
        dp[i] = maxSum;
    }

    return dp[0];
}

