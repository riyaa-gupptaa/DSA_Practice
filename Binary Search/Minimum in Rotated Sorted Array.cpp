#include<iostream>
#include<vector>
using namespace std;
//Identify the sorted half
//Why is the right half not sorted
//Sorted half may or may not have the answer
int findMin(vector<int>& nums)
{
    int n=nums.size();
    int low=0;
    int high=n-1;
    int ans=INT_MAX;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(nums[low]<=nums[mid])
        {
            ans=min(ans,nums[low]);
            low=mid+1;
        }
        else{
            ans=min(ans,nums[mid]);
            high=mid-1;
        }
    }
    return ans;
}