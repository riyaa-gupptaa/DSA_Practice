#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
// or->|
//&->and
// XOR->^
long long f(int i, int j, int isTrue, string &exp)
{
    long long MOD = 1e9;
    if (i > j)
    {
        return 0;
    }
    if (i == j)
    {
        if (isTrue)
        {
            return exp[i] == 'T';
        }
        else
            return exp[i] == 'F';
    }
    long long ways = 0;
    for (int ind = i + 1; ind <= j - 1; ind += 2)
    {
        long long lT = f(i, ind - 1, 1, exp);
        long long lF = f(i, ind - 1, 0, exp);
        long long rT = f(ind + 1, j, 1, exp);
        long long rF = f(ind + 1, j, 0, exp);
        if (exp[ind] == '&')
        {
            if (isTrue)
            {
                ways = (ways + (rT * lT) % MOD) % MOD;
            }
            else
            {
                ways = (ways + (rT * lF) % MOD + (rF & lT) % MOD + (rF & lF) % MOD) % MOD;
            }
        }
        else if (exp[ind] == '|')
        {
            if (isTrue)
            {
                ways = (ways + (lT * rT) % MOD + (lT * rF) % MOD + (lF * rT) % MOD) % MOD;
            }
            else
            {
                ways = (ways + (rF * lF) % MOD) % MOD;
            }
        }
        else
        {
            if (isTrue)
            {
                ways = (ways + (lT * rF) % MOD + (lF * rT) % MOD) % MOD;
            }
            else
            {
                ways = (ways + (lT * rT) % MOD + (lF * rF) % MOD) % MOD;
            }
        }
    }
    return ways;
}
int parseBoolExpr(string expression)
{
    return f(0, expression.size() - 1, 1, expression);
}

// Exponential time complexity

// Memoization
long long f(int i, int j, int isTrue, string &exp, vector<vector<vector<long long>>> &dp)
{
    long long MOD = 1e9;
    if (i > j)
    {
        return 0;
    }
    if (i == j)
    {
        if (isTrue)
        {
            return exp[i] == 'T';
        }
        else
            return exp[i] == 'F';
    }
    if (dp[i][j][isTrue] != -1)
    {
        return dp[i][j][isTrue];
    }
    long long ways = 0;
    for (int ind = i + 1; ind <= j - 1; ind += 2)
    {
        long long lT = f(i, ind - 1, 1, exp, dp);
        long long lF = f(i, ind - 1, 0, exp, dp);
        long long rT = f(ind + 1, j, 1, exp, dp);
        long long rF = f(ind + 1, j, 0, exp, dp);
        if (exp[ind] == '&')
        {
            if (isTrue)
            {
                ways = (ways + (rT * lT) % MOD) % MOD;
            }
            else
            {
                ways = (ways + (rT * lF) % MOD + (rF * lT) % MOD + (rF * lF) % MOD) % MOD;
            }
        }
        else if (exp[ind] == '|')
        {
            if (isTrue)
            {
                ways = (ways + (lT * rT) % MOD + (lT * rF) % MOD + (lF * rT) % MOD) % MOD;
            }
            else
            {
                ways = (ways + (rF * lF) % MOD) % MOD;
            }
        }
        else
        {
            if (isTrue)
            {
                ways = (ways + (lT * rF) % MOD + (lF * rT) % MOD) % MOD;
            }
            else
            {
                ways = (ways + (lT * rT) % MOD + (lF * rF) % MOD) % MOD;
            }
        }
    }
    return dp[i][j][isTrue] = ways;
}
int parseBoolExpr(string expression)
{
    int n = expression.size();
    vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(2, -1)));
    return f(0, expression.size() - 1, 1, expression, dp);
}

//Tabulation
int mod = 1e9 + 7;
#define ll long long
int evaluateExp(string &exp)
{
    int n = exp.length();
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, 0)));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            for (int isTrue = 0; isTrue < 2; isTrue++)
            {
                if (i > j)
                    continue;
                if (i == j)
                {
                    if (isTrue)
                        dp[i][j][isTrue] = exp[i] == 'T';
                    else
                        dp[i][j][isTrue] = exp[i] == 'F';
                    continue;
                }

                ll ways = 0;
                for (int k = i + 1; k <= j - 1; k += 2)
                {
                    ll ft = dp[i][k - 1][1];
                    ll ff = dp[i][k - 1][0];
                    ll st = dp[k + 1][j][1];
                    ll sf = dp[k + 1][j][0];

                    if (exp[k] == '|' && isTrue)
                        ways += ((ft * st) % mod + (ft * sf) % mod + (ff * st) % mod) % mod;
                    else if (exp[k] == '|' && !isTrue)
                        ways += (ff * sf) % mod;
                    else if (exp[k] == '&' && isTrue)
                        ways += (ft * st) % mod;
                    else if (exp[k] == '&' && !isTrue)
                        ways += ((ff * sf) % mod + (ff * st) % mod + (ft * sf) % mod) % mod;
                    else if (exp[k] == '^' && isTrue)
                        ways += ((ft * sf) % mod + (ff * st) % mod) % mod;
                    else if (exp[k] == '^' && !isTrue)
                        ways += ((ff * sf) % mod + (ft * st) % mod) % mod;
                }
                dp[i][j][isTrue] = ways % mod;
            }
        }
    }
    return dp[0][n - 1][1];
}