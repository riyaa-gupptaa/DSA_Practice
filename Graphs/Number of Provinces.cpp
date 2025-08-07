#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
void dfs(int node,vector<vector<int>>& adj,vector<int> &vis)
{
    vis[node]=1;
    for(auto it: adj[node])
    {
        if(!vis[it])
        {
            dfs(it,adj,vis);
        }
    }
}
int findCircleNum(vector<vector<int>>& isConnected)
{
    int n=isConnected.size();
    vector<vector<int>> adj(n);
    //to change adjacency matrix to list
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(isConnected[i][j]==1 && i!=j)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    vector<int> vis(n,0);
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            cnt++;
            dfs(i,adj,vis);
        }
    }
    return cnt;
}
//Space complexity is O(N)+O(N)
//Time complexity is O(N)+O(V+2E)