#include<iostream>
using namespace std;
#include<vector>
#include<set>
//Brute force approach
int main()
{
    vector<int> arr1={1,1,2,3,4,5};
    vector<int> arr2={2,3,4,4,5};
    int n1=arr1.size();
    int n2=arr2.size();
    set<int> st;
    for(int i=0;i<n1;i++)//O(N1logN1)
    {
        st.insert(arr1[i]);
    }
    for(int i=0;i<n2;i++)//O(N2logN2)
    {
        st.insert(arr2[i]);
    }
    vector<int> unionArr(st.size());//O(n1+n2) for the worst case
    int i=0;
    for(auto it:st)
    {
        unionArr[i++]=it;
    }
    /* Accessing elements through set directly
    set<int>::iterator itr;
    for(itr=st.begin();itr!=st.end();itr++)
    {
        cout<<*itr<<" ";
    }*/
   for(int i=0;i<unionArr.size();i++)
   {
        cout<<unionArr[i]<<endl;
   }
}
//Time complexity is O(n1logn + n2logn)+O(n1+n2)
//Space complexity is O(n1+n2) + O(n1+n2)[To return the answer]

//Optimal approach
//2 pointer approach
vector<int> sortedArray(vector<int> a,vector<int> b)
{
    int n1=a.size();
    int n2=b.size();
    int i=0;
    int j=0;
    vector<int> unionArr;
    while(i<n1 && j<n2)
    {
        if(a[i]<=b[j])
        {
            if(unionArr.back()!=a[i]||unionArr.size()==0)
            {
                unionArr.push_back(a[i]);
            }
            i++;
        }
        else{
            if(unionArr.size()==0||unionArr.back()!=b[j])
            {
                unionArr.push_back(b[j]);
            }
            j++;
        }
    }
    while(j<n2)
    {
        if(unionArr.size()==0||unionArr.back()!=b[j])
        {
            unionArr.push_back(b[j]);
        }
        j++;
    }
    while(i<n1)
    {
        if(unionArr.size()==0||unionArr.back()!=a[i])
        {
            unionArr.push_back(a[i]);
        }
        j++;
    }
    return unionArr;
}
//Time complexity of this code is O(n1+n2)
//Space complexity is O(n1+n2)[No extra space is used]

//Intersection-Elements present in both arrays
//Brute force approach
int main()
{
    vector<int> A={1,2,2,3,3,4,5,6};
    vector<int> B={2,3,3,5,6,6,7};
    int n1=A.size();
    int n2=B.size();
    vector<int> vis(n2,0);
    vector<int> ans;
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n2;j++)
        {
            if(A[i]==B[j] && vis[j]==0)
            {
                ans.push_back(A[i]);
                vis[j]=1;
                break;
            }
            if(B[j]>A[i])
            {
                break;
            }
        }
    }
    set<int> st(ans.begin(),ans.end());
    vector<int> ans2(st.begin(),st.end());
    for(int i=0;i<ans2.size();i++)
    {
        cout<<ans2[i]<<endl;
    }
    return 0;
}
//Time complexity is O(n1*n2)
//Space complexity is O(n2)

//Optimal approach
//2 pointer approach
vector<int> findArrayIntersection(vector<int> &A,int n,vector<int> &B,int m)
{
    int i=0;
    int j=0;
    vector<int> ans;
    while(i<n && j<m)
    {
        if(A[i]<B[j])
        {
            i++;
        }
        else if(B[j]<A[i])
        {
            j++;
        }
        else{
            ans.push_back(A[i]);
            i++;
            j++;
        }
    }
    return ans;
}