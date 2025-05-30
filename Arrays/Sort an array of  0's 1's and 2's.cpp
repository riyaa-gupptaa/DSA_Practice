#include<iostream>
#include<vector>
#include<map>
using namespace std;
//Brute force approach
//Use any sorting algorithm like merge sort
//Time complexity will be O(NlogN)
//Space complexity is O(N)[Extra space]

//Better approach
int main()
{
    vector<int> arr={0,1,2,0,1,2,1,2,0,0,0,1};
    int n=arr.size();
    int cnt1=0;
    int cnt2=0;
    int cnt3=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
        {
            cnt1++;
        }
        else if(arr[i]==1)
        {
            cnt2++;
        }
        else{
            cnt3++;
        }
    }
    for(int i=0;i<cnt1;i++)
    {
        arr[i]=0;
    }
    for(int i=cnt1;i<cnt1+cnt2;i++)
    {
        arr[i]=1;
    }
    for(int i=cnt1+cnt2;i<n;i++)
    {
        arr[i]=2;
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
}
//Time complexity is O(2N)
//Space complexity is O(1)

//Dutch National flag algorithm
//Optimal approach
int main()
{
    vector<int> arr={0,1,1,0,1,2,1,2,0,0,0};
    int n=arr.size();
    int low=0,mid=0,high=n-1;
    while(mid<=high)
    {
        if(arr[mid]==0)
        {
            swap(arr[mid],arr[low]);
            low++;
            mid++;
        }
        else if(arr[mid]==1)
        {
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
}
//Time complexity is O(N);
//Space complexity is O(1);