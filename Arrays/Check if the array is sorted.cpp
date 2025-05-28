//Brute force approach
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> A={1,2,2,3,3,4};
    for(int i=1;i<A.size();i++)
    {
        if(A[i]>=A[i-1])
        {

        }
        else{
            cout<<0<<endl;
        }
    }
    cout<<1<<endl;
}