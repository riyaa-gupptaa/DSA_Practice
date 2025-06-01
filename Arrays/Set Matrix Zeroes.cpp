#include<iostream>
#include<vector>
using namespace std;
//brute force approach
void markRow(int i,vector<vector<int>> &matrix,int m)
{
    for(int j=0;j<m;j++)
    {
        if(matrix[i][j]!=0)
        {
            matrix[i][j]=-1;
        }
    }
}
void markCol(int j,vector<vector<int>> &matrix,int n)
{
    for(int i=0;i<n;i++)
    {
        if(matrix[i][j]!=0)
        {
            matrix[i][j]=-1;
        }
    }
}
void setZeroes(vector<vector<int>> &matrix)
{
    int n=matrix.size();//size of rows
    int m=matrix[0].size();//size of columns
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(matrix[i][j]==0)
            {
                markRow(i,matrix,m);
                markCol(j,matrix,n);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(matrix[i][j]==-1)
            {
                matrix[i][j]=0;
            }
        }
    }
}
//Time complexity is O(N*M)*O(N+M)+O(N*M)~O(N*N*N)

//Better approach
//If there is at least one zero in the column, mark the whole column as zero
//If there is at least one zero in the row, mark it as zero
void setZeroes(vector<vector<int>> &matrix)
{
    int n=matrix.size();//size of rows
    int m=matrix[0].size();//size of columns
    vector<int> col(m,0);
    vector<int> row(n,0);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(matrix[i][j]==0)
            {
                row[i]=1;
                col[j]=1;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(row[i]||col[j])
            {
                matrix[i][j]=0;
            }
        }
    }
}

//Time complexity is O(2*N*M)
//Space complexity is O(N)+O(M)

//Optimal solution
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();
    //int col[m]={0}; --> matrix[0][...]
    //int row[n]={0}; --> matrix[...][0]
    int col0=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(matrix[i][j]==0)
            {
                //mark the ith row
                matrix[i][0]=0;
                //mark the j-th column
                if(j!=0)
                {
                matrix[0][j]=0;
                }
                else{
                    col0=0;
                }
            }
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(matrix[i][j]!=0)
            {
                if(matrix[0][j]==0||matrix[i][0]==0)
                {
                    matrix[i][j]=0;
                }
            }
        }
    }
    if(matrix[0][0]==0)
    {
        for(int j=0;j<m;j++)
        {
            matrix[0][j]=0;
        }
    }
    if(col0==0)
    {
        for(int i=0;i<n;i++)
        {
            matrix[i][0]=0;
        }
    }
    return matrix;
}
//Time complexity is O(N*M)
//Space complexity is O(1)