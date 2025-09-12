#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution {
public:
    bool doesAliceWin(string s) {
        const string Vowels="aeiou";
        for(char c:s)
        {
            if(Vowels.find(c)!=string::npos)
            {
                return true;
            }
        }
        return false;
    }
};