#include<iostream>
#include<vector>
using namespace std;
int median(vector<vector<int>> &mat)
{
    vector<int> ls;
    int n=mat.size();
    int m=mat[0].size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            ls.push_back(mat[i][j]);
        }
    }
    sort(ls.begin(),ls.end());
    return ls[(m*n)/2];
}
//Time complexity is O(n*m)+O(n*m*log(n*m))
//Space complexity is O(2*n*m)
int upperBound(vector<int> &arr,int x,int n)
{
    int low=0;
    int high=n-1;
    int ans=n;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(arr[mid]>x)
        {
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
int countSmallEqual(vector<vector<int>> &matrix,int n,int m,int x)
{
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        cnt+=upperBound(matrix[i],x,m);
    }
    return cnt;
}
int median(vector<vector<int>> &mat)
{
    int low=INT_MAX;
    int high=INT_MIN;
    int n=mat.size();
    int m=mat[0].size();
    for(int i=0;i<n;i++)
    {
        low=min(low,mat[i][0]);
        high=max(high,mat[i][m-1]);
    }
    int req=(n*m)/2;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        int smallEqual=countSmallEqual(mat,n,m,mid);
        if(smallEqual<=req)
        {
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return low;
}