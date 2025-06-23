#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ans;
        int n = nums.size();
        int first = -1;
        int last = -1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == target)
            {
                if (first == -1)
                {
                    first = i;
                }
                last = i;
            }
        }
        ans.push_back(first);
        ans.push_back(last);
        return ans;
    }
};
// Time complexity is O(N);

// Optimised Solution
int findLowerBound(vector<int> &nums, int target)
{
    int low = 0, high = nums.size();
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

int findUpperBound(vector<int> &nums, int target)
{
    int low = 0, high = nums.size();
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] <= target)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    int n = nums.size();
    int lb = findLowerBound(nums, target);

    if (lb == n || nums[lb] != target)
        return {-1, -1};

    int ub = findUpperBound(nums, target);

    return {lb, ub - 1};
}
//Time complexity is 2*O(log2n)
//Space complexity is O(1)
int firstOccurrence(vector<int> &nums,int n,int target)
{
    int low=0;
    int high=n-1;
    int first=-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(nums[mid]==target)
        {
            first=mid;
            high=mid-1;
        }
        else if(nums[mid]<target)
        {
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
return first;
}
int lastOccurrence(vector<int> &nums,int n,int target)
{
    int low=0;
    int high=n-1;
    int last=-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(nums[mid]==target)
        {
            last=mid;
            low=mid+1;
        }
        else if(nums[mid]<target)
        {
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return last;
}
vector<int> searchRange(vector<int> &nums, int target)
{
    int n=nums.size();
    int first=firstOccurrence(nums,n,target);
    if(first==-1)
    {
        return {-1,-1};
    }
    int last=lastOccurrence(nums,n,target);
    return {first,last};
}
