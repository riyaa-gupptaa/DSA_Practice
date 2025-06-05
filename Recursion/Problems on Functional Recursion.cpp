#include<iostream>
#include<vector>
using namespace std;
void f(vector<int>&arr,int l,int r)
{
    swap(arr[l],arr[r]);
    f(arr,l+1,r-1);
}
int main()
{
    vector<int> arr={1,2,3,4,5};
    int l=0;
    int r=arr.size()-1;
    f(arr,l,r);
}
void reverse(vector<int> arr,int i,int n)
{
    if(i>=n/2)
    {
        return;
    }
    swap(arr[i],arr[n-i-1]);
    reverse(i+1,n);
}
int main()
{
    vector<int> arr={1,2,3,4,5};
    int n=arr.size();
    reverse(arr,0,n);
}
//Check if a string is palindrome
bool f(int i,string &s)
{
    if(i>=s.size()/2)
    {
        return true;
    }
    if(s[i]!=s[s.size()-i-1])
    {
        return false;
    }
    return f(i+1,s);
}
int main()
{
    string s="madam";
    cout<<f(0,s)<<endl;
}