#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> findPSE(vector<int> &heights)
{
    int n = heights.size();
    vector<int> pse(n);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] > heights[i])
        {
            st.pop();
        }
        pse[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return pse;
}
vector<int> findNSE(vector<int> &heights)
{
    int n = heights.size();
    vector<int> nse(n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            st.pop();
        }
        nse[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return nse;
}
int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    vector<int> area(n);
    vector<int> nse = findNSE(heights);
    vector<int> pse = findPSE(heights);
    for (int i = 0; i < n; i++)
    {
        area[i] = heights[i] * (nse[i] - pse[i] - 1);
    }
    int maxi = *max_element(area.begin(), area.end());
    return maxi;
}
// Time complexity is O(5N)
// Space complexity is O(4N)

// Let's optimise the brute force solution
int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    stack<int> st;
    int maxArea = 0;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] > heights[i])
        {
            int height = heights[st.top()];
            st.pop();
            int right = i;
            int left = st.empty() ? -1 : st.top();
            maxArea = max(height * (right - left - 1), maxArea);
        }
        st.push(i);
    }

    // Process remaining bars in stack
    while (!st.empty())
    {
        int height = heights[st.top()];
        st.pop();
        int right = n;
        int left = st.empty() ? -1 : st.top();
        maxArea = max(height * (right - left - 1), maxArea);
    }

    return maxArea;
}

// Time complexity is O(N)+O(N)
// Space complexity is O(N)