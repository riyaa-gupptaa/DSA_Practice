#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
// 2->Rot
// 1->fresh
// 0->fresh
// BFS-Level Wise
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cntfresh = 0;

        // Step 1: Put all initially rotten oranges in queue
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2; // rotten visited
                }
                else
                {
                    vis[i][j] = 0;
                }
                if (grid[i][j] == 1)
                    cntfresh++;
            }
        }

        int tm = 0;
        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, 1, 0, -1};
        int cnt = 0;

        // Step 2: BFS
        while (!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tm = max(tm, t);
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1)
                {
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 2; // mark rotten
                    cnt++;
                }
            }
        }

        // Step 3: If all fresh oranges are rotted
        if (cnt != cntfresh)
            return -1;
        return tm;
    }
};
//Time complexity is O(N*M)
//Space complexity is O(N*M)