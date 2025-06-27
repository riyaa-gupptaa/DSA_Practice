#include <iostream>
#include <algorithm>
#include<numeric>
#include <vector>
using namespace std;
// Answer will be always between [max,sum]
int function2(vector<int> &weights, int cap)
{
    int day = 1;
    int load = 0;
    int n = weights.size();
    for (int i = 0; i < n; i++)
    {
        if (load + weights[i] > cap)
        {
            day += 1;
            load = weights[i];
        }
        else
        {
            load += weights[i];
        }
    }
    return day;
}

int shipWithinDays(vector<int> &weights, int days)
{
    int low = *max_element(weights.begin(), weights.end());   // At least the heaviest item
    int high = accumulate(weights.begin(), weights.end(), 0); // At most the sum of all weights
    int ans = high;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int requiredDays = function2(weights, mid);
        if (requiredDays <= days)
        {
            ans = mid; // Try smaller capacity
            high = mid - 1;
        }
        else
        {
            low = mid + 1; // Need more capacity
        }
    }

    return ans;
}