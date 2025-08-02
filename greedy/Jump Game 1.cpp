#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
bool canJump(vector<int>& nums)
{
    int n=nums.size();
    int maxInd=0;
    for(int i=0;i<n;i++)
    {
        if(i>maxInd)
        {
            return false;
        }
        maxInd=max(maxInd,i+nums[i]);
    }
    return true;
}
//Time complexity is O(N)
//Space complexity is O(1)