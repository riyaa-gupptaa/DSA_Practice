#include <iostream>
#include <string>
using namespace std;
//Either all letters are capital
//All letters are not capital
//Only first letter is capital
class Solution
{
public:
    bool allCapital(string word)
    {
        for(char &ch:word)
        {
            if(ch<'A'||ch>'Z')
            {
                return false;
            }
        }
        return true;
    }
    bool allSmall(string word)
    {
        for(char &ch:word)
        {
            if(ch<'a'||ch>'z')
            {
                return false;
            }
        }
        return true;
    }
    bool detectCapitalUse(string word)
    {
        if(allCapital(word)||allSmall(word)||allSmall(word.substr(1)))
        {
            return true;
        }
        return false;
    }
};
//Other Method
bool check(string word,char start,char end)
{
    for(char &ch:word)
    {
        if(ch<start||ch>end)
        {
            return false;
        }
    }
    return true;
}
bool detectCapitalUse(string word)
{
    if(check(word,'A','Z')||check(word,'a','z')||check(word.substr(1),'a','z'))
    {
        return true;
    }
    return false;
}

//Another Solution
bool detectCapitalUse(string word)
{
    int countCapitals=0;
    for(char &ch:word)
    {
        if(isupper(ch))
        {
            countCapitals++;
        }
    }
    if(countCapitals==0)
    {
        return true;
    }
    if(countCapitals==word.length())
    {
        return true;
    }
    return false;
}