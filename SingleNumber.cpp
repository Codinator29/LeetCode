/*

https://leetcode.com/problems/single-number/

Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

Follow up: Could you implement a solution with a linear runtime complexity and without using extra memory?

*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int num = nums[0];
        
        for(int i = 1; i < nums.size(); i++)
        {
            num = num ^ nums[i];
        }
        
        return num;
    }
};