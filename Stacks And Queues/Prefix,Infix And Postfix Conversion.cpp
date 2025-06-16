#include <iostream>
using namespace std;
#include <stack>
int priority(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '/' || c == '*')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
string infixToPostfix(string s)
{
    int i = 0;
    stack<char> st;
    string ans = "";
    int n = s.length();
    while (i < n)
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
        {
            ans = ans + s[i];
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && priority(s[i]) <= priority(st.top()))
            {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    return ans;
}
// Time complexity is O(n)+O(n)
// Space complexity is O(n)

// Infix to Prefix Conversion
// 1.Reverse the infix
// 2.Infix To postfix
// 3.Reverse that answer
string infixToPrefix(string s)
{
    reverse(s.begin(), s.end());
    int i = 0;
    stack<char> st;
    string ans = "";
    while (i < s.length())
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
        {
            ans += s[i];
        }
        else if (s[i] == '(')
        {
            ans += s[i];
        }
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            if (s[i] == '^')
            {
                while (!st.empty() && priority(s[i]) <= priority(st.top()))
                {
                    ans += st.top();
                    st.pop();
                }
            }
            else
            {
                while (!st.empty() && priority(s[i]) < priority(st.top()))
                {
                    ans += st.top();
                    st.pop();
                }
            }
            st.push(s[i]);
        }
        i++;
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// Time complexity is O(3N)
// Space complexity is O(N)

// Postfix to Infix Conversion
string PostfixtoInfix(string s)
{
    int i = 0;
    stack<string> st;
    while (i < s.length())
    {
        if (isalnum(s[i])) // Operand
        {
            st.push(string(1, s[i]));
        }
        else // Operator
        {
            string op1 = st.top();
            st.pop(); // Right operand
            string op2 = st.top();
            st.pop(); // Left operand
            string expr = "(" + op2 + s[i] + op1 + ")";
            st.push(expr);
        }
        i++;
    }
    return st.top();
}

//Time complexity is  O(N)+O(N)
//Space complexity is O(N)

//Prefix to infix expression
string preToInfix(string pre_exp)
{
    int n=pre_exp.length();
    int i=n-1;
    stack<string> st;
    while(i>=0)
    {
        if(isalnum(pre_exp[i]))
        {
            st.push(string(1,pre_exp[i]));
        }
        else{
            string t1=st.top();
            st.pop();
            string t2=st.top();
            st.pop();
            string exp='('+t2+pre_exp[i]+t1+')';
            st.push(exp);
        }
        i--;
    }
    return st.top();
}
//Time complexity is O(N)+O(N)
//Space complexity is O(N)

//Postfix to Prefix
string postToPre(string post_exp)
{
    int i=0;
    stack<string> st;
    while(i<post_exp.length())
    {
        if(isalnum(post_exp[i]))
        {
            st.push(string(1,post_exp[i]));
        }
        else{
            string t1=st.top();
            st.pop();
            string t2=st.top();
            st.pop();
            string exp=post_exp[i]+t2+t1;
            st.push(exp);
        }
        i++;
    }
    return st.top();
}
//Time complexity is O(N)
//Space complexity is O(N)

//Prefix to Postfix Conversion
string preToPost(string pre_exp)
{
    int n=pre_exp.length();
    int i=n-1;
    stack<string> st;
    while(i>=0)
    {
        if(isalnum(pre_exp[i]))
        {
            st.push(string(1,pre_exp[i]));
        }
        else{
            string t1=st.top();
            st.pop();
            string t2=st.top();
            st.pop();
            string expr=t1+t2+pre_exp[i];
            st.push(expr);
        }
        i--;
    }
    return st.top();
}
//Time complexity is O(n)+O(n)
//Space complexity is O(n)