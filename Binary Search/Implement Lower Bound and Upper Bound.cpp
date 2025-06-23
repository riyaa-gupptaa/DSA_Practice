#include <iostream>
#include <vector>
using namespace std;
// lower bound
// smallest index such that arr[ind]>=x
int lowerBound(vector<int> &arr, int target)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
// Time complexity is O(logn)

// lb=lower_bound(arr.begin(),arr.end(),n)-arr.begin();

// Upper Bound
//Smallest index such that arr[ind]>x
//  User function Template for C++
class Solution
{
public:
    int upperBound(vector<int> &arr, int target)
    {
        int n=arr.size();
        int low=0;
        int high=n-1;
        int ans=n;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(arr[mid]>target)
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
};
//Time complexity is O(log2n)
