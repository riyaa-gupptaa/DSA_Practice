#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
int longestSubarray(vector<int> &nums)
{
    int l = 0;     // Left pointer of sliding window
    int zeros = 0; // Count of zeros in the current window

    for (const int num : nums)
    {
        if (num == 0)
        {
            ++zeros; // Expand window, count zero
        }

        // If we have more than 1 zero, shrink the window from the left
        if (zeros > 1 && nums[l++] == 0)
        {
            --zeros;
        }
    }

    // At the end, window size is nums.size() - l
    // But since we must delete 1 element, subtract 1
    return nums.size() - l - 1;
}
