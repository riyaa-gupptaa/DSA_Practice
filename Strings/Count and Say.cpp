#include<iostream>
#include<string>
#include<map>
using namespace std;
string countAndSay(int n)
{
    if(n==1)
    {
        return "1";
    }
    string say=countAndSay(n-1);
    //Processing
    string result="";
    for(int i=0;i<say.length();i++)
    {
        char ch=say[i];
        int count=0;
        while(i<say.length()-1 && say[i]==say[i+1])
        {
            count++;
            i++;
        }
        result+=to_string(count)+string(1,ch);
    }
    return result;
}