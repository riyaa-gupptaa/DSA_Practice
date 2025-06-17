#include<iostream>
#include<stack>
#include<vector>
using namespace std;
//Summation of min(leftmax,rightmax)-arr[i]
//Prefix max will store maximum elements till that index
int trap(vector<int>& height)
{
    int n=height.size();
    vector<int> prefixMax(n,0);
    prefixMax[0]=height[0];
    for(int i=1;i<n;i++)
    {
        prefixMax[i]=max(prefixMax[i-1],height[i]);
    }
    vector<int> suffixMax(n,0);
    suffixMax[n-1]=height[n-1];
    for(int i=n-2;i>=0;i--)
    {
        suffixMax[i]=max(suffixMax[i+1],height[i]);
    }
    int total=0;
    for(int i=0;i<n;i++)
    {
        int leftMax=prefixMax[i];
        int rightMax=suffixMax[i];
        if(height[i]<leftMax && height[i]<rightMax)
        {
            total+=min(leftMax,rightMax)-height[i];
        }
    }
    return total;
}
//Time complexity is O(2N)+O(N)~O(3N)
//Space complexity is O(2N)

//Optimised Solution
int trap(vector<int>& height)
{
    int n=height.size();
    int leftMax=0;
    int rightMax=0;
    int total=0;
    int l=0;
    int r=n-1;
    while(l<r)
    {
        if(height[l]<=height[r])
        {
            if(leftMax>height[l])
            {
                total+=leftMax-height[l];
            }
            else{
                leftMax=height[l];
            }
            l=l+1;
        }
        else{
            if(rightMax>height[r])
            {
                total+=rightMax-height[r];
            }
            else{
                rightMax=height[r];
            }
            r=r-1;
        }
    }
    return total;
}
//Time complexity is O(N)
//Space complexity is O(1)