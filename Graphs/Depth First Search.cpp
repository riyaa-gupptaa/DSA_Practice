#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
void dfs(int node,vector<vector<int>> &adj,vector<int> &vis,vector<int> &ls)
{
    vis[node]=1;
    ls.push_back(node);
    //traverse all its neighbours
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            dfs(it,adj,vis,ls);
        }
    }
}
vector<int> dfs(vector<vector<int>>& adj) 
{
    int n=adj.size();
    vector<int> vis(n,0);
    int start=0;
    vector<int> ls;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i, adj, vis, ls); // In case graph is disconnected
        }
    }

    return ls;
}
//SC->O(N)+O(N)+O(N)~O(N)
//TC->O(N)+(2*E)