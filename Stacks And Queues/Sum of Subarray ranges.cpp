#include<iostream>
#include<vector>
#include<stack>
using namespace std;
long long subArrayRanges(vector<int>& nums)
{
    int n=nums.size();
    long long sum=0;
    for(int i=0;i<nums.size();i++)
    {
        int largest=nums[i];
        int smallest=nums[i];
        for(int j=i+1;j<n;j++)
        {
            largest=max(largest,nums[j]);
            smallest=min(smallest,nums[j]);
            sum+=(largest-smallest);
        }
    }
    return sum;
}
//Time complexity is O(N^2)
//Space complexity is O(1)

//For Optimal approach 
//Sum of subarray maximum-sum of subarray minimum
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
            nge[i]=n;
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
long long subArrayRanges(vector<int>& nums)
{
    long long num1=sumOfMax(nums);
    long long num2=sumSubarrayMins(nums);
    return num1-num2;
}
//Time complexity is O(10N)~O(N)
//Space complexity is O(10N)~O(N)