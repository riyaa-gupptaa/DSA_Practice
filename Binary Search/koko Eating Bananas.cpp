#include <iostream>
#include <vector>
using namespace std;
// Return the min integer k such rhat koko can eat all bananas within h hours
// 2 bananas per hours
// So she will take 2 hours to eat 3 bananas, 3 hours to eat 6 bananas, 4 hours to eat 7 bananas and so on
class Solution
{
public:
    int func(vector<int> &piles, int hourly)
    {
        int totalhrs = 0;
        int n = piles.size();
        for (int i = 0; i < n; i++)
        {
            totalhrs += ceil(piles[i] / hourly);
        }
        return totalhrs;
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int maxi = *max_element(piles.begin(), piles.end());
        for (int i = 1; i <= maxi; i++)
        {
            int reqTime = func(piles, i);
            if (reqTime <= h)
            {
                return i;
            }
        }
        return -1;
    }
};
// Time complexity is O(max(Array element)*n)

// Optimised approach
// Bs on answers={1,max element of array}
int func(vector<int> &piles, int hourly)
{
    int totalhrs = 0;
    int n = piles.size();
    for (int i = 0; i < n; i++)
    {
        totalhrs += ceil((double)piles[i] / (double)hourly);
    }
    return totalhrs;
}
int minEatingSpeed(vector<int> &piles, int h)
{
    int n = piles.size();
    int low = 0;
    int high = *max_element(piles.begin(), piles.end());
    int ans=0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int totalhrs = func(piles, mid);
        if(totalhrs<=h)
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
//Time complexity is O(N)*log2(maximum_element)
//Space comoplexity is O(1)