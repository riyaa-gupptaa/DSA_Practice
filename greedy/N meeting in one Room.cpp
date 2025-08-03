#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
struct Data
{
    int st, en, pos;
};
bool comp(Data val1, Data val2)
{
    return val1.en < val2.en;
}
int maxMeetings(vector<int> &start, vector<int> &end)
{
    int n = start.size();
    vector<Data> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i].st = start[i];
        arr[i].en = end[i];
        arr[i].pos = i + 1;
    }
    sort(arr.begin(), arr.end(), comp);
    int cnt = 1;
    int freetime = arr[0].en;
    for (int i = 1; i < n; i++)
    {
        if (arr[i].st > freetime)
        {
            cnt = cnt + 1;
            freetime = arr[i].en;
        }
    }
    return cnt;
}

// If you want to store meeting positions as well
int maxMeetings(vector<int> &start, vector<int> &end, vector<int> &meetingOrder)
{
    int n = start.size();
    vector<Data> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i].st = start[i];
        arr[i].en = end[i];
        arr[i].pos = i + 1;
    }

    sort(arr.begin(), arr.end(), comp);

    int cnt = 1;
    int freetime = arr[0].en;
    meetingOrder.push_back(arr[0].pos);

    for (int i = 1; i < n; i++)
    {
        if (arr[i].st > freetime)
        {
            cnt++;
            freetime = arr[i].en;
            meetingOrder.push_back(arr[i].pos);
        }
    }

    return cnt;
}
//TC-O(2N+NlogN)
//Space complexity is O(3*N)+O(N)