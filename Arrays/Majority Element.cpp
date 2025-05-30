#include<iostream>
#include<vector>
#include<map>
using namespace std;
//Brute force approach
//Majority element is (>N/2 times)
int main()
{
    vector<int> arr={2,2,3,3,1,2,2};
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
       int count=0;
       for(int j=0;j<n;j++)
       {
        if(arr[j]==arr[i])
        {
            count++;
        }
       } 
       if(count>n/2)
       {
        cout<<arr[i]<<endl;
        break;
       }
    }
}
//Time complexity is O(N*N)
//Space complexity is O(1)

//Better approach
//We can use hashing
int majorityElement(vector<int> v)
{
    map<int,int> mp;
    for(int i=0;i<v.size();i++)
    {
        mp[v[i]]++;
    }
    for(auto it:mp)
    {
        if(it.second>(v.size()/2))
        {
            return it.first;
        }
    }
    return -1;
}
//Time complexity is O(NlogN)+O(N)
//Space complexity is O(N) [Unique elements]

//Optimal Solution
//Moore's voting algorithm

int majorityElement(vector<int> v)
{
    int cnt=0;
    int el;
    for(int i=0;i<v.size();i++)
    {
        if(cnt==0)
        {
            cnt=1;
            el=v[i];
        }
        else if(v[i]==el)
        {
            cnt++;
        }
        else{
            cnt--;
        }
    }
    int cnt1=0;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==el)
        {
            cnt++;
        }
    }
    if(cnt1>(v.size()/2))
    {
        return el;
    }
    return -1;
}
//Time complexity is O(N)
//Space complexity is O(1)