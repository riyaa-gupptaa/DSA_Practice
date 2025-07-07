// User function template for C++
#include<iostream>
#include<vector>
using namespace std;
class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int res=arr[n-1]-arr[0];
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]-k<0)
            {
                continue;
            }
            int minH=min(arr[0]+k,arr[i]-k);
            int maxH=max(arr[i-1]+k,arr[n-1]-k);
            res=min(res,maxH-minH);
        }
        return res;
    }
};
//Time complexity is O(Nlogn)
//space complexity is O(1)