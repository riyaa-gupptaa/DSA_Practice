#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
    vector<int> leftSmaller(vector<int> arr)
    {
        int n=arr.size();
        vector<int> list1(n,-1);
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty()&& st.top()>=arr[i])
            {
                st.pop();
            }
            list1[i]=st.empty()?-1:st.top();
            st.push(arr[i]);
        }
        return list1;
    }
};
//Time complexity is O(2N)
//Space complexity is O(N)+O(N)