#include<iostream>
#include<vector>
#include<map>
using namespace std;
//Brute force approach
//We have assurance that n/2 numbers are positive and n/2 numbers are negative
int main()
{
    vector<int> arr={3,1,-2,-5,2,-4};
    int n=arr.size();
    vector<int> pos;
    vector<int> neg;
    //Positive numbers appear at even indices
    //Negative numbers appear at odd indices
    for(int i=0;i<n;i++)
    {
        if(arr[i]>=0)
        {
            pos.push_back(arr[i]);
        }
        else{
            neg.push_back(arr[i]);
        }
    }
    for(int i=0;i<n/2;i++)
    {
        arr[2*i]=pos[i];
        arr[2*i+1]=neg[i];
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
}
//Time complexity is O(N)+O(N)
//Space complexity is O(N) [Extra space being used to store the elements]

//Optimal approach
int main()
{
    vector<int> arr={3,1,-2,-5,2,-4};
    int n=arr.size();
    vector<int> ans(n,0);
    int posIndex=0,negIndex=1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<0)
        {
            ans[negIndex]=arr[i];
            negIndex+=2;
        }
        else{
            ans[posIndex]=arr[i];
            posIndex+=2;
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<endl;
    }
}