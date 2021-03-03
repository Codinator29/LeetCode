/*

https://leetcode.com/problems/median-of-two-sorted-arrays/

Median of Two Sorted Arrays

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
Example 3:

Input: nums1 = [0,0], nums2 = [0,0]
Output: 0.00000
Example 4:

Input: nums1 = [], nums2 = [1]
Output: 1.00000
Example 5:

Input: nums1 = [2], nums2 = []
Output: 2.00000

*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int mid = 0;
        int i = 0, j = 0, k = 0;
        bool isEven = false;
        
        vector<int> resultArray;
        
        int totalsize = m + n;
        
        if(totalsize % 2 == 0)
        {
            isEven = true;
        }
        
        mid = (totalsize + 1) / 2;
        
        while(i < m && j < n)
        {
            if(nums1[i] < nums2[j])
            {
                resultArray.push_back(nums1[i]);
                i++;
            }
            else
            {
                resultArray.push_back(nums2[j]);
                j++;
            }
            k++;
            
            if(k >= mid + 1)
            {
                if(isEven)
                {
                    return (resultArray[mid] + resultArray[mid - 1] )/ 2.0;
                }
                else
                {
                    return resultArray[mid - 1];
                }
            }
        }
        
        while(i < m && k <= mid + 1)
        {
            resultArray.push_back(nums1[i]);
            i++;
            k++;
        }
        
        while(j < n && k <= mid + 1)
        {
            resultArray.push_back(nums2[j]);
            j++;
            k++;
        }
        
        if(isEven)
        {
            return (resultArray[mid] + resultArray[mid - 1]) / 2.0;
        }
        else
        {
            return resultArray[mid - 1];
        }

    }
};
