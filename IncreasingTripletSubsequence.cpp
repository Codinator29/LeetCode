/*

https://leetcode.com/problems/increasing-triplet-subsequence/

Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.

*/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int num_i = INT_MAX, num_j = INT_MAX;
        for(auto n: nums){
            if(n < num_i)
                num_i = n;
            else if(n > num_i && n < num_j)
                num_j = n;
            else if(n > num_j)
                return true;
        }
        return false;
    }
};