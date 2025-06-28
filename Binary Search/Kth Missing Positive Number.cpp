#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int n = arr.size();
        int i = 0;
        int curr = 1;
        while (k > 0)
        {
            if (i < n && arr[i] == curr)
            {
                i++;
            }
            else
            {
                k--;
            }
            if (k == 0)
            {
                return curr;
            }
            curr++;
        }
        return -1;
    }
};

// Binary Search
int findKthPositive(vector<int> &arr, int k)
{
    int low = 0;
    int n = arr.size();
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int missing = arr[mid] - (mid + 1);
        if (missing < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return k + low;
}
// Time complexity is O(N)
// Space complexity is O(1)