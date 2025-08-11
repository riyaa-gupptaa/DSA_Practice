#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
// Color the graph with 2 colors such that no adjacent nodes have same color
bool isBipartite(vector<vector<int>> &graph)
{
    int v = graph.size();
    vector<int> color(v, -1); // -1 means uncolored

    for (int start = 0; start < v; start++)
    {
        if (color[start] == -1)
        { // Unvisited component
            queue<int> q;
            q.push(start);
            color[start] = 0; // Start coloring with 0

            while (!q.empty())
            {
                int node = q.front();
                q.pop();

                for (auto it : graph[node])
                {
                    if (color[it] == -1)
                    { // If uncolored, assign opposite color
                        color[it] = !color[node];
                        q.push(it);
                    }
                    else if (color[it] == color[node])
                    {
                        // Same color found on adjacent nodes -> not bipartite
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
