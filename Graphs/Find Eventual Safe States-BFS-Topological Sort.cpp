#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
vector<int> eventualSafeNodes(int V,vector<vector<int>> &adj)
{
    vector<vector<int>> adjRev(V);
    vector<int> inDegree(V,0);
    for(int i=0;i<V;i++)
    {
        for(auto it:adj[i])
        {
            adjRev[it].push_back(i);
            inDegree[i]++;
        }
    }
    queue<int> q;
    vector<int> safeNodes;
    for(int i=0;i<V;i++)
    {
        if(inDegree[i]==0)
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        safeNodes.push_back(node);
        for(auto it: adjRev[node])
        {
            inDegree[it]--;
            if(inDegree[it]==0)
            {
                q.push(it);
            }
        }
    }
    sort(safeNodes.begin(),safeNodes.end());
    return safeNodes;
}