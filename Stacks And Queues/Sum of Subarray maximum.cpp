#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> PGE(vector<int> &nums)
{
    int n=nums.size();
    vector<int> pge(n);
    stack<int> st;
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && nums[st.top()]<nums[i])
        {
            st.pop();
        }
        pge[i]=st.empty()?-1:st.top();
        st.push(i);
    }
    return pge;
}
vector<int> NGE(vector<int> &nums)
{
    int n=nums.size();
    vector<int> nge(n);
    stack<int> st;
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && nums[st.top()]<=nums[i])
        {
            st.pop();
        }
        if(st.empty())
        {
            nge[i]=-1;
        }
        else{
            nge[i]=st.top();
        }
        st.push(i);
    }
    return nge;
}
long long sumOfMax(vector<int> &arr)
{
    int n=arr.size();
    vector<int> nge=NGE(arr);
    vector<int> pge=PGE(arr);
    long long total=0;
    for(int i=0;i<n;i++)
    {
        long long left=i-pge[i];
        long long right=nge[i]-i;
        total+=(long long)arr[i]*left*right;
    }
    return total;
}