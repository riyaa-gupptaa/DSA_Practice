#include<iostream>
#include<vector>
#include<map>
using namespace std;
//Brute force approach
int subarraySum(vector<int>& nums, int k)
{
    int n=nums.size();
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int sum=0;
            for(int k=i;k<=j;k++)
            {
                sum+=nums[k];
            }
            if(sum==k)
            {
                count++;
            }
        }
    }
    return count;
} 
//Time complexity is O(N*N*N)

//Better approach
int subarraySum(vector<int>& nums, int k)
{
    int n=nums.size();
    int count=0;
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=i;j<n;j++)
        {
            sum+=nums[j];
        }
        if(sum==k)
        {
            count++;
        }
    }
    return count;
}
//Time complexity is O(N*N)

//Optimal solution
int subarraySum(vector<int>& nums, int k)
{
    int n=nums.size();
    int preSum=0;
    int count=0;
    map<int,int> mpp;
    mpp[0]=1;
    for(int i=0;i<n;i++)
    {
        preSum+=nums[i];
        int remove=preSum-k;
        count+=mpp[remove];
        mpp[preSum]+=1;
    }
    return count;
}
//Time complexity is O(N*logN)