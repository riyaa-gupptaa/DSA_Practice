#include<iostream>
#include<vector>
#include<map>
using namespace std;
//Without using extra space.
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    long long arr3[n + m];
    int left=0; 
    int right = 0;
    int index = 0;

    // Merge both arrays
    while (left < m && right < n)
    {
        if (nums1[left] <= nums2[right])
        {
            arr3[index++] = nums1[left++];
        }
        else
        {
            arr3[index++] = nums2[right++];
        }
    }

    // Copy remaining elements of nums1
    while (left < m)
    {
        arr3[index++] = nums1[left++];
    }

    // Copy remaining elements of nums2
    while (right < n)
    {
        arr3[index++] = nums2[right++];
    }

    // Write back to nums1
    for (int i = 0; i < m + n; i++)
    {
        nums1[i] = arr3[i];
    }
}
//Time complexity is O(n+m)+O(n+m)
//Space complexity is O(n+m)

//Wihtout extra space
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    int left=m-1;
    int right=0;
    while(left>=0 && right<n)
    {
        if(nums1[left]>=nums2[right])
        {
            swap(nums1[left],nums2[right]);
            left--;
            right++;
        }
        else{
            break;
        }
    }
    sort(nums1.begin(),nums1.begin()+m);
    sort(nums2.begin(),nums2.begin()+n);
}
//Time complexity is O(min(n,m))+O(nlogn)+O(mlogm)
//No extra space

//Gap method -shell sort
void swap1Greater(vector<int> &nums1,vector<int> &nums2,int ind1,int ind2)
{
    if(nums1[ind1]>nums2[ind2])
    {
        swap(nums1[ind1],nums2[ind2]);
    }
}
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int len = m + n;
    int gap = (len / 2) + (len % 2); // initial gap

    while (gap > 0) {
        int left = 0;
        int right = left + gap;

        while (right < len) {
            // Case 1: both pointers in nums1
            if (left < m && right < m) {
                if (nums1[left] > nums1[right]) {
                    swap(nums1[left], nums1[right]);
                }
            }
            // Case 2: left in nums1, right in nums2
            else if (left < m && right >= m) {
                if (nums1[left] > nums2[right - m]) {
                    swap(nums1[left], nums2[right - m]);
                }
            }
            // Case 3: both pointers in nums2
            else if (left >= m) {
                if (nums2[left - m] > nums2[right - m]) {
                    swap(nums2[left - m], nums2[right - m]);
                }
            }

            left++;
            right++;
        }

        // Update gap
        gap = (gap == 1) ? 0 : (gap / 2 + gap % 2);
    }

    // Copy nums2 back to nums1
    for (int i = 0; i < n; i++) {
        nums1[m + i] = nums2[i];
    }
}
//Time complexity is log2(n*m)*O(n*m)
//Space complexity is constant