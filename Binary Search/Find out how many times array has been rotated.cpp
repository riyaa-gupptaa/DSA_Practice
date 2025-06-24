#include<iostream>
#include<vector>
using namespace std;
int findRotation(vector<int>& nums)
{
    int n=nums.size();
    int low=0;
    int high=n-1;
    int ans=INT_MAX;
    int index=-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(nums[low]<=nums[high])
        {
            if(nums[low]<ans)
            {
                index=low;
                ans=nums[low];
            }
            break;
        }
        if(nums[low]<=nums[mid])
        {
            if(nums[low]<ans)
            {
                index=low;
                ans=nums[low];
            }
            low=mid+1;
        }
        else{
            high=mid-1;
            if(nums[mid]<ans)
            {
                index=mid;
                ans=nums[mid];
            }
        }
    }
    return index;
}