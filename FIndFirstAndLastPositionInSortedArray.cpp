/*

https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

Follow up: Could you write an algorithm with O(log n) runtime complexity?

*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;        
        int firstOccurrence = findBound(nums, target, true);
        
        if (firstOccurrence == -1) {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        
        int lastOccurrence = findBound(nums, target, false);
        
        result.push_back(firstOccurrence);
        result.push_back(lastOccurrence);
        return result;
    }
    
    int findBound(vector<int> &nums, int target, bool isFirst) {
        int N = nums.size();
        int begin = 0, end = N - 1;
        
        while (begin <= end) {
            
            int mid = (begin + end) / 2;
            
            if (nums[mid] == target) {
                
                if (isFirst) {
                    
                    // This means we found our lower bound.
                    if (mid == begin || nums[mid - 1] != target) {
                        return mid;
                    }
                    
                    // Search on the left side for the bound.
                    end = mid - 1;
                    
                } else {
                    
                    // This means we found our upper bound.
                    if (mid == end || nums[mid + 1] != target) {
                        return mid;
                    }
                    
                    // Search on the right side for the bound.
                    begin = mid + 1;
                }
                
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                begin = mid + 1;
            }
        }
        
        return -1;
    }
};