#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
using namespace std;
// All paths by alice+all paths by bob(Recursion for both cases)
// Explore everything m times (i1,j1) & (i2,j2)
// Explore all the paths
// Give the maximum sum path
// We have a fixed starting point and a variable ending point
int f(int i, int j1, int j2, vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    if (j1 < 0 || j1 >= m || j2 < 0 || j2 > m)
    {
        return -1e8;
    }
    if (i == n - 1)
    {
        if (j1 == j2)
        {
            return grid[i][j1];
        }
        else
        {
            return grid[i][j1] + grid[i][j2];
        }
    }
    // Exploring all paths
    int maxi = 0;
    for (int dj1 = -1; dj1 <= 1; dj1++)
    {
        for (int dj2 = -1; dj2 <= 1; dj2++)
        {
            if (j1 == j2)
            {
                maxi = max(maxi, grid[i][j1] + f(i + 1, j1 + dj1, j2 + dj2, grid));
            }
            else
            {
                maxi = max(maxi, grid[i][j1] + grid[i][j2] + f(i + 1, j1 + dj1, j2 + dj2, grid));
            }
        }
    }
    return maxi;
}
int cherryPickup(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    return f(0, 0, m - 1, grid);
}
// Time complexity is O(3^n*3^n)~Exponential
// Space complexity is O(n)

int f(int i, int j1, int j2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{
    int n = grid.size();
    int m = grid[0].size();
    if (j1 < 0 || j1 >= m || j2 < 0 || j2 > m)
    {
        return -1e8;
    }
    if (i == n - 1)
    {
        if (j1 == j2)
        {
            return grid[i][j1];
        }
        else
        {
            return grid[i][j1] + grid[i][j2];
        }
    }
    if (dp[i][j1][j2] != -1)
    {
        return dp[i][j1][j2];
    }
    // Exploring all paths
    int maxi = -1e8;
    for (int dj1 = -1; dj1 <= 1; dj1++)
    {
        for (int dj2 = -1; dj2 <= 1; dj2++)
        {
            if (j1 == j2)
            {
                maxi = max(maxi, grid[i][j1] + f(i + 1, j1 + dj1, j2 + dj2, grid));
            }
            else
            {
                maxi = max(maxi, grid[i][j1] + grid[i][j2] + f(i + 1, j1 + dj1, j2 + dj2, grid));
            }
        }
    }
    return dp[i][j1][j2] = maxi;
}
int cherryPickup(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    return f(0, 0, m - 1, grid, dp);
}

// Tabulation
int cherryPickup(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));
    for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            if (j1 == j2)
            {
                dp[n - 1][j1][j2] = grid[n - 1][j1];
            }
            else
            {
                dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n-1][j2];
            }
        }
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                int maxi = -1e8;
                for (int dj1 = -1; dj1 <= 1; dj1++)
                {
                    for (int dj2 = -1; dj2 <= 1; dj2++)
                    {
                        int value=0;
                        if (j1 == j2)
                        {
                           value=grid[i][j1];
                        }
                        else
                        {
                           value=grid[i][j1] + grid[i][j2];
                        }
                        if(j1+dj1>=0 && j1+dj1<m && j2+dj2>=0 && j2+dj2<m)
                        {
                            value+=dp[i+1][j1+dj1][j2+dj2];
                        }
                        else{
                            value+=-1e8;
                        }
                        maxi=max(maxi,value);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][m-1];
}

//Space Optimization
int cherryPickup(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> front(m, vector<int>(m, 0)), curr(m, vector<int>(m, 0));

    // Base case: last row
    for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            if (grid[n - 1][j1] == -1 || grid[n - 1][j2] == -1)
                front[j1][j2] = -1e8;
            else if (j1 == j2)
                front[j1][j2] = grid[n - 1][j1];
            else
                front[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                int maxi = -1e8;

                for (int dj1 = -1; dj1 <= 1; dj1++)
                {
                    for (int dj2 = -1; dj2 <= 1; dj2++)
                    {
                        int nj1 = j1 + dj1;
                        int nj2 = j2 + dj2;

                        if (nj1 >= 0 && nj1 < m && nj2 >= 0 && nj2 < m &&
                            grid[i][j1] != -1 && grid[i][j2] != -1)
                        {
                            int value = (j1 == j2) ? grid[i][j1] : (grid[i][j1] + grid[i][j2]);
                            value += front[nj1][nj2];
                            maxi = max(maxi, value);
                        }
                    }
                }
                curr[j1][j2] = maxi;
            }
        }
        front = curr;
    }

    return max(0, front[0][m - 1]); // return 0 if no valid path
}
