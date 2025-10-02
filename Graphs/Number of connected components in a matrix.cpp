#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
void bfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>> &grid)
{
    vis[row][col]=1;
    queue<pair<int,int>> q;
    q.push({row,col});
    int n=grid.size();
    int m=grid[0].size();
    while(!q.empty())
    {
        int row=q.front().first;
        int col=q.front().second;
        q.pop();
        //Traverse in the neighbours and mark them 1
        for(int delRow=-1;delRow<=1;delRow++)
        {
            for(int delCol=-1;delCol<=1;delCol++)
            {
                int nrow=row+delRow;
                int ncol=col+delCol;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && !vis[nrow][ncol])
                {
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
}
int numIslands(vector<vector<char>> &grid)
{
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> vis(n,vector<int>(m,0));
    int cnt=0;
    for(int row=0;row<n;row++)
    {
        for(int col=0;col<m;col++)
        {
            if(!vis[row][col] && grid[row][col]=='1')
            {
                cnt++;
                bfs(row,col,vis,grid);
            }
        }
    }
    return cnt;
}
//Space Complexity is O(N*N)+O(N*N)
//Time complexity is O(N*n)