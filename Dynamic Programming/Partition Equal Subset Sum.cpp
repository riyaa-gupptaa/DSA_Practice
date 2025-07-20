#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
using namespace std;
// Exactly 2 subsets
bool isSubsetSum(vector<int> &arr, int sum)
{
    int n = arr.size();
    vector<bool> curr(sum + 1, 0), prev(sum + 1, 0);
    prev[0] = curr[0] = true;
    if(arr[0]<=sum)
    {
        prev[arr[0]] = true;
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= sum; target++)
        {
            bool nottake = prev[target];
            bool take = false;
            if (arr[ind] <= target)
            {
                take = prev[target - arr[ind]];
            }
            curr[target] = take | nottake;
        }
        prev = curr;
    }
    return prev[sum];
}
bool canPartition(vector<int> &nums)
{
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
    }
    int target = sum / 2;
    if (sum % 2)
    {
        return false;
    }
    return isSubsetSum(nums, target);
}