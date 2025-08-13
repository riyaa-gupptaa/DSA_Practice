#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
bool dfsCheck(int node, vector<vector<int>> &grid, vector<int> &vis, vector<int> &pathVis,vector<int> &check)
{
    vis[node] = 1;
    pathVis[node] = 1;
    check[node]=0;
    for (auto it : grid[node])
    {
        if (!vis[it])
        {
            if (dfsCheck(it, grid, vis, pathVis,check) == true)
            {
                check[node]=0;
                return true;
            }
        }
        else if (pathVis[it])
        {
            check[node]=0;
            return true;
        }
    }
    check[node]=1;
    pathVis[node] = 0;
    return false;
}
vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    int V = graph.size();
    vector<int> vis(V, 0);
    vector<int> pathVis(V, 0);
    vector<int> check(V,0);
    vector<int> safeNodes;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfsCheck(i, graph, vis, pathVis,check);
        }
    }
    for(int i=0;i<V;i++)
    {
        if(check[i]==1)
        {
            safeNodes.push_back(i);
        }
    }
    return safeNodes;
}