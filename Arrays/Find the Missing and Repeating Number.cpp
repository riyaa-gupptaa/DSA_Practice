#include<iostream>
#include<vector>
#include<map>
using namespace std;
//Brute force approach
vector<int> findTwoElement(vector<int>& arr)
{
    int n=arr.size();
    int repeating =-1;
    int missing=-1;
    for(int i=1;i<=n;i++)
    {
        int count=0;
        for(int j=0;j<n;j++)
        {
            if(arr[j]==i)
            {
                count++;
            }
        }
        if(count==2)
        {
            repeating=i;
        }
        else if(count==0)
        {
            missing=i;
        }
    }
    return {missing,repeating};
}
//Time complexity is O(N*N)
//Space complexity is O(1)

//Better approach includes Hashing
//We can use hash array
vector<int> findTwoElement(vector<int>& arr)
{
    int n=arr.size();
    vector<int> hash(n+1,0);
    for(int i=0;i<n;i++)
    {
        hash[arr[i]]++;
    }
    int repeating=-1,missing=-1;
    for(int i=0;i<n;i++)
    {
        if(hash[i]==2)
        {
            repeating=i;
        }
        else if(hash[i]==0)
        {
            missing=i;
        }
        if(repeating!=-1 && missing!=-1)
        {
            break;
        }
    }
    return {repeating,missing};
}
//Time complexity is O(2N)
//Space complexity is O(N)

//Optimal solution
//Basic mathematics or XOR Method
vector<int> findTwoElement(vector<int>& arr)
{
    long long n=arr.size();
    //S-Sn
    //S2-S2N
    long long SN=(n*(n+1))/2;
    long long S2N=(n*(n+1)*(2*n+1))/6;
    long long S=0,S2=0;
    for(int i=0;i<n;i++)
    {
        S+=arr[i];
        S2+=(long long)arr[i]+(long long)arr[i];
    }
    long long val1=S-SN;//x-y
    long long val2=S2-S2N;
    val2=val2/val1;//x+y
    long long x=(val1+val2)/2; // X is repeating number
    long long y=x-val1; // Y is the missing number
    return {(int)x,(int)y};
}
//Time complexity is O(N)
//Space complexity is O(1)

//Using XOR Operation
//(arr[i])^(1^2^....^n)=num
//find a difference in num; find the first one from the right
//Put them into two parts & XOR
vector<int> findTwoElement(vector<int>& arr)
{
    long long n=arr.size();
    int xr=0;
    for(int i=0;i<n;i++)
    {
        xr=xr^arr[i];
        xr=xr^(i+1);
    }
    int bitNo=0;
    while(1)
    {
        if((xr & (1<<bitNo)!=0))
        {
            break;
        }
        bitNo++;
    }
    int zero=0;
    int one=0;
    for(int i=0;i<n;i++)
    {
        //part of 1 club
        if((arr[i] & (1<bitNo))!=0)
        {
            one=one^arr[i];
        }
        //zeroth club
        else{
            zero=zero^arr[i];
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==zero)
        {
            cnt++;
        }
    }
    if(cnt==2)
    {
        return {zero,one};
    }
    return {one,zero};
}