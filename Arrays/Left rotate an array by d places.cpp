#include<iostream>
using namespace std;
#include<vector>
//Brute force approach
/*
int main()
{
    vector<int> arr={1,2,3,4,5,6,7};
    //Let's suppose d=3
    int d=3;
    d=d%arr.size();
    int temp[d];
    for(int i=0;i<d;i++)
    {
        temp[i]=arr[i];
    }
    for(int i=d;i<arr.size();i++)
    {
        arr[i-d]=arr[i];//{4,5,6,7,_,_,_}
    }
    //If we don't want to use extra variable
    /*
    int j=0;
    for(int i=arr.size()-d;i<arr.size();i++)
    {
        arr[i]=temp[j];//{4,5,6,7,1,2,3};
        j++;
    }
   //1 is at n-d, 2 is at (n-d)+1, 3 is at (n-d)+2
   for(int i=arr.size()-d;i<arr.size();i++)
   {
        arr[i]=temp[i-(arr.size()-d)];
   }
}
*/
//Time complexity is O(d)+O(n-d)+O(d)=O(n+d)
//Space complexity is O(d)[Extra space used]

//Optimal solution
void reverse(vector<int> &arr,int start,int end)
{
    while(start<=end)
    {
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
}
int main()
{
    vector<int> arr={1,2,3,4,5,6,7};
    int d=3;
    d=d%arr.size();
    int n=arr.size();
    //we will use the concept of reversing
    //reverse(a,a+d) Time complexity is O(d)
    //reverse(a+d,a+n) Time complexity is O(n-d)
    //reverse(a,a+n) Time complexity is O(n)
    reverse(arr,0,d-1);
    reverse(arr,d,n-1);
    reverse(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}
//Overall complexity is O(2n)
//We are not using any extra space
