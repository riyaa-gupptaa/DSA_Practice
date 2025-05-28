//Brute force approach
//Set dataset cannot have duplicate elements
#include<iostream>
using namespace std;
#include<set>
/*
int main()
{
    set<int> st;
    vector<int> arr={1,1,2,2,2,3,3};
    for(int i=0;i<arr.size();i++)
    {
        st.insert(arr[i]);
    }
    int index=0;
    for(auto it:st)
    {
        arr[index]=it;//Inserts all the elements back to the array after removing duplicate elements from the array
        index++;
    }
}*/
//Time complexity is O(N logN)+N
//Space complexity is O(N)

//Optimal Solution
//We will use a two pointer approach
int main()
{
    vector<int> arr={1,1,2,2,2,3,3};
    int i=0;
    for(int j=1;j<arr.size();j++)
    {
        if(arr[j]!=arr[i])
        {
            arr[i+1]=arr[j];
            i++;
        }
    } 
    cout<<i+1<<endl;
}
//Time complexity is O(N)
//Space complexity is O(1)
