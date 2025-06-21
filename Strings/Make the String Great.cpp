#include <iostream>
#include <string>
#include <vector>
using namespace std;
//We have to check if we are having a lower case and a upper case letter adjacent to each other
class Solution
{
public:
    string makeGood(string s)
    {
        int n=s.length();
        string result="";
        for(int i=0;i<n;i++)
        {
            if(!result.empty() && (result.back()-32==s[i]||result.back()+32==s[i]))
            {
                result.pop_back();
            }
            else{
            result.push_back(s[i]);
            }
        }
        return result;
    }
};