#include <iostream>
#include <vector>
using namespace std;
// Iterative approach
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return -1;
    }
};
// Recursive Approach
class Solution
{
public:
    int function(vector<int> &arr,int low,int high,int target)
    {
        if(low>high)
        {
            return -1;
        }
        int mid=(low+high)/2;
        if(arr[mid]==target)
        {
            return mid;
        }
        else if(arr[mid]<target)
        {
           return function(arr,mid+1,high,target);
        }
        return function(arr,low,high-1,target);
    }
    int search(vector<int> &nums, int target)
    {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int ans=function(nums,low,high,target);
        return ans;
    }
};
//Time complexity is O(logn)
