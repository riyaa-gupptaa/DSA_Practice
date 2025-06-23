#include <iostream>
#include <vector>
using namespace std;
// Floor is the largest number in array<=x
// Smallest number in array>=x that is ceil
// Lower bound is ceil
class Solution
{
public:
    int findFloor(vector<int> &arr, int x)
    {
        // Your code here
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        int ans = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] <= x)
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }
};

//Ceil of number is the lower bound
int findCeil(vector<int> &arr, int target)
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