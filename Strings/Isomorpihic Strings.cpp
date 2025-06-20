#include<iostream>
#include<string> 
#include<vector>
using namespace std;
bool isIsomorphic(string s,string t)
{
    int len=s.size();
    char seen[128]={};
    for(int i=0;i<len;i++)
    {
        char c=s[i];
        if(!seen[c])
        {
            for(char s: seen)
            {
                if(s=t[i])
                {
                    return false;
                }
            }
            seen[c]=t[i];
        }
        else if(seen[c]!=t[i])
        {
            return false;
        }
    }
    return true;
}

//Another approach
bool isIsomorphic(string s,string t)
{
    if(s.length()!=t.length())
    {
        return false;
    }
    char map_s[128]={0};
    char map_T[128]={0};
    int len=s.size();
    for(int i=0;i<len;++i)
    {
        if(map_s[s[i]]!=map_T[t[i]])
        {
            return false;
        }
        map_s[s[i]]=i+1;
        map_T[t[i]]=i+1;
    }
  return true; 
}
//Time complexity is O(N)
//Space complexity is O(1)