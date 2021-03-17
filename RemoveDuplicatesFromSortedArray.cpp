/*

https://leetcode.com/problems/remove-duplicates-from-sorted-array/

Given a sorted array nums, remove the duplicates in-place such that each element appears only once and returns the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

*/

class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int n = a.size();
        if(n<=1) return a.size();
        int j = 0;
        for(int i=1;i<n;i++)
        {
            if(a[i]!=a[j])
            {
                a[++j] = a[i];
            }
        }
        return j+1;
    }
};