#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
// It should have an opening as well as a closing parethesis
// We have to change the * to something to make the parenthesis valid
bool f(string s, int ind, int cnt)
{
    if (cnt < 0)
    {
        return false;
    }
    int n = s.size();
    if (ind == n)
    {
        return (cnt == 0);
    }
    if (s[ind] == '(')
    {
        return f(s, ind + 1, cnt + 1);
    }
    if (s[ind] == ')')
    {
        return f(s, ind + 1, cnt - 1);
    }
    return f(s, ind + 1, cnt + 1) or f(s, ind + 1, cnt - 1) or f(s, ind + 1, cnt);
}
bool checkValidString(string s)
{
    int n = s.size();
    return f(s, 0, 0);
}
// Time complexity is O(3^N)
// Space complexity is O(N)

// Greedy
bool checkValidString(string s)
{
    int n = s.size();
    int mini = 0;
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            mini = mini + 1;
            maxi = maxi + 1;
        }
        else if (s[i] == ')')
        {
            mini = mini - 1;
            maxi = maxi - 1;
        }
        else
        {
            mini = mini - 1;
            maxi = maxi + 1;
        }
        if (mini < 0)
        {
            mini = 0;
        }
        if (maxi < 0)
        {
            return false;
        }
    }
    return (mini == 0);
}
// Time complexity is O(N)
// Space complexity is O(1)