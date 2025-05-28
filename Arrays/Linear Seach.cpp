#include<iostream>
using namespace std;
int main()
{
    vector<int> arr={6,7,8,4,1};
    int n=arr.size();
    int num=7;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==num)
        {
            cout<<i<<endl;//First occurence of the number
        }
    }
    cout<<"No such number exists in the array"<<endl;
    return 0;
}