#include<iostream>
#include<vector>
#include<stack>
using namespace std;
//Monotonic stack means a stack storing elements in either increasing or decreasing order
vector<int> nextLargerElement(vector<int> &arr)
{
    int n=arr.size();
    vector<int> ans(n,0);
    for(int i=0;i<n-1;i++)
    {
        for(int j=+1;j<n-1;j++)
        {
            if(arr[j]>arr[i])
            {
                ans[i]=arr[j];
                break;
            }
        }
    }
    return ans;
}
//time complexity is O(n^2)
//Space complexity is O(N)

//Other Method
vector<int> nextLargerElement(vector<int> &arr)
{
    int n=arr.size();
    vector<int> list1;
    stack<int> st;
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && st.top()<=arr[i])
        {
            st.pop();
        }
        if(st.empty())
        {
            list1[i]=-1;
        }
        else{
            list1[i]=st.top();
        }
        st.push(list1[i]);
    }
    return list1;
}
//Time compplexity is O(2N)
//Space complexity is O(n)