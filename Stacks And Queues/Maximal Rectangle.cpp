#include<iostream>
#include<stack>
#include<vector>
using namespace std;
//We will use the concept of prefix Sum and then longest rectangle in histogram
int maxInHistogram(vector<int> &heights)
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
int maximalRectangle(vector<vector<char>>& matrix) 
{
    int r=matrix.size();
    if(r==0)
    {
        return 0;
    }
    int c=matrix[0].size();
    vector<int> ps(c,0);
    int maxi=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(matrix[i][j]=='1')
            {
                ps[j]++;
            }
            if(matrix[i][j]=='0')
            {
                ps[j]=0;
            }
        }
        maxi=max(maxi,maxInHistogram(ps));
    }
    return maxi;
}
//Time complexity is O(M*N)+O(N*2M)
//Space complexity is O(N*M)