#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());

        for (int d = 1; d <= maxi; d++)
        {
            int sum = 0;
            for (int i = 0; i < n; i++)
            {
                sum += (nums[i] + d - 1) / d; // correct integer ceil
            }
            if (sum <= threshold)
            {
                return d; // return the divisor, not the sum
            }
        }
        return -1;
    }
};
//Time complexity is maxi*N
//Space complexity is O(1)

//Optimised Solution
int sumOfD(vector<int>&nums,int div)
{
    int sum=0;
    int n=nums.size();
    for(int i=0;i<n;i++)
    {
        sum=sum+ceil((double)(nums[i])/(double)(div));
    }
    return sum;
}
int smallestDivisor(vector<int> &nums, int threshold)
{
    int n=nums.size();
    int ans=-1;
    int low=1;
    int high=*max_element(nums.begin(),nums.end());
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(sumOfD(nums,mid)<=threshold)
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
//Time complexity is O(logm)*N