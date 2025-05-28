#include<iostream>
using namespace std;
int main()
{
    vector<int> arr={1,2,3,4,5};
    int temp=arr[0];
    int n=arr.size();
    for(int i=1;i<arr.size();i++)
    {
        arr[i-1]=arr[i];//It shifts all the numbers to one position left
    }
    arr[n-1]=temp;
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}
//Time complexity is O(N)
//Space complexity is O(1) [Extra space] and we are using an array is O(N)
