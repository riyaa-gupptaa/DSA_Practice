#include<iostream>
#include<vector>
#include<map>
using namespace std;
//Brute force approach
//Generate all subarrays
int maxProduct(vector<int>& nums)
{
    int maxi=INT_MIN;
    int n=nums.size();
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int prod=1;
            for(int k=i;k<j;k++)
            {
                prod*=nums[k];
            }
            maxi=max(maxi,prod);
        }
    }
    return maxi;
}
//Time complexity is O(N*N*N)
//Space complexity is O(1)

//Better approach
int maxProduct(vector<int>& nums)
{
    int n=nums.size();
    int maxi=INT_MIN;
    for(int i=0;i<n;i++)
    {
        int prod=1;
        for(int j=i;j<n;j++)
        {
            prod=prod*nums[j];
            maxi=max(maxi,prod);
        }
    }
    return maxi;
}
//Time complexity is O(N*N)
//Space complexity is O(1)

//Optimal solution
//Only +ve
//Even negative,+ve
//Odd negative,+ve
//It has zeroes
int maxProduct(vector<int>& nums)
{
    int n=nums.size();
    int pre=1,suff=1;
    int maxi=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(pre==0)
        {
            pre=1;
        }
        if(suff==0)
        {
            suff=1;
        }
        pre=pre*nums[i];
        suff=suff*nums[n-i-1];
        maxi=max(maxi,max(pre,suff));
    }
    return maxi;
}
//Time complexity is O(N)
//Space complexity is O(1)