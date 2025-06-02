#include<iostream>
#include<map>
#include<vector>
using namespace std;
//Given Row and column, tell me the element at that place
//Ex R=5 C=3, element=6
//Print any nth row of the pascal triangle
//Given N print the entire triangle
//for the first problem r-1 C n-1 
int findNcR(int n,int r)
{
    int res=1;
    for(int i=0;i<r;i++)
    {
        res=res*(n-i);//10*9*8
        res=res/(i+1);// divide by 1*2*3
    }
    return res;
}
//Time complexity is O(n)+O(r)+O(n-r)
//Space complexity is O(1)
//funNcr(r-1,c-1) It can easily solve the first type of problem

//2nd kind of problem
//Nth row-> N elements
int findNcr(int n,int r)
{
    int res=1;
    for(int i=0;i<r;i++)
    {
        res=res*(n-i);
        res=res/(i+1);
    }
    return res;
}
int main()
{
    int n;//Number of rows
for(int c=1;c<=n;c++)
{
    findNcr(n-1,c-1);
}
}
//Time complexity is O(N*r)
//Optimal approach
vector<int> generateRow(int row)
{
    long long ans=1;
    vector<int> ansRow;
    ansRow.push_back(1);
    for(int col=1;col<row;col++)
    {
        ans=ans*(row-col);
        ans=ans/(col);
        ansRow.push_back(ans);
    }
    return ansRow;
}
vector<vector<int>> pascalTriangle(int N)
{
    vector<vector<int>> ans;
    for(int i=1;i<=N;i++)
    {
        vector<int> temp=generateRow(i);
        ans.push_back(temp);
    }
    return ans;
}