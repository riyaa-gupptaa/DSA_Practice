#include<iostream>
#include<vector>
#include<map>
using namespace std;
//Print Name  N times using Recursion
void f(int i,int n)
{
    if(i>n)//Base condition
    {
        return;
    }
    cout<<"Raj"<<endl;
    f(i+1,n);
}
int main()
{
    int n;
    cin>>n;
    f(1,n);
}
//Time complexity is O(N)

//Print 1-N
void f(int i,int n)
{
    if(i>n)//Base condition
    {
        return;
    }
    cout<<i<<endl;
    f(i+1,n);
}

//Print in terms of N->1
void f(int i,int n)
{
    if(i<1)//Base condition
    {
        return;
    }
    cout<<i<<endl;
    f(i-1,n);
}
int main()
{
    int n;
    cin>>n;
    f(n,n);
}
//Print linearly from 1 to N (Backtracking)
void f(int i,int n)
{
    if(i<1)
    {
        return;
    }
    f(i-1,n);
    cout<<i<<endl;
}
int main()
{
    int n;
    cin>>n;
    f(n,n);
}

//Print from N to 1(Backtracking)
void f(int i,int n)
{
    if(i>n)
    {
        return;
    }
    f(i+1,n);
    cout<<i<<endl;
}
