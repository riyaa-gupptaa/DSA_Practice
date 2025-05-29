#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main()
{
    vector<int> arr={1,1,2,3,3,4,4};
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        int num=arr[i];
        int count=0;
        for(int j=0;j<n;j++)
        {
            if(arr[j]==num)
            {
                count++;
            }
        }
        if(count==1)
        {
            cout<<num<<endl;
        }
    }
}
//Time complexity is O(N*N)
//Space complexity is O(1)

//Better approach
//We will use hasing for the optimal approach
int main()
{
    vector<int> arr={1,1,2,3,3,4,4};
    int n=arr.size();
    int maxi=arr[0];
    for(int i=0;i<n;i++)
    {
        maxi=max(maxi,arr[i]);
    }
    vector<int> hash(maxi,0);
    for(int i=0;i<n;i++)
    {
        hash[arr[i]]++;
    }
    for(int i=0;i<n;i++)
    {
        if(hash[arr[i]]==1)
        {
            cout<<arr[i]<<endl;
        }
    }
}
//Time complexity is O(N)
//Space complexity is O(maxi) i.e is the maximum element
//Hash array cannot be used everytime for very very large numbers
//We will use map data structure for that like map<long long,int>

//Optimal approach
int main()
{
    vector<int> arr={1,1,2,3,3,4,4};
    int n=arr.size();
    map<long long,int> mp;
    for(int i=0;i<n;i++)
    {
        mp[arr[i]]++;
    }
    for(auto it: mp)
    {
        if(it.second==1)
        {
            cout<<it.first<<endl;
        }
    }
}
//Ordered map will take O(nlogm)+O(n/2 + 1) m is the size of the map
//Unordered map will take O(n) for best case and O(n*n) for worst case
//Space complexity is O(n/2 + 1)

//Optimal solution
//We will use XOR property
int main()
{
    vector<int> arr={1,1,2,3,3,4,4};
    int XOR1=0;
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        XOR1=XOR1^arr[i];
    }
    cout<<XOR1<<endl;
}