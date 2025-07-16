#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
using namespace std;
int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
    {
        return grid[0][0];
    }
    if (i < 0 || j < 0)
    {
        return INT_MAX;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = grid[i][j] + f(i - 1, j, grid,dp);
    int left = grid[i][j] + f(i, j - 1, grid,dp);
    return dp[i][j]=grid[i][j]+min(up, left);
}
int minPathSum(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f(n - 1, m - 1, grid, dp);
}

//Tabulation
int minPathSum(vector<vector<int>> &grid)
{
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> dp(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==0 && j==0)
            {
                dp[i][j]=grid[0][0];
            }
            else{
                int up = INT_MAX, left = INT_MAX;
                if(i>0)
                {
                up=grid[i][j]+dp[i-1][j];
                }
                if(j>0)
                {
                left=grid[i][j]+dp[i][j-1];
                }
                dp[i][j]=min(up,left);
            }
        }
    }
    return dp[n-1][m-1];
}

//Space Optimisation
int minPathSum(vector<vector<int>> &grid)
{
    int n=grid.size();
    int m=grid[0].size();
    vector<int> prev(m,0);
    for(int i=0;i<n;i++)
    {
        vector<int> cur(m,0);
        for(int j=0;j<m;j++)
        {
            if(i==0 && j==0)
            {
                cur[j]=grid[i][j];
            }
            else{
                int up=grid[i][j];
                if(i>0)
                {
                    up+=prev[j];
                }
                int left=grid[i][j];
                if(j>0)
                {
                    left+=cur[j-1];
                }
                cur[j]=min(up,left);
            }
        }
        prev=cur;
    }
    return prev[m-1];
}