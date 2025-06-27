#include <iostream>
#include <vector>
using namespace std;
// m signifies number of bouquets
// k represents adjacent flowers required
class Solution
{
public:
    bool possible(vector<int> &bloomday, int day, int m, int k)
    {
        int n = bloomday.size();
        int NOB = 0;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (bloomday[i] <= day)
            {
                count++;
            }
            else
            {
                NOB += (count / k);
                count = 0;
            }
        }
        NOB += (count / k);
        if (NOB >= m)
        {
            return true;
        }
        return false;
    }
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int n = bloomDay.size();
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        if (n < (m * k))
        {
            return -1;
        }
        for (int i = low; i <= high; i++)
        {
            if (possible(bloomDay, i, m, k))
            {
                return i;
            }
        }
        return -1;
    }
};
// Time complexity is O((maxi-mini+1)*N)

// Optimised Solution
bool possible(vector<int> &bloomday, int day, int m, int k)
{
    int n = bloomday.size();
    int NOB = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (bloomday[i] <= day)
        {
            count++;
        }
        else
        {
            NOB += (count / k);
            count = 0;
        }
    }
    NOB += (count / k);
    if (NOB >= m)
    {
        return true;
    }
    return false;
}
int minDays(vector<int> &bloomDay, int m, int k)
{
    int n = bloomDay.size();
    int low = *min_element(bloomDay.begin(), bloomDay.end());
    int high = *max_element(bloomDay.begin(), bloomDay.end());
    if (n < (m * k))
    {
        return -1;
    }
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (possible(bloomDay, mid, m, k) == true)
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
//Time complexity is O(N*log(max-min+1))
