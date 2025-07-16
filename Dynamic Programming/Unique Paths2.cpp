#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
using namespace std;
// We cannot go by dead Cell
int f(int i, int j, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp)
{
    if (i >= 0 && j >= 0 && obstacleGrid[i][j] == 1)
    {
        return 0;
    }
    if (i == 0 && j == 0)
    {
        return 1;
    }
    if (i < 0 || j < 0)
    {
        return 0;
    }
    if (dp[i][j] != -1)
        return dp[i][j];

    int up = f(i - 1, j, obstacleGrid, dp);
    int left = f(i, j - 1, obstacleGrid, dp);
    return dp[i][j] = up + left;
}
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f(n - 1, m - 1, obstacleGrid, dp);
}

// Tabulation
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (obstacleGrid[i][j] == 1)
            {
                dp[i][j] = 0;
            }
            else if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                int up = (i > 0) ? dp[i - 1][j] : 0;
                int left = (j > 0) ? dp[i][j - 1] : 0;
                dp[i][j] = up + left;
            }
        }
    }
    return dp[n - 1][m - 1];
}

//Space Optimization
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int mod=(int)(1e9+7);
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();
    vector<int> prev(m,0);
    for(int i=0;i<n;i++)
    {
        vector<int> cur(m,0);
        for(int j=0;j<m;j++)
        {
            if(obstacleGrid[i][j]==-1)
            {
                cur[j]=0;
            }
            else if(i==0 && j==0)
            {
                cur[j]=1;
            }
            else{
                int up=0,left=0;
                if(i>0)
                {
                    up=prev[j];
                }
                if(j>0)
                {
                    left=cur[j-1];
                }
                cur[j]=(up+left)%mod;
            }
        }
        prev=cur;
    }
    return prev[m-1];
}