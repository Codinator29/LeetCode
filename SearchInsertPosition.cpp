/*

https://leetcode.com/problems/search-insert-position/

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() == 0)
        {
            return 0;
        }
        
        return searchHelper(nums, 0, nums.size() - 1, target);
    }
    
    int searchHelper(vector<int>& nums, int start, int end, int target)
    {
        while(start <= end)
        {
            int mid = (start + end) / 2;
            
            if(nums[mid] == target)
            {
                return mid;
            }
            
            if(nums[mid] > target)
            {
                end = mid - 1;
            }
            
            if(nums[mid] < target)
            {
                start = mid + 1;
            }
        }
        
        return start;
    }
};