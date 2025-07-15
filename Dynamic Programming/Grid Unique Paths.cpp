#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
using namespace std;
// All possible ways-Recursion
int f(int i, int j) // No. of ways for (0,0)->(i,j)
{
    if (i == 0 && j == 0)
    {
        return 1;
    }
    if (i < 0 || j < 0)
    {
        return 0;
    }
    int up = f(i - 1, j);
    int left = f(i, j - 1);
    return up + left;
}
int uniquePaths(int m, int n)
{
    return f(m - 1, n - 1);
}
// Time complexity is O(2^m*n)
// Space complexity is O(path length)

// Using memoization
int f(int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
    {
        return 1;
    }
    if (i < 0 || j < 0)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int up = f(i - 1, j, dp);
    int left = f(i, j - 1, dp);
    return dp[i][j] = up + left;
}
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    return f(m - 1, n - 1, dp);
}
// Time complexity is O(N*M)
// Space complexity is O((N-1)+(M-1))(Recursive Stack Space)+O(N*M)

// Using tabulation
// Declare base cases
// Express all states in for loop
// Copy the recurrence and write
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // Set base case: only 1 way to reach any cell in first row or first column
    for (int i = 0; i < m; i++)
        dp[i][0] = 1;
    for (int j = 0; j < n; j++)
        dp[0][j] = 1;

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[m - 1][n - 1];
}

//Space Optimizations
//Won't work for all cases
int uniquePaths(int m,int n)
{
    vector<int> prev(n,0);
    for(int i=0;i<m;i++)
    {
        vector<int> curr(n,0);
        for(int j=0;j<n;j++)
        {
            if(i==0 && j==0)
            {
                curr[j]=1;
            }
            else{
                int up=0;
                int left=0;
                if(i>0)
                {
                    up=prev[j];
                }
                if(j>0)
                {
                    left=curr[j-1];
                }
                curr[j]=up+left;
            }
        }
        prev=curr;
    }
    return prev[n-1];
}