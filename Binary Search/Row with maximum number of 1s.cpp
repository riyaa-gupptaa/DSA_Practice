#include<iostream>
#include<vector>
using namespace std;
vector<int> rowAndMaximumOnes(vector<vector<int>>& mat)
{
    int n=mat.size();
    int m=mat[0].size();
    int max_cnt=-1;
    int ind=-1;

    for(int i=0;i<n;i++)
    {
        int cntRow=0;
        for(int j=0;j<m;j++)
        {
            cntRow+=mat[i][j];
        }
        if(cntRow>max_cnt)
        {
            max_cnt=cntRow;
            ind=i;
        }
    }
    vector<int> ans;
    ans.push_back(max_cnt);
    ans.push_back(ind);
    return ans;
}

//Better Approach
int lowerBound(vector<int> arr,int n,int x)
{
  int low=0;
  int high=n-1;
  int ans=n;
  while(low<=high)
  {
    int mid=(low+high)/2;
    if(arr[mid]>=x)
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
vector<int> rowAndMaximumOnes(vector<vector<int>>& mat)
{
   int cnt_max=0;
   int index=-1;
   int n=mat.size();
   int m=mat[0].size();
   for(int i=0;i<n;i++)
   {
    int cnt_ones=m-lowerBound(mat[i],m,1);
    if(cnt_ones>cnt_max)
    {
        cnt_max=cnt_ones;
        index=i;
    }
   }
   vector<int> ans;
   ans.push_back(cnt_max);
   ans.push_back(index);
   return ans;
}
//Time complexity is O(n*log2m)