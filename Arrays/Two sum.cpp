#include<iostream>
#include<vector>
#include<map>
using namespace std;
//Brute force approach
int main()
{
    vector<int> arr={2,6,5,8,11};
    int n=arr.size();
    int k=14;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
                continue;
            }
            if(arr[i]+arr[j]==k)
            {
                cout<<i<<endl;
                cout<<j<<endl;
                break;
            }
        }
    }
}
//Time complexity is O(N^2)

//Better Approach
int main()
{
    vector<int> arr={2,6,5,8,11};
    int n=arr.size();
    int k=14;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]+arr[j]==k)
            {
                cout<<i<<endl;
                cout<<j<<endl;
                break;
            }
        }
    }
}
//A slightly better approach nearly about O(N*N)

//We can use Hash map
string read(int n,vector<int> book,int target)
{
    map<int,int> mpp;
    for(int i=0;i<n;i++)
    {
        int a=book[i];
        int more=target-a;
        if(mpp.find(more)!=mpp.end())
        {
            return "YES"; //return (mpp[more],i);
        }
        mpp[a]=i;
    }
    return "NO";
}
//Time complexity is O(N*LogN)
//Unordered map for O(N) or O(N^2) in worst case
//Space complexity is O(N)

//Optimal approach
//2 pointer approach
string read(int n,vector<int> book,int target)
{
    int left=0;
    int right=n-1;
    sort(book.begin(),book.end());
    while(left<right)
    {
        int sum=book[left]+book[right];
        if(sum==target)
        {
            return "YES";
        }
        else if(sum>target)
        {
            left++;
        }
        else{
            right--;
        }
    }
    return "NO";
}
//Time complexity is O(N)+O(NlogN)
//Space complexity is O(1)