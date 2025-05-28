 //Largest Element in an Array
 //Brute Force approach
 #include<iostream>
 using namespace std;
 #include<vector>
 /*
 int main()
 {
    vector<int> arr={1,2,3,2,4,5};
    int n=arr.size();
    sort(arr.begin(),arr.end());
    //Accessing the largest element after sorting
    cout<<arr[n-1]<<endl;
 }*/
 //The problem with the brute force approach is that it takes a:
 //Time complexity of O(NLogN);
 //Space complexity of O(1)
 
 //Let's move to the better approach
 int main()
 {
    vector<int> arr={1,3,2,5,4,2};
    int n=arr.size();
    int largest=arr[0];
    for(int i=0;i<n;i++)
    {
        if(arr[i]>largest)
        {
            largest=arr[i];
        }
    }
    cout<<largest<<endl;
 }
 //The better appraoch assumes a largest element and compares it with the other elements of the array.
 //The time complexity is O(N)
 //Space complexity is O(1)
 

