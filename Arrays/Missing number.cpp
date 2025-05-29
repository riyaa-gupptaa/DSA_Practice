#include<iostream>
using namespace std;
#include<vector>
#include<set>
//Brute force approach
int main()
{
    vector<int> arr={1,2,3,4,6,7,8,9};
    int n=arr.size();
    for(int i=1;i<=n;i++)
    {
        int flag=0;
        for(int j=0;j<n;j++)
        {
            if(arr[j]==i)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            cout<<i<<endl;
        }
    }
}
//Time complexity is O(N*N)
//Space complexity is O(1)

//Better approach
//We will use hashing
int main()
{
    vector<int> arr={1,2,3,5,6,7};
    int n=arr.size();
    vector<bool> hash(n+1,false);
    for(int num:arr)
    {
        hash[num]=false;
    }
    for(int i=1;i<=n;i++)
    {
        if(!hash[i])
        {
            cout<<i<<endl;
        }
    }
    cout<<-1<<endl;
}

//Optimal approach
int main()
{
    vector<int> arr={1,2,4,5};
    int n=arr.size();
    int sum=(n*(n+1))/2;
    int s2=0;
    for(int i=0;i<n;i++)
    {
        s2+=arr[i];
    }
    cout<<sum-s2<<endl;
}
// We can do similar work using XOR operation
int main()
{
    vector<int> arr={1,2,4,5};
    int n=arr.size();
    int XOR1=0;
    for(int i=1;i<=n;i++)
    {
        XOR1=XOR1^i;
    }
    int XOR2=0;
    for(int i=0;i<n;i++)
    {
        XOR2=XOR2^arr[i];
    }
    cout<<(XOR1^XOR2)<<endl;
}
//Time complexity is O(N)