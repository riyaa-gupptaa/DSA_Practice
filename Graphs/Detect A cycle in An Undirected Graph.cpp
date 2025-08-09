#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
bool detect(int src,vector<vector<int>> &edges,vector<int> &vis)
{
    vis[src]=1;
    queue<pair<int,int>> q;
    q.push({src,-1});
    while(!q.empty())
    {
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();
        for(auto adjacentNode:edges[node])
        {
            if(!vis[adjacentNode])
            {
                vis[adjacentNode]=1;
                q.push({adjacentNode,node});
            }
            else if(parent!=adjacentNode){
                return true;
            }
        }
    }
    return false;
}
bool isCycle(int V, vector<vector<int>>& edges)
{
    vector<int> vis(V,0);
    for(int i=0;i<V;i++)
    {
        if(!vis[i])
        {
            if(detect(i,edges,vis))
            {
                return true;
            }
        }
    }
    return false;
}
//Time complexity O(N+2*E)
//Space complexity is O(N)+O(N)~O(N)