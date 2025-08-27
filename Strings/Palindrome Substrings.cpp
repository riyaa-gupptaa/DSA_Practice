#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution
{
public:
    bool isPalindrome(string s)
    {
        int l = 0;
        int r = s.size() - 1;
        while (l < r)
        {
            if (s[l++] != s[r--])
            {
                return false;
            }
        }
        return true;
    }
    vector<string> generate(string &s)
    {
        vector<string> substrings;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                substrings.push_back(s.substr(i, j - i + 1));
            }
        }
        return substrings;
    }
    int countSubstrings(string s)
    {
        vector<string> subStrings = generate(s);
        int count = 0;
        for (auto &a : subStrings)
        {
            if (isPalindrome(a))
            {
                count++;
            }
        }
        return count;
    }
};