#include<iostream>
#include<vector>
using namespace std;
//We will return the floor value
int mySqrt(int x)
{
    int ans=1;
    for(int i=1;i<=x;i++)
    {
        if(i*i<=x)
        {
            ans=i;
        }
        else{
            break;
        }
    }
    return ans;
}
//Time complexity is O(N)

//Optimised Solution
int mySqrt(int x)
{
    int low=1;
    int high=x;
    int ans=1;
    if(x==0)
    {
        return 0;
    }
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if((mid*mid)<=x)
        {
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}
//floor of root n- Find the max integer which on squaring is <= x
//If we get range of 1 to n and we are asked to find min or max, then it's always solved using Binary search