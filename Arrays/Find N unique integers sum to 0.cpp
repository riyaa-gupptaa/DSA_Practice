#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            ans[i]=i*2-n+1;
        } 
        return ans;
    }
};