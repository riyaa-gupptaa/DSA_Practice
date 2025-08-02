#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
//Scheduling policy that selects the waiting process
//with the smallest execution time to excecute next.
long long solve(vector<int>& bt)
{
    int n=bt.size();
    sort(bt.begin(),bt.end());
    int t=0,wttime=0;
    for(int i=0;i<n;i++)
    {
        wttime+=t;
        t +=bt[i];
    }
    return (wttime/n);
}
//Time complexity is O(N)+O(NlogN)
//Space complexity is O(1)