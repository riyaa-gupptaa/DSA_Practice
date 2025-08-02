#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
int findContentChildren(vector<int>& g, vector<int>& s)
{
    int n=g.size();
    int m=s.size();
    int l=0,r=0;
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());
    while(r<n && l<m)
    {
        if(g[r]<=s[l])
        {
            r=r+1;
        }
        l=l+1;
    }
    return r;
}
//Time complexity O(NlogN+MlogM+M)
//Space complexity is O(1)
