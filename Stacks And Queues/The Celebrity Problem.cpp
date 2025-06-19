#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
    int celebrity(vector<vector<int>> &mat)
    {
        int n = mat.size();
        vector<int> knowme(n, 0);
        vector<int> iknow(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 1)
                {
                    knowme[j]++;
                    iknow[i]++;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (knowme[i] == n - 1 && iknow[i] == 0)
            {
                return i;
            }
        }
        return -1;
    }
};
// Time complexity is O(N*N)
// Space complexity is O(2N)

// Optimized Solution
class Solution
{
public:
    int celebrity(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int top = 0;
        int down = n - 1;

        // Step 1: Find the candidate
        while (top < down)
        {
            if (mat[top][down] == 1)
            {
                // top knows down → top cannot be celebrity
                top++;
            }
            else
            {
                // top does not know down → down cannot be celebrity
                down--;
            }
        }

        int candidate = top;

        // Step 2: Verify the candidate
        for (int i = 0; i < n; i++)
        {
            if (i != candidate)
            {
                if (mat[candidate][i] == 1 || mat[i][candidate] == 0)
                {
                    return -1; // candidate knows someone OR someone doesn't know candidate
                }
            }
        }

        return candidate;
    }
};
//Time complexity is O(2N)
//Space complexity is O(1)