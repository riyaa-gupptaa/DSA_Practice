#include <iostream>
#include <string>
#include <vector>
using namespace std;
//The characters in word1 should also be present in word2
//frequency should be same without bothering about the characters
//Sort frequence 1 and sort frequency 2
class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        int m=word1.length();
        int n=word2.length();
        if(m!=n)
        {
            return false;
        }
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        for(int i=0;i<m;i++)
        {
            char ch=word1[i];
            int idx=ch-'a';
            freq1[idx]++;
            char ch2=word2[i];
            int idx2=ch2-'a';
            freq2[idx2]++;
        }
        //1st point- Jo char word1 mein hai woh char 2 mein bhi hona chahiye
        for(int i=0;i<26;i++)
        {
            if(freq1[i]!=0 && freq2[i]!=0)
            {
                continue;
            }
            if(freq1[i]==0 && freq2[i]==0)
            {
                continue;
            }
            return false;
        }
        //2nd point
        sort(freq1.begin(),freq1.end());
        sort(freq2.begin(),freq2.end());
        return freq1==freq2;
    }
};