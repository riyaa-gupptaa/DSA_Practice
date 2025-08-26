#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution
{
public:
    int areaOfMaxDiagonal(vector<vector<int>> &dimensions)
    {
        int n = dimensions.size();
        vector<long long> ans;
        for (int i = 0; i < n; i++)
        {
            long long mul = 1LL * dimensions[i][0] * dimensions[i][0] +
                            1LL * dimensions[i][1] * dimensions[i][1];
            ans.push_back(mul);
        }

        int maxi = 0;
        for (int i = 1; i < n; i++)
        {
            if (ans[i] > ans[maxi])
            {
                maxi = i;
            }
            else if (ans[i] ==
                     ans[maxi])
            {
                int areaCurr = dimensions[i][0] * dimensions[i][1];
                int areaBest = dimensions[maxi][0] * dimensions[maxi][1];
                if (areaCurr > areaBest)
                    maxi = i;
            }
        }
        int answer = 0;
        answer = dimensions[maxi][0] * dimensions[maxi][1];
        return answer;
    }
};