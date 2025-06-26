#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int func(int mid,int n)
    {
        long long ans=1;
        while(n>0)
        {
            if(n%2==1)
            {
                ans=ans*mid;
                n=n-1;
            }
            else{
                mid=mid*mid;
                n=n/2;
            }
        }
        return ans;
    }
    int nthRoot(int n, int m)
    {
        int low=1;
        int high=m;
        if(m==0)
        {
            return 0;
        }
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(func(mid,n)==m)
            {
                return mid;
            }
            else if(func(mid,n)<m)
            {
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return -1;
    }
};

//Another method
int func(int mid,int n,int m)
{
    long long ans=1;
    for(int i=1;i<=n;i++)
    {
        ans=ans*mid;
        if(ans>m)
        {
            return 2;
        }
    }
    if(ans==m)
    {
        return 1;
    }
    return 0;
}
int Nthroot(int n,int m)
{
    int low=1;
    int high=m;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        int midN=func(mid,n,m);
        if(midN==1)
        {
            return mid;
        }
        else if(midN==0)
        {
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}