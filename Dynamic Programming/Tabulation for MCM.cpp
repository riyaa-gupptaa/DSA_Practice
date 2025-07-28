#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
//Copy the base case
//Write down changing conditions

int matrixMultiplication(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 2; len < n; len++) // length of chain
    {
        for (int i = 1; i <= n - len; i++)
        {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int cost = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[1][n - 1];
}
//Time complexity is O(N*N*N)
//Space complexity is O(N*N)