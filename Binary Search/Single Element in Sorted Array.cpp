#include<iostream>
#include<vector>
using namespace std;
//Brute force approach
int singleNonDuplicate(vector<int>& nums)
{
    int n=nums.size();
    if(n==1)
    {
        return nums[0];
    }
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            if(nums[i]!=nums[i+1])
            {
                return nums[0];
            }
        }
        else if(i==n-1)
        {
            if(nums[i]!=nums[i-1])
            {
                return nums[i];
            }
        }
        else{
            if(nums[i]!=nums[i+1] && nums[i]!=nums[i-1])
            {
                return nums[i];
            }
        }
    }
    return 0;
}
//Time complexity is O(N)

//Optimsed Solution
//(even,odd)->element is on right half
//(odd,even)->element is on the left half
int singleNonDuplicate(vector<int> &nums)
{
    int n=nums.size();
    if(n==1)
    {
        return nums[0];
    }
    if(nums[0]!=nums[1])
    {
        return nums[0];
    }
    if(nums[n-1]!=nums[n-2])
    {
        return nums[n-1];
    }
    int low=1;
    int high=n-2;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1])
        {
            return nums[mid];
        }
        if((mid%2==1 && nums[mid-1]==nums[mid])||(mid%2==0 && nums[mid]==nums[mid+1]))
        {
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}