#include<iostream>
#include<vector>
#include<map>
using namespace std;
//Brute force approach
void rotate(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();
    vector<vector<int>> temp=matrix;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            matrix[j][n-1-i]=temp[i][j];
        }
    }
}
//Time complexity is O(N*N)
//Space complexity is O(N*N)

//Optimal Solution
//First transpose the matrix
//Column becomes the row and the row becomes the column
//Then reverse every row
void rotate(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    //O(N*N/2)
    for(int i=0;i<n;i++)
    {
        reverse(matrix[i].begin(),matrix[i].end());
    }
}
//Time complexity is O(N/2*N/2)
//Space complexity is O(1)