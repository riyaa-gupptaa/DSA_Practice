#include<iostream>
#include<vector>
#include<map>
using namespace std;
//Brute force approach
//linear search with every other element
int main()
{
    vector<int> arr={10,22,12,3,0,6};
    int n=arr.size();
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        bool leader=true;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]>arr[i])
            {
                leader=false;
                break;
            }
        }
        if(leader==true)
        {
            ans.push_back(arr[i]);
        }
    }
}
//Time complexity is O(N*N)
//Space complexity is O(N)

//Optimal approach
int main()
{
    vector<int> arr={10,22,12,3,0,6};
    int n=arr.size();
    int maxi=INT_MIN;
    vector<int> ans;
    for(int i=n-1;i>=0;i--)
    {
        if(arr[i]>maxi)
        {
            ans.push_back(arr[i]);
        }
        //keeps track of the right maximum
        maxi=max(arr[i],maxi);
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }
}
//Time complexity is O(N) and sort is O(NlogN)
//Space complexity is O(N) as we need to return an array