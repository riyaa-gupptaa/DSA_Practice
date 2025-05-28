#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> arr={1,0,2,3,2,0,0,4,5,1};
    vector<int> temp;
    int n=arr.size();
    for(int i=0;i<n;i++)//time complexity is O(N)
    {
        if(arr[i]!=0)
        {
            temp.push_back(arr[i]);
        }
    }
    for(int i=0;i<temp.size();i++)//Time complexity is O(x)
    {
        arr[i]=temp[i];
    }
    int nz=temp.size();//Index from which you need to fill zeroes
    for(int i=nz;i<n;i++)//Time complexity is O(N-x)
    {
        arr[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}
//Time complexity is O(2N)
//Space complexity is O(x)-No of non zeroes element

//Optimal solution
int main()
{
    vector<int> arr={1,0,2,3,2,0,0,4,5,1};
    //Step1 is to find the first zero element
    int j=-1;
    int n=arr.size();
    for(int i=0;i<n;i++)//Time complexity is O(N)
    {
        if(arr[i]==0)
        {
            j=i;
            break;
        }
    }
    if(j==-1)
    {
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<endl;
        }
    }
    for(int i=j+1;i<n;i++)//Time complexity is O(N-x)
    {
        if(arr[i]!=0)
        {
            swap(arr[i],arr[j]);
            j++;
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
}
//A more cleaner and efficient approach
void moveZeroes(vector<int> &nums)
{
    int j=0;
    for(int i=j+1;i<nums.size();i++)
    {
        if(nums[i]!=0)
        {
            swap(nums[i],nums[j]);
            j++;
        }
    }
}