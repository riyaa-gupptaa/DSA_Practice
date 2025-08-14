#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    // Step 1: Build adjacency list
    vector<vector<int>> adj(numCourses);
    for (auto &pr : prerequisites)
    {
        adj[pr[1]].push_back(pr[0]); // pr[1] → pr[0]
    }

    // Step 2: Compute indegree
    vector<int> indegree(numCourses, 0);
    for (int i = 0; i < numCourses; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    // Step 3: Push courses with no prerequisites
    queue<int> q;
    for (int i = 0; i < numCourses; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    // Step 4: Process queue
    int count = 0;
    while (!q.empty())
    {
        int course = q.front();
        q.pop();
        count++;

        for (auto next : adj[course])
        {
            indegree[next]--;
            if (indegree[next] == 0)
            {
                q.push(next);
            }
        }
    }

    // Step 5: If processed all courses → possible
    return count == numCourses;
}
