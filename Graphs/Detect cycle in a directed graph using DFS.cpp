#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
//On the same paths, node has to be viited again
bool dfsCheck(int node,vector<vector<int>>& grid,vector<int>&vis,vector<int>&pathVis)
{
    vis[node]=1;
    pathVis[node]=1;
    for(auto it:grid[node])
    {
        if(!vis[it])
        {
            if(dfsCheck(it,grid,vis,pathVis)==true)
            {
                return true;
            }
        }
        else if(pathVis[it])
        {
            return true;
        }
    }
    pathVis[node]=0;
    return false;
}
bool containsCycle(vector<vector<int>>& grid)
{
    int V=grid.size();
    vector<int> vis(V,0);
    vector<int> pathVis(V,0);
    for(int i=0;i<V;i++)
    {
        if(!vis[i])
        {
            if(dfsCheck(i,grid,vis,pathVis)==true)
            {
                return true;
            }
        }
    }
    return false;
}