#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
class SpecialStack {
    stack<pair<int,int>> st;

public:
    void push(int x)
    {
        if(st.empty())
        {
            st.push({x,x});
        }
        else{
            int currentMin=min(x,st.top().second);
            st.push({x,currentMin});
        }
    }
    int pop()
    {
        int data=st.top().first;
        st.pop();
        return data;
    }
    int peek()
    {
        return st.top().first;
    }
    bool isEmpty()
    {
        return st.empty();
    }
    int getMin()
    {
        return st.top().second;
    }
};
//We can take a pair<val,min> 
//Time complexity is O(1)
//Space complexity is O(2*N)
class SpecialStack {
    stack<int> st;
    int mini=INT_MAX;

public:
    void push(int x)
    {
        if(st.empty())
        {
            mini=x;
            st.push(x);
        }
        else{
           if(x>mini)
           {
            st.push(x);
           } 
           else{
            st.push(2*x-mini);
            mini=x;
           }
        }
    }
    int pop()
    {
        if(st.empty())
        {
            return -1;
        }
        int data=st.top();
        st.pop();
        if(data<mini)
        {
            mini=2*mini-data;
        }
        return data;
    }
    int peek()
    {
        if(st.empty())
        {
            return 0;
        }
        int data= st.top();
        if(mini<data)
        {
            return data;
        }
        return mini;
    }
    bool isEmpty()
    {
        return st.empty();
    }
    int getMin()
    {
        return mini;
    }
};
//Time complexity is O(1)
//Space complexity is O(N)