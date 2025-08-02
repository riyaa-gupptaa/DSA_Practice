#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit)
{
    int n = deadline.size();
    vector<int> ans = {0, 0};
    vector<pair<int, int>> jobs;
    for (int i = 0; i < n; i++)
    {
        jobs.push_back({deadline[i], profit[i]});
    }
    sort(jobs.begin(), jobs.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    for (const auto job : jobs)
    {
        if (job.first > pq.size())
        {
            pq.push(job.second);
        }
        else if (!pq.empty() && pq.top() < job.second)
        {
            pq.pop();
            pq.push(job.second);
        }
    }
    while (!pq.empty())
    {
        ans[1] += pq.top();
        pq.pop();
        ans[0]++;
    }
    return ans;
}

// Alternative Approach
vector<int> jobSequencing(vector<int> &deadline,
                          vector<int> &profit)
{
    int n=deadline.size();
    int cnt=0;
    int totProfit=0;
    vector<pair<int,int>> jobs;
    for(int i=0;i<n;i++)
    {
        jobs.push_back({profit[i],deadline[i]});
    }
    sort(jobs.begin(),jobs.end(),greater<pair<int,int>>());
    vector<int> slot(n,0);
    for(int i=0;i<n;i++)
    {
        int start=min(n,jobs[i].second)-1;
        for(int j=start;j>=0;j--)
        {
            if(slot[j]==0)
            {
                slot[j]=1;
                cnt++;
                totProfit+=jobs[i].first;
                break;
            }
        }
    }
    return {cnt,totProfit};
}