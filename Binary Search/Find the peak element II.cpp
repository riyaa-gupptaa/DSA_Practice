#include<iostream>
#include<vector>
using namespace std;
int maxElement(vector<vector<int>> &mat,int n,int m,int col)
{
    int maxValue=-1;
    int index=-1;
    for(int i=0;i<n;i++)
    {
        if(mat[i][col]>maxValue)
        {
            maxValue=mat[i][col];
            index=i;
        }
    }
    return index;
}
vector<int> findPeakGrid(vector<vector<int>>& mat)
{
    int n=mat.size();
    int m=mat[0].size();
    int low=0;
    int high=m-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        int row=maxElement(mat,n,m,mid);
        int left=mid-1>=0?mat[row][mid-1]:-1;
        int right=mid+1<m?mat[row][mid+1]:-1;
        if(mat[row][mid]>left && mat[row][mid]>right)
        {
            return {row,mid};
        }
        else if(mat[row][mid]<left)
        {
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return {-1,-1};
}
//Time complexity is O(log2m*n)
//Space complexity is O(1)