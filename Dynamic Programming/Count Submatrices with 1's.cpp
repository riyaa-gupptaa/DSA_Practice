#include <iostream>
#include <string>
#include <stack>
using namespace std;
int countSubmatrices(int n, int m, vector<vector<int>> &arr)
{
    vector<int> height(m, 0);
    int total = 0;

    for (int i = 0; i < n; i++)
    {
        // update histogram heights
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
                height[j] = 0;
            else
                height[j] += 1;
        }

        // stack method to count submatrices ending at row i
        stack<int> st;
        vector<int> sum(m, 0);
        for (int j = 0; j < m; j++)
        {
            while (!st.empty() && height[st.top()] >= height[j])
                st.pop();

            if (!st.empty())
            {
                int prev = st.top();
                sum[j] = sum[prev] + height[j] * (j - prev);
            }
            else
            {
                sum[j] = height[j] * (j + 1);
            }

            st.push(j);
            total += sum[j];
        }
    }

    return total;
}