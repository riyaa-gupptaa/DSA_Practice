#include<iostream>
#include<map>
#include<vector>
using namespace std;
//Brute force approach
int numberOfInversions(vector<int>&a, int n)
{
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                count+=1;
            }
        }
    }
    return count;
}
//Time complexity is O(N*N)

//Optimal approach
int merge(vector<int> &arr,int low,int mid,int high)
{
    vector<int> temp;
    int left=low;
    int right=mid+1;
    int count=0;
    while(left<=mid && right<=high)
    {
        if(arr[left]<=arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            count+=(mid-left+1);
            right++;
        }
    }
    while(left<=mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++)
    {
        arr[i]=temp[i-low];
    }
    return count;
}
int mergeSort(vector<int> &arr,int low,int high)
{
    int cnt=0;
    if(low>=high)
    {
        return;
    }
    int mid=(low+high)/2;
    cnt+=mergeSort(arr,low,mid);
    cnt+=mergeSort(arr,mid+1,high);
    cnt+=merge(arr,low,mid,high);
    return cnt;
}
int numberOfInversions(vector<int>&a, int n)
{
    int cnt=0;
    cnt=mergeSort(a,0,n-1);
    return cnt;
}
//Time complexity is O(NlogN)
