#include <iostream>
#include <string>
#include <map>
using namespace std;
#include <sstream>
class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        istringstream iss(s);
        string word;
        unordered_map<char, string> charToword;
        unordered_map<string, char> wordTochar;
        int i = 0;
        while (iss >> word)
        {
            if (i >= pattern.size())
            {
                return false;
            }
            char c = pattern[i];
            if (charToword.count(c) && charToword[c] != word)
            {
                return false;
            }
            if (wordTochar.count(word) && wordTochar[word] != c)
            {
                return false;
            }
            charToword[c] = word;
            wordTochar[word] = c;
            i++;
        }
        return i == pattern.size();
    }
};