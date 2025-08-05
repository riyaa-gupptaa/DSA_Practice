#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
bool comp(pair<int, int> &a, pair<int, int> &b)
{
    double r1 = (double)a.first / a.second;
    double r2 = (double)b.first / b.second;
    return r1 > r2;
}
double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity)
{
    int n = val.size();
    vector<pair<int, int>> items;

    for (int i = 0; i < n; i++)
    {
        items.push_back({val[i], wt[i]});
    }

    sort(items.begin(), items.end(), comp);

    double totVal = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (items[i].second <= capacity)
        {
            totVal += items[i].first;
            capacity -= items[i].second;
        }
        else
        {
            totVal += ((double)items[i].first / items[i].second) * capacity;
            break;
        }
    }

    return totVal;
}
//Time complexity is O(N+NlogN)
//Space complexity is O(1)