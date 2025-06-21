#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    int maxDepth(string s)
    {
        int res=0,curr=0;
        for(char& c:s)
        {
            if(c=='(')
            {
                res=max(res,++curr);
            }
            if(c==')')
            {
                curr--;
            }
        }
        return res;
    }
};
//Time complexity is O(N)
//Space complexity is O(1)