#include <iostream>
using namespace std;
#include <stack>
bool isBalanced(const string &s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else
        {
            if (!st.empty() &&
                    ((st.top() == '(' && s[i] == ')') ||
                (st.top() == '[' && s[i] == ']') ||
                (st.top() == '{' && s[i] == '}')))
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }
    return st.empty();
}
//Time complexity is O(N)
//Space complexity is O(N)