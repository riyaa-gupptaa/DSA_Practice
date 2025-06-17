#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> asteroidCollision(vector<int> &asteroids)
{
    int n = asteroids.size();
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (asteroids[i] >= 0)
        {
            st.push(asteroids[i]);
        }
        else
        {
            while (!st.empty() && st.top() > 0 && st.top() < abs(asteroids[i]))
            {
                st.pop();
            }
            if (!st.empty() && st.top() == abs(asteroids[i]))
            {
                st.pop();
            }
            else if (st.empty() || st.top() < 0)
            {
                st.push(asteroids[i]);
            }
        }
    }
    vector<int> list1(st.size());
    for (int i = st.size() - 1; i >= 0; i--)
    {
        list1[i] = st.top();
        st.pop();
    }
    return list1;
}
//Time complexity is O(N)
//Space complexity is O(N)