#include <iostream>
#include <vector>
using namespace std;
// By peak element we mean to say that
// nums[i-1]<nums[i]>nums[i+1]
// Brute force approach
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if ((i == 0 || nums[i] > nums[i - 1]) &&
                (i == n - 1 || nums[i] > nums[i + 1]))
            {
                return i;
            }
        }
        return 0; // Should never reach here if input is valids
    }
};
// Time complexity is O(n)
// Space complexity is O(1)

// Optimised Solution
int findPeakElement(vector<int> &nums)
{
    int n = nums.size();
    int low=1;
    int high=n-2;
    if(n==1)
    {
        return 0;
    }
    if(nums[0]>nums[1])
    {
        return 1;
    }
    if(nums[n-1]>nums[n-2])
    {
        return n-1;
    }
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if((nums[mid]>nums[mid-1]) && (nums[mid]>nums[mid+1]))
        {
            return mid;
        }
        else if(nums[mid]>nums[mid-1])
        {
            low=mid+1;
        }
        else if(nums[mid]>nums[mid+1])
        {
            high=mid-1;
        }
    }
    return -1;
}
//Time complexity is O(logn)
//Space complexity is O(1)

