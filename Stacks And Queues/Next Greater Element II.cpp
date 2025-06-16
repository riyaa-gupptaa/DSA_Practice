#include<iostream>
#include<vector>
#include<stack>
using namespace std;
//We will use the concept of circular array
vector<int> nextLargerElement(vector<int> &arr)
{
    int n=arr.size();
    vector<int> list1(n,-1);
    stack<int> st;
    for(int i=2*n-1;i>=0;i--)
    {
        int idx=i%n;
        while(!st.empty() && st.top()<=arr[idx])
        {
            st.pop();
        }
        if(st.empty())
        {
            list1[i]=-1;
        }
        else
        {
            list1[i]=st.top();
        }
        st.push(arr[idx]);
    }
    return list1;
}
//Time complexity is O(4N)
//Space complexity is O(2N)