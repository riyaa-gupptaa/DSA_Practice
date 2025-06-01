#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<unordered_set>
using namespace std;
//Brute force approach
bool linearSearch(vector<int> &arr,int num)
{
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        if(arr[i]==num)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    vector<int> arr={102,4,100,1,101,3,2,1};
    int n=arr.size();
    // Let's arrange the array the lonfest consecutive sequence can be 1,2,3,4 with a length of 4
    int longest=1;
    int count;
    for(int i=0;i<n;i++)
    {
        int x=arr[i];
        count=1;
        while(linearSearch(arr,x+1)==true)
        {
            x=x+1;
            count=count+1;
        }
    }
    cout<<count<<endl;
}
//Time complexity is O(N*N)
//Space complexity is O(1)

//Better approach
int longestConsecutive(vector<int> &nums)
{
    int n=nums.size();
    if(n==0)
    {
        return 0;
    }
    sort(nums.begin(),nums.end());
    int longest=1;
    int lastSmaller=INT_MIN;
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(nums[i]-1==lastSmaller)
        {
            count=count+1;
            lastSmaller=nums[i];
        }
        else if(nums[i]!=lastSmaller)
        {
            count=1;
            lastSmaller=nums[i];
        }
        longest=max(longest,count);
    }
    return longest;
}

//Optimal solution
//Using set data structure
int longestConsecutive(vector<int> &nums)
{
    int n=nums.size();
    if(n==0)
    {
        return 0;
    }
    int longest=1;
    unordered_set<int> st;
    for(int i=0;i<n;i++)
    {
        st.insert(nums[i]);
    }
    for(auto it:st)
    {
        if(st.find(it-1)==st.end())
        {
            int count=1;
            int x=it;
            while(st.find(x+1)!=st.end())
            {
                x=x+1;
                count=count+1;
            }
            longest=max(longest,count);
        }
    }
    return longest;
}
//Time complexity is O(N)+O(2N)
//Space complexity of O(N)