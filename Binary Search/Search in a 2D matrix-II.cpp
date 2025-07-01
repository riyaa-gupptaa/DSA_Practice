#include<iostream>
#include<vector>
using namespace std;
//Brute force approach
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

//Better approach
int bs(vector<int>& row, int target) {
    int low = 0, high = row.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (row[mid] == target)
            return mid;
        else if (row[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
vector<int> searchMatrix2(vector<vector<int>>& matrix, int target)
{
    int n=matrix.size();
    for(int i=0;i<n;i++)
    {
        int ind=bs(matrix[i],target);
        if(ind!=-1)
        {
            return {i,ind};
        }
    }
    return {-1,-1};
}
//Time complexity is O(N*log2m)
vector<int> searchMatrix2(vector<vector<int>>& matrix, int target)
{
    int n=matrix.size();
    int m=matrix[0].size();
    int row=0;
    int col=m-1;
    while(row<n && col>=0)
    {
        if(matrix[row][col]==target)
        {
            return {row,col};
        }
        else if(matrix[row][col]<target)
        {
            row++;
        }
        else{
            col--;
        }
    }
    return {-1,-1};
}
//Time complexity is O(n+m)
//Space complexity is O(1)