#include<iostream>
#include<vector>
#include<map>
using namespace std;
//Space optimization is the main key
//We need to find the maximum profit
int main()
{
    vector<int> arr={7,1,5,3,6,4};
    int n=arr.size();
    int mini=arr[0];
    int profit=0;
    for(int i=1;i<n;i++)
    {
        int cost=arr[i]-mini;
        profit=max(profit,cost);
        mini=min(mini,arr[i]);
    }
    cout<<profit<<endl;
}
//Time complexity is O(N)