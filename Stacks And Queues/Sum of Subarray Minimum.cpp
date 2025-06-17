#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int sumSubarrayMins(vector<int>& arr)
{
    const int mod=1e9+7;
    int n=arr.size();
    int sum=0;
    for(int i=0;i<n;i++)
    {
        int mini=arr[i];
        for(int j=i;j<n;j++)
        {
            mini=min(mini,arr[j]);
            sum=(sum+mini)%mod;
        }
    }
    return sum;
}
//Time complexity is O(n^2)
//Space complexity is O(1)

//Optimised Solution
vector<int> findNSE(vector<int> &arr)
{
    int n=arr.size();
    vector<int> nse(n);
    stack<int> st;
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && arr[st.top()]>=arr[i])
        {
            st.pop();
        }
        nse[i]=st.empty()?n:st.top();
        st.push(i);
    }
    return nse;
}
vector<int> findPSE(vector<int> &arr)
{
    int n=arr.size();
    vector<int> pse(n);
    stack<int> st;
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && arr[st.top()]>arr[i])
        {
            st.pop();
        }
        pse[i]=st.empty()?-1:st.top();
        st.push(i);
    }
    return pse;
}
int sumSubarrayMins(vector<int>& arr)
{
    int n=arr.size();
    const int mod=(int)1e9+7;
    vector<int> nse=findNSE(arr);
    vector<int> pse=findPSE(arr);
    int total=0;
    for(int i=0;i<n;i++)
    {
        int left=i-pse[i];
        int right=nse[i]-i;
        total=(total+(right*left*1LL*arr[i])%mod)%mod;
    }
    return total;
}
//Time complexity is O(5N)
//Space complexity is O(5N)