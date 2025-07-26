#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
//dp[i]-Signifies the longest Increasing subsquence that ends at index i
vector<int> getLIS(vector<int>& arr)
{
    int n=arr.size();
    vector<int> dp(n,1),hash(n);
    int maxi=1;
    int lastindex=0;
    for(int i=0;i<n;i++)
    {
        hash[i]=i;
        for(int prev=0;prev<i;prev++)
        {
            if(arr[prev]<arr[i] && 1+dp[prev]>dp[i])
            {
                dp[i]=max(dp[i],1+dp[prev]);
                hash[i]=prev;
            }
        }
        if(dp[i]>maxi)
        {
            maxi=dp[i];
            lastindex=i;
        }
    }
    vector<int> temp;
    temp.push_back(arr[lastindex]);
    int ind=1;
    while(hash[lastindex]!=lastindex)
    {
        lastindex=hash[lastindex];
        temp.push_back(arr[lastindex]);
    }
    reverse(temp.begin(),temp.end());
    return temp;
}