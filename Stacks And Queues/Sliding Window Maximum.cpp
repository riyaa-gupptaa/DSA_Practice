#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i <= n - k; i++)
        {
            int maxi = 0;
            for (int j = i; j < i + k; j++)
            {
                maxi = max(maxi, nums[j]);
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};
// Time complexity is O(N-K)*O(k)
// Space complexity is O(N-K)

// Optimal Approach
// K elements, Keep the window elements
// monotonic stack-Store elements in decreasing order
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n=nums.size();
        vector<int> ans;
        deque<int> dq;
        for(int i=0;i<n;i++)
        {
            while(!dq.empty() && i-dq.front()>=k)
            {
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()]<=nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k-1)
            {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};
//Time complexty is O(2N)
//Space complexity is O(K)