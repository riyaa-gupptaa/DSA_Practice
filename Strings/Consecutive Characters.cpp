#include<iostream>
#include<string>
#include<vector>
using namespace std;
int maxPower(string s)
{
    int n=s.length();
    int maxi=0;
    int count=0;
    for(int i=0;i<n;i++)
    {
        count=1;
        for(int j=i+1;j<n;j++)
        {
            if(s[i]!=s[j])
            {
                break;
            }
            else{
                count++;
            }
        }
        maxi=max(maxi,count);
    }
    return maxi;
}