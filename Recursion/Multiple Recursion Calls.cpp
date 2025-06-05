#include<iostream>
#include<vector>
using namespace std;
//Fibonacci Series
int f(int n)
{
    if(n<=1)
    {
        return n;
    }
    int last=f(n-1);
    int slast=f(n-2);
    return last+slast;
}
int main()
{
    int n;
    cin>>n;
    cout<<f(n)<<endl;
}
//Time complexity is O(2^n)