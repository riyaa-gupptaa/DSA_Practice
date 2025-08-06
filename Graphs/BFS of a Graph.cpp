#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
// Breadth-Level Wise
vector<int> bfs(vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<int> vis(n, 0);
    vis[0] = 1;
    queue<int> q;
    q.push(0);
    vector<int> bfs_order; 

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs_order.push_back(node);
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }

    return bfs_order;
}
//Space complexity is O(3N)~O(N)
//TIme complexity is O(N)+O(2E)
