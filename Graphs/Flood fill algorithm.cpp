#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
//.             (row-1,col)
//.                 |
//(row,col-1)<--(row,col)---->(row,col+1)
//                  |
//               (row+1,col)
// row={-1,0,+1,0}
// col={+0,+1,+0,-1}
void dfs(int row,int col,vector<vector<int>> &ans,vector<vector<int>>&image,int newColor,vector<int> &delRow,vector<int> &delcol,int iniColor)
{
    ans[row][col]=newColor;
    int n=image.size();
    int m=image[0].size();
    for(int i=0;i<4;i++)
    {
        int nrow=row+delRow[i];
        int ncol=col+delcol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==iniColor && ans[nrow][ncol]!=newColor)
        {
            dfs(nrow,ncol,ans,image,newColor,delRow,delcol,iniColor);
        }
    }
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
{
    int iniColor=image[sr][sc];
    vector<vector<int>> ans=image;
    vector<int> delRow={-1,0,+1,0};
    vector<int> delcol={0,+1,0,-1};
    dfs(sr,sc,ans,image,color,delRow,delcol,iniColor);
    return ans;
}
//Time Complexity is O(N*M)
//Space Complexity is O(N*M)