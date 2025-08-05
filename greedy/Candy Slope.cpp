#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
//cash child ->at least one candy
//Chhildren with higher rating has> neighbour
int candy(vector<int>& ratings)
{
    int n=ratings.size();
    vector<int> left(n);
    vector<int> right(n);
    left[0]=1;
    right[n-1]=1;
    for(int i=1;i<n;i++)
    {
        if(ratings[i]>ratings[i-1])
        {
            left[i]=left[i-1]+1;
        }
        else{
            left[i]=1;
        }
    }
    for(int i=n-2;i>=0;i--)
    {
        if(ratings[i]>ratings[i+1])
        {
            right[i]=right[i+1]+1;
        }
        else{
            right[i]=1;
        }
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+max(left[i],right[i]);
    }
    return sum;
}
//Time compleity is O(3N)
//Space complexity is O(2N)

//Space Optimised
int candy(vector<int>& ratings)
{
    int n=ratings.size();
    if(n==0)
    {
        return 0;
    }
    vector<int> candies(n,1);
    for(int i=1;i<n;i++)
    {
        if(ratings[i]>ratings[i-1])
        {
            candies[i]=candies[i-1]+1;
        }
    }
    for(int i=n-2;i>=0;i--)
    {
        if(ratings[i]>ratings[i+1])
        {
            candies[i]=max(candies[i],candies[i+1]+1);
        }
    }
    return accumulate(candies.begin(),candies.end(),0);
}

int candy(vector<int>& ratings)
{
    int n=ratings.size();
    int sum=1;
    int i=1;
    while(i<n)
    {
        if(ratings[i]==ratings[i-1])
        {
            sum=sum+1;
            i++;
            continue;
        }
        int peak=1;
        while(i<n && ratings[i]>ratings[i-1])
        {
            peak+=1;
            sum+=peak;
            i++;
        }
        int down=1;
        while(i<n && ratings[i]<ratings[i-1])
        {
            sum+=down;
            i++;
            down++;
        }
        if(down>peak)
        {
            sum+=down-peak;
        }
    }
    return sum;
}
//Time complexity is O(N)
//Space complexity is O(1)