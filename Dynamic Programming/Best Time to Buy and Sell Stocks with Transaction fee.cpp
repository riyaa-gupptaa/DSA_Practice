#include<iostream>
#include<vector>
#include<map>
using namespace std;
//A fee for each transaction will be deducted from the profit
int maximumProfit(int n,int fee,vector<int> &prices)
{
    int aheadNotBuy,aheadBuy,currBuy,currNotBuy;
    aheadNotBuy=aheadBuy=0;
    for(int ind=n-1;ind>=0;ind--)
    {
        //sell
        currNotBuy=max(prices[ind]+aheadBuy-fee,0+aheadNotBuy);
        currBuy=max(-prices[ind]+aheadNotBuy,0+aheadBuy);
        aheadBuy=currBuy;
        aheadNotBuy=currNotBuy;
    }
    return aheadBuy;
}
