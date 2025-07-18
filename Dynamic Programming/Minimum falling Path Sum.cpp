#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
using namespace std;
//Base case is destination or out of bound cases
int f(int i,int j,vector<vector<int>> &matrix,vector<vector<int>> &dp)
{
    int n=matrix.size();
    int m=matrix[0].size();
    if(j<0 || j>=m)
    {
        return 0;
    }
    if(i==0)
    {
        return matrix[0][j];
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int straight=matrix[i][j]+f(i-1,j,matrix,dp);
    int left=matrix[i][j]+f(i-1,j-1,matrix,dp);
    int rd=matrix[i][j]+f(i-1,j+1,matrix,dp);
    return dp[i][j]=min(straight, min(left, rd));
}
int minFallingPathSum(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    int result=INT_MAX;
    for(int j=0;j<m;j++)
    {
        result=min(result,f(n-1,j,matrix,dp));
    }
    return result;
}
//Time complexity is O(N*M)
//Space complexity is O(N*M)+O(N)


//Time complexity is O(3^n)~exponential for recursion
//Space complexity is O(N)

//Tabulation
int minFallingPathSum(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();
    vector<vector<int>> dp(n,vector<int>(m,0));
    for(int j=0;j<m;j++)
    {
        dp[0][j]=matrix[0][j];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int straight=dp[i-1][j];
            int left=(j>0)?dp[i-1][j-1]:1e9;
            int rd=(j<m-1)?dp[i-1][j+1]:1e9;
            dp[i][j]=matrix[i][j]+min(straight,min(left,rd));
        }
    }
    int result=INT_MIN;
    for(int j=0;j<m;j++)
    {
        result=min(result,dp[n-1][j]);
    }
    return result;
}

//Space Optimization
int maxFallingPathSum(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    vector<int> prev(matrix[n-1]);
    for(int i=n-2;i>=0;--i)
    {
        vector<int> curr(n,0);
        for(int j=0;j<n;++j)
        {
            int down=prev[j];
            int ld=(j>0)?prev[j-1]:INT_MAX;
            int rd=(j<n-1)?prev[j+1]:INT_MAX;
            curr[j] = matrix[i][j] + min(down, min(ld,rd));
        }
        prev = curr;
    }
    return *min_element(prev.begin(), prev.end());
}