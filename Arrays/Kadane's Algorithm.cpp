#include<iostream>
#include<vector>
#include<map>
using namespace std;
//Brute force approach
//We can try all the subarrays formed
int main()
{
    vector<int> arr={-2,-3,4,-1,-2,1,5,-3};
    int n=arr.size();
    int maxi=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int sum=0;
            for(int k=i;k<=j;k++)
            {
                sum+=arr[k];
            }
            maxi=max(sum,maxi);
        }
    }
    cout<<maxi<<endl;
}
//Time complexity is O(N*N*N)

//Better Approach
//We can store the sum of the previous array and add the next element to that particular subarray only
int main()
{
    vector<int> arr={-2,-3,4,-1,-2,1,5,-3};
    int n=arr.size();
    int maxi=0;
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=i;j<n;j++)
        {
            sum+=arr[j];
            maxi=max(sum,maxi);
        }
    }
    cout<<maxi<<endl;
}
//Time complexity is O(N*N)
//Space complexity is O(1)

//Optimal Solution
long long maxSubarraySum(int arr[],int n)
{
    long long sum=0,maxi=LONG_MIN;
   /**int ansStart=-1;
    int ansEnd=-1; //If you want to print the subarray with maximum sum
    int start=0;*/
    for(int i=0;i<n;i++)
    {
       /* if(sum==0)
        {
            start=i; //To print the subarray
        }*/
        sum+=arr[i];
        if(sum>maxi)
        {
            maxi=sum;
           /* ansStart=start; //To print the subarray
            ansEnd=i;*/
        }
        if(sum<0)
        {
            sum=0;
        }
    }
    return maxi;
}
//Time complexity is O(N)
//Space complexity is O(1)
//Can you print the maximum subarray