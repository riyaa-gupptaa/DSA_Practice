#include<iostream>
#include<vector>
#include<map>
using namespace std;
//In this case the positives are not equal to the negatives
//Either the positives are greater than negatives or vice versa
//Brute force approach
vector<int> alternateNumbers(vector<int> &a)
{
    int n=a.size();
    vector<int> pos,neg;
    for(int i=0;i<n;i++)
    {
        if(a[i]>0)
        {
            pos.push_back(a[i]);
        }
        else{
            neg.push_back(a[i]);
        }
    }
    if(pos.size()>neg.size())
    {
        for(int i=0;i<neg.size();i++)
        {
            a[2*i]=pos[i];
            a[2*i+1]=neg[i];
        }
        int index=neg.size()*2;
        for(int i=neg.size();i<pos.size();i++)
        {
            a[index]=pos[i];
            index+=1;
        }
    }
    else{
        for(int i=0;i<pos.size();i++)
        {
            a[2*i]=pos[i];
            a[2*i+1]=neg[i];
        }
        int index=pos.size()*2;
        for(int i=pos.size();i<neg.size();i++)
        {
            a[index]=neg[i];
            index+=1;
        }
    }
    return a;
}
int main()
{
    vector<int> a={-1,2,3,4,-3,1};
    vector<int> ans=alternateNumbers(a);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }
}
//Time complexity is O(N)+O(min(pos,neg))+O(leftovers)
//Worst time complexity is O(N)+O(N)
