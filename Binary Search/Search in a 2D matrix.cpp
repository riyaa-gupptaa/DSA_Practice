#include<iostream>
#include<vector>
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    int n=matrix.size();
    int m=matrix[0].size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(matrix[i][j]==target)
            {
                return true;
            }
        }
    }
    return false;
}
//Time complexity is O(n*m)
//Space complexity is O(1)
bool bs(vector<int>& row, int target) {
    int low = 0, high = row.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (row[mid] == target)
            return true;
        else if (row[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}
bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    int n=matrix.size();
    int m=matrix[0].size();
    for(int i=0;i<n;i++)
    {
        if(matrix[i][0]<=target && target<=matrix[i][m-1])
        {
            return bs(matrix[i],target);
        }
    }
    return false;
}
//Time complexity is O(n)

//Optimization
//Flatten a 2D to 1D
bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    int low=0;
    int n=matrix.size();
    int m=matrix[0].size();
    int high=(n*m-1);
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        int row=mid/m;
        int col=mid%m;
        if(matrix[row][col]==target)
        {
            return true;
        }
        else if(matrix[row][col]<target)
        {
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return false;
}
//Time complexity is O(log2(n*m))