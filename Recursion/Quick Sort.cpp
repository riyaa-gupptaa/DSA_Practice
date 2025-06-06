#include<iostream>
#include<vector>
using namespace std;
//Pick a pivot and place it in its current place in the sorted array
//Smaller on the left and larger on the right
//We will stop when j crosses i
int f(vector<int> arr,int low,int high)
{
    int pivot=arr[low];
    int i=low;
    int j=high;
    while(i<j)
    {
        while(arr[i]<=pivot && i<=high)
        {
            i++;
        }
        while(arr[j]>pivot && j>=low)
        {
            j--;
        }
        if(i<j)
        {
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[low],arr[j]);
    return j;
}
void quickSort(vector<int> &arr,int low,int high)
{
    if(low<high)
    {
      int partition =f(arr,low,high);
      quickSort(arr,low,partition-1);
      quickSort(arr,partition+1,high);
    }
}
int main()
{
    vector<int> arr={4,6,2,5,7,9,1,3};
    int n=arr.size();
    quickSort(arr,0,n-1);
}
//Time complexity is O(NlogN)
//As we are dividing and merging
//Space complexity is O(1)