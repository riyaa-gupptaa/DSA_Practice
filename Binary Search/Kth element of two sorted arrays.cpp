#include<iostream>
#include<vector>
using namespace std;
int kthElement(vector<int> &arr1, vector<int>& arr2,int k){
    int m=arr1.size();
    int n=arr2.size();
    if(m>n)
    {
        return kthElement(arr2,arr1,k);
    }
    int low=max(k-n,0);
    int high=min(k,m);
    int left=k;
    int n1=m+n;
    while(low<=high)
    {
        int mid1=low+(high-low)/2;
        int mid2=left-mid1;
        int l1=INT_MIN,l2=INT_MIN;
        int r1=INT_MAX,r2=INT_MAX;
        if(mid1<m)
        {
            r1=arr1[mid1];
        }
        if(mid2<n)
        {
            r2=arr2[mid2];
        }
        if(mid1-1>=0)
        {
            l1=arr1[mid1-1];
        }
        if(mid2-1>=0)
        {
            l2=arr2[mid2-1];
        }
        if(l1<=r2 && l2<=r1)
        {
            return max(l1,l2);
        }
        else if(l1>r2)
        {
            high=mid1+1;
        }
        else{
            low=mid1+1;
        }
    }
    return 0;
}