#include<iostream>
#include<vector>
#include<map>
using namespace std;
//Brute force approach
//The answer will always have 2 elements
vector<int> majorityElement(vector<int>& nums)
{
    int n=nums.size();
    vector<int> ls;
    int count;
    for(int i=0;i<n;i++)
    {
        if(ls.size()==0||ls[0]!=nums[i])
        {
            count=0;
            for(int j=0;j<n;j++)
            {
               if(nums[j]==nums[i])
               {
                count++;
               } 
            }
            if(count>n/3)
            {
                ls.push_back(nums[i]);
            }
        }
        if(ls.size()==2)
        {
            break;
        }
    }
    return ls;
}
//Time complexity is O(N*N)
//Space complexity is O(1)

//Hashing technique
//keep the number and the count
vector<int> majorityElement(vector<int>& nums)
{
    int n=nums.size();
    vector<int> ls;
    map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        mp[nums[i]]++;
    }
    for(auto it: mp)
    {
        if(it.second>n/3)
        {
            ls.push_back(it.first);
        }
    }
    return ls;
}
//Time complexity is O(NlogN)+O(N)
//Space complexity is O(n)

//Optimal approach
//Cancellation logic
vector<int> majorityElement(vector<int>& nums)
{
    int n=nums.size();
    vector<int> ls;
    int cnt1=0,cnt2=0;
    int el1=INT_MIN,el2=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(cnt1==0 && nums[i]!=el2)
        {
            cnt1=1;
            el1=nums[i];
        }
        else if(cnt2==0 && nums[i]!=el1)
        {
            cnt2=1;
            el2=nums[i];
        }
        else if(el1==nums[i])
        {
            cnt1++;
        }
        else if(el2==nums[i])
        {
            cnt2++;
        }
        else{
            cnt1--;
            cnt2--;
        }
    }
    cnt1=0;
    cnt2=0;
    for(int i=0;i<n;i++)
    {
        if(el1==nums[i])
        {
            cnt1++;
        }
        if(el2==nums[i])
        {
            cnt2++;
        }
    }
    int mini=(int)(n/3)+1;
    if(cnt1>=mini)
    {
        ls.push_back(el1);
    }
    if(cnt2>=mini)
    {
        ls.push_back(el2);
    }
    return ls;
}
//Time complexity is O(2N)
