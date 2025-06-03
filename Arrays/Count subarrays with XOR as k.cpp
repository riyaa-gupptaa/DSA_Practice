#include<iostream>
#include<vector>
#include<map>
using namespace std;
//Brute force approach
//Generate all subarrays
int subarrayXor(vector<int> &arr, int k)
{
    int n=arr.size();
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int XOR=0;
            for(int k=i;k<j;k++)
            {
                XOR=XOR^arr[k];
            }
            if(XOR==k)
            {
                count++;
            }
        }
    }
    return count;
}
//Time complexity is O(N*N*N)

//Better approach
int subarrayXor(vector<int> &arr, int k)
{
    int n=arr.size();
    int count=0;
    for(int i=0;i<n;i++)
    {
        int XOR=0;
        for(int j=i;j<n;j++)
        {
            XOR=XOR^arr[j];
        }
        if(XOR==k)
        {
            count++;
        }
    }
    return count;
}
//Time complexity is O(N*N)
//Is there a subarray ending with 6 and having a XOR of k
//We will take a hash map with frontXor,Count
int subarrayXor(vector<int> &arr, int k)
{
    int n=arr.size();
    map<int,int> mpp;
    int xr=0;
    mpp[xr]++;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        xr=xr^arr[i];
        int x=xr^k;
        cnt+=mpp[x];
        mpp[xr]++;
    }
    return cnt;
}
//Time complexity is O(N)
//Space complexity is O(N) 