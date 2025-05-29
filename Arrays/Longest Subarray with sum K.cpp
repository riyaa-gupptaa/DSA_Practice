#include<iostream>
using namespace std;
#include<vector>
#include<map>
//Brute force approach
int main()
{
    vector<int> arr={1,2,3,1,1,1,1,4,2,3};
    int d=3;
    //We need to return the contiguous part of the array
    //Generate all subarrays
    int n=arr.size();
    int llen=0;
    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=i;j<n;j++)
        {
            sum+=arr[j];
            if(sum==d)
            {
                llen=max(llen,(j-i+1));
            }
        }
    }
    cout<<llen<<endl;
}
//Time complexity of O(n*n)
//Space is constant

//Better Solution
//We will use hashing for the better solution
int main()
{
    vector<int> arr={1,2,3,1,1,1,1,4,2,3};
    int k=3;
    int n=arr.size();
    long long sum=0;
    int maxlen=0;
    map<long long,int> preSumMap;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum==k)
        {
            maxlen=max(maxlen,i+1);
        }
        long long rem=sum-k;
        if(preSumMap.find(rem)!=preSumMap.end())
        {
            int len=i-preSumMap[rem];
            maxlen=max(maxlen,len);
        }
        if(preSumMap.find(sum)==preSumMap.end())
        {
        preSumMap[sum]=i;
        }
    }
    cout<<maxlen<<endl;
}
//This code will fail for array's with 0's
//It will constantly update the hash table on encountering 0's
//Hence it will fail for array's with 0's
//It will work for both positives and negatives
//Time complexity is O(N*LogN) for ordered maps
//Time complexity is O(N*1) for unordered maps
//Space complexity is O(N)

//Optimal solution
//2 pointer approach
int main()
{
    vector<int> arr={1,2,3,1,1,1,1,3,3};
    int n=arr.size();
    int k=6;
    int left=0;
    int right=0;
    long long sum=arr[0];
    int maxlen=0;
    while(right<n)
    {
        while(left<=right && sum>k)
        {
            sum-=arr[left];
            left++;
        }
        if(sum==k)
        {
            maxlen=max(maxlen,right-left+1);
        }
        right++;
        if(right<n)
        {
            sum+=arr[right];
        }
    }
    cout<<maxlen<<endl;
}
//This approach works for postive and zeroes
//Time complexity is O(2n) for worst case
//Space complexity is O(1)