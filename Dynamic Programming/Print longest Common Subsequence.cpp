#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
string findLCS(int n, int m,string &text1, string &text2)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int len=dp[n][m];
    string ans="";
    for(int i=0;i<len;i++)
    {
        ans+='$';
    }
    int index=len-1;
    int i=n,j=m;
    while(i>0 && j>0)
    {
        if(text1[i-1]==text2[j-1])
        {
            ans[index]=text1[i-1];
            index--;
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
        {
            i--;
        }
        else{
            j--;
        }
    }
    return ans;
}
//Time complexity is O(N+M)-at worst case
