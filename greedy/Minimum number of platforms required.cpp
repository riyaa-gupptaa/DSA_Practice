#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
//max number of intersections
int findPlatform(vector<int>& arr, vector<int>& dep)
{
    int n=arr.size();
    int maxCnt=0;
    for(int i=0;i<n;i++)
    {
        int cnt=1;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j] <= dep[i] && arr[i] <= dep[j])
            {
                cnt++;
            }
            maxCnt=max(maxCnt,cnt);
        }
    }
    return maxCnt;
}
//Time complexity is O(N*N)
//Space complexity is O(1)

//Optimised
int findPlatform(vector<int>& arr, vector<int>& dep)
{
    int n=arr.size();
    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());
    int cnt=0;
    int maxCnt=0;
    int i=0;
    int j=0;
    while(i<n)
    {
        if(arr[i]<=dep[j])
        {
            cnt=cnt+1;
            i=i+1;
        }
        else{
            cnt=cnt-1;
            j=j+1;
        }
        maxCnt=max(cnt,maxCnt);
    }
    return maxCnt;
}
//Time complexity is O(2N+2NlogN)
//Space complexity is O(1)