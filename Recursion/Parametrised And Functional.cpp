#include<iostream>
#include<vector>
using namespace std;
//Paramterised
void f(int i,int sum)
{
    if(i<1)
    {
        cout<<sum<<endl;
        return;
    }
    f(i-1,sum+i);
}
int main()
{
    int n;
    cin>>n;
    f(n,0);
}

//Functional Recursion
int f(int n)
{
    if(n==0)
    {
        return 0;
    }
    return n+f(n-1);
}
int main()
{
    int n;
    cin>>n;
    cout<<f(n)<<endl;
}
//Factorial of N
void f(int i,int fact)
{
    if(i<1)
    {
        cout<<fact<<endl;
        return;
    }
    f(i+1,fact*i);
}
//Functional
int fact(int n)
{
    if(n==0)
    {
        return 1;
    }
    return n*fact(n-1);
}