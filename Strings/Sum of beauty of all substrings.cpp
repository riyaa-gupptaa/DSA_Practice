#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    int beautySum(string s)
    {
        int n=s.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            int freq[26]={0};
            for(int j=i;j<n;j++)
            {
                freq[s[j]-'a']++;
                int maxi=INT_MIN;
                int mini=INT_MAX;
                for(int i=0;i<26;i++)
                {
                    if(freq[i]>0)
                    {
                        maxi=max(maxi,freq[i]);
                        mini=min(mini,freq[i]);
                    }
                }
                sum=sum+(maxi-mini);
            }
        }
        return sum;
    }
};