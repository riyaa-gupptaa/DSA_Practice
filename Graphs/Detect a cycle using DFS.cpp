#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
bool dfs(int node,int parent,vector<int> &vis,vector<vector<int>> &edges)
{
    vis[node]=1;
    for(auto adjacentNode:edges[node])
    {
        if(!vis[adjacentNode])
        {
            if(dfs(adjacentNode,node,vis,edges)==true) return true;
            return true;
        }
        else if(adjacentNode!=parent)
        {
            return true;
        }
    }
    return false;
}
bool isCycle(int V, vector<vector<int>>& edges)
{
    vector<int> vis(V,0);
    return dfs(1,-1,vis,edges);
}
//SC-O(N)
//TC-O(N+2*E)+O(N)