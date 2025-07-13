#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
using namespace std;
//Memoization-Tend to store the value of sub problems in some map/table
//Factorial using Dynamic programming
//Memoization
int factorial(int n,vector<int>&dp)
{
    if(n<=1)
    {
        return n;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    return dp[n]=factorial(n-1,dp)+factorial(n-2,dp);
}
int main()
{
    int n;
    cin>>n;
    vector<int> dp(n,-1);
    cout<<factorial(n,dp);
    return 0;
}
//Time complexity is O(N)

//Tabulation-Bottom Up approach
//Base case to the required ans

int main()
{
    int n;
    cin>>n;
    int prev2=0;
    int prev1=1;
    for(int i=2;i<=n;i++)
    {
        int curi=prev2+prev1;
        prev2=prev1;
        prev1=curi;
    }
    cout<<prev1<<endl;
    return 0;
}
//Time complexity is O(N)
//Space complexity is O(N)
