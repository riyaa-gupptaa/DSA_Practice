//First we will look at the brute force approach. It says to sort the elements first and then search for the kth largest or smallest element
#include<iostream>
using namespace std;
/*
int main()
{
    vector<int> arr={1,2,2,6,5,4};
    int n=arr.size();
    sort(arr.begin(),arr.end());
    //supposed we need second largest element
    int secondL=arr[n-2];
    cout<<secondL<<endl;
    //we will get 5 as output which is correct
}*/
//The problem with the brute force approach is with the time complexity
//time complexity is O(NlogN)
//Space complexity is O(N)

//Now let's look at the better approach
/*
int main()
{
    vector<int> arr={1,2,2,6,5,4};
    int n=arr.size();
    int largest=arr[n-1];
    int secondL=-1;
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]!=largest)
        {
            secondL=arr[i];
            break;
        }
    }
    cout<<secondL<<endl;
}*/
//The problem is that even if the elements are same, it will traverse the full array
//Time complexity will be O(N)
//Space complexity is O(1)

//Now we will look for another approach
/*
int main()
{
    vector<int> arr={1,2,4,7,7,5};
    int largest=arr[0];
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]>largest)
        {
            largest=arr[i];
        }
    }
    int Slargest=-1;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]>Slargest && arr[i]!=largest)
        {
            Slargest=arr[i];
        }
    }
    cout<<Slargest<<endl;
}
//Time complexity is O(N+N)=O(2N)
*/
//Optimal approach
//We find both Second largest and second smallest
int secondLargest(vector<int> &arr,int n)
{
    int largest=arr[0];
    int slargest=-1;//If all elements are negative, then use INT_MIN
    for(int i=1;i<n;i++)
    {
        if(arr[i]>largest)
        {
            slargest=largest;
            largest=arr[i];
        }
        else if(arr[i]<largest && arr[i]>slargest)
        {
            slargest=arr[i];
        }
    }
    return slargest;
}
int secondSmallest(vector<int> &arr,int n)
{
    int smallest=arr[0];
    int ssmallest=INT_MAX;
    for(int i=1;i<n;i++)
    {
        if(arr[i]<smallest)
        {
            ssmallest=smallest;
            smallest=arr[i];
        }
        else if(arr[i]>smallest && arr[i]<ssmallest)
        {
            ssmallest=arr[i];
        }
    }
    return ssmallest;
}
int main()
{
    vector<int> arr={1,2,4,7,7,5};
    int n=arr.size();
    int slargest=secondLargest(arr,n);
    int ssmallest=secondSmallest(arr,n);
    cout<<slargest<<endl;
    cout<<ssmallest<<endl;
}
//Time complexity is O(N)
//Space complexity is O(1)