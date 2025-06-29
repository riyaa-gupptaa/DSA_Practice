#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
int func(vector<int> &arr,int pages)
{
    int stu=1;
    int pagesStudent=0;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]>pages)
        {
            return INT_MAX;
        }
        if(pagesStudent+arr[i]<=pages)
        {
            pagesStudent+=arr[i];
        }
        else{
            stu++;
            pagesStudent=arr[i];
        }
    }
    return stu;
}
int findPages(vector<int> &arr, int k)
{
    int n=arr.size();
    if(k>n)
    {
        return -1;
    }
    int low=*max_element(arr.begin(),arr.end());
    int high=accumulate(arr.begin(),arr.end(),0);
    int ans=high;
    for(int pages=low;pages<=high;pages++)
    {
        int cntStu=func(arr,pages);
        if(cntStu<=k)
        {
            ans=pages;
            break;
        }
    }
    return ans;
}

//Optimised Approach
int findPages(vector<int> &arr, int k)
{
    int n=arr.size();
    if(k>n)
    {
        return -1;
    }
    int low=*max_element(arr.begin(),arr.end());
    int high=accumulate(arr.begin(),arr.end(),0);
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        int noStu=func(arr,mid);
        if(noStu>k)
        {
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return low;
}
//Time complexity is O(log2(sum-max+1))*O(n)