#include<iostream>
#include<vector>
using namespace std;
int minJumps(vector<int>& arr)
{
    int n=arr.size();
    int ans=0;
    int i=0;
    int range=arr[0];
    while(range<n-1)
    {
        int temp=range;
        while(i<n && i<=range)
        {
            temp=max(temp,arr[i]+i);
            i++;
        }
        if(temp==range && i<n)
        {
            return -1;
        }
        range=temp;
        ans++;
    }
    return ans+1;
}