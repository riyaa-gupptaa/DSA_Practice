#include<iostream>
#include<vector>
using namespace std;
//Brute force approach
int main()
{
    vector<int> arr={1,1,0,1,1,1,0,1,1};
    int count=0;
    int n=arr.size();
    int maxi=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==1)
        {
            count++;
            maxi=max(maxi,count);
        }
        if(arr[i]==0)
        {
            count=0;
        }
    }
    cout<<maxi<<endl;
}
//Time complexity is O(N)