#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
// works for multiple components
vector<int> topoSort(int V, vector<vector<int>> &adj)
{
    vector<int> inDegree(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            inDegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (inDegree[i] == 0)
            q.push(i);
    }

    vector<int> topo;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (auto it : adj[node])
        {
            inDegree[it]--;
            if (inDegree[it] == 0)
                q.push(it);
        }
    }
    return topo;
}

string findOrder(vector<string> &words, int K) // ✅ K = number of distinct characters
{
    vector<vector<int>> adj(K);

    for (int i = 0; i < words.size() - 1; i++)
    {
        string s1 = words[i];
        string s2 = words[i + 1];
        int len = min(s1.size(), s2.size());

        for (int ptr = 0; ptr < len; ptr++)
        {
            if (s1[ptr] != s2[ptr])
            {
                adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                break;
            }
        }
    }

    vector<int> topo = topoSort(K, adj);

    string ans = "";
    for (auto it : topo)
    {
        ans += char(it + 'a');
    }
    return ans;
}
