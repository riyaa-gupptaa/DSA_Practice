#include<iostream>
#include<vector>
#include<map>
using namespace std;
//Brute force approach
//Generate all permutations in a sorted order
//Do linear search
//Return next index then it's the answer
//Time complexity will be at minimum [N!*N]

//Using STL library
vector<int> nextGreaterPermutation(vector<int> &A)
{
    next_permutation(A.begin(),A.end());
    return A;
}

//Optimal Solution
//Longer prefix match
//Find the break point that is when a[i]<a[i+1]
vector<int> nextGreaterPermutation(vector<int> &A)
{
    int ind=-1;
    int n=A.size();
    for(int i=n-2;i>=0;i--)
    {
        if(A[i]<A[i+1])
        {
            ind=i;
            break;
        }
    }
    if(ind==-1)
    {
        reverse(A.begin(),A.end());
        return A;
    }
    for(int i=n-1;i>ind;i--)
    {
        if(A[i]>A[ind])
        {
            swap(A[i],A[ind]);
            break;
        }
    }
    reverse(A.begin()+ind+1,A.end());
    return A;
}
//Time complexity is O(3N)
//Space complexity is O(1)