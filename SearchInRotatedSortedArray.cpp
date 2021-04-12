/* 

https://leetcode.com/problems/search-in-rotated-sorted-array/

There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0)
        {
            return -1;
        }
        return searchHelper(nums, 0, nums.size() - 1, target);
    }
    
    int searchHelper(vector<int>& nums, int start, int end, int target)
    {
        if(start == end && nums[start] != target)
        {
            return -1;
        }
        
        int mid = (start + end) / 2;
        
        if(nums[mid] == target)
        {
            return mid;
        }
        
        if(nums[start] <= nums[mid])
        {
            if(target >= nums[start] && target <= nums[mid])
            {
                return searchHelper(nums, start, mid - 1, target);
            }
            else
            {
                return searchHelper(nums, mid + 1, end, target);
            }
        }
        
        if(nums[start] > nums[mid])
        {
            if(target >= nums[mid] && target <= nums[end])
            {
                return searchHelper(nums, mid + 1, end, target);
            }
            else
            {
                return searchHelper(nums, start, mid - 1, target);
            }
        }
        return -1;
    }
};