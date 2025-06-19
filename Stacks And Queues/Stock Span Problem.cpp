#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class StockSpanner
{
public:
    StockSpanner()
    {

    }
    vector<int> arr;
    int next(int price)
    {
        arr.push_back(price);
        int cnt=1;
        for(int i=arr.size()-2;i>=0;i--)
        {
            if(arr[i]<=price)
            {
                cnt++;
            }
            else{
                break;
            }
        }
        return cnt;
    }
};
//Time complexity is O(No.Of days)
//Space complexity s O(total number of recent calls)

//Optimised Solution
//Current Index-(Index of)(Previous Greater element)=Consecutive days
vector<int> findPGE(vector<int> &arr)
{
    int n=arr.size();
    stack<int> st;
    vector<int> pge(n);
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && arr[st.top()]<=arr[i])
        {
            st.pop();
        }
        pge[i]=st.empty()?-1:st.top();
        st.push(i);
    }
    return pge;
}
class StockSpanner{
    public:
    vector<int> arr;
    StockSpanner()
    {

    }
    int next(int price)
    {
        arr.push_back(price);
        int n=arr.size();
        vector<int> pge=findPGE(arr);
        int cnt=n-1-pge[n-1];
        return cnt;
    }
};
//Time limit exceeded

class StockSpanner{
    stack<pair<int,int>> st;
    int ind=-1;
    StockSpanner()
    {
        ind=-1;
        while(!st.empty())
        {
            st.pop();
        }
    }
    int next(int price)
    {
        ind=ind+1;
        while(!st.empty() && st.top().first<=price)
        {
            st.pop();
        }
        int ans=ind-(st.empty()?-1:st.top().second);
        st.push({price,ind});
        return ans;
    }
};
//Time complexity is O(2N)
//Space complexity is O(N)