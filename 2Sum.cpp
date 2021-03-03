/* 

https://leetcode.com/problems/two-sum/

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        
        unordered_map<int, int> set;
        
        for(int i = 0; i < nums.size(); i++)
        {
            int diff = target - nums[i];
            
            if(set.find(diff) == set.end())
            {
                set[nums[i]] = i;
            }
            else
            {
                result.push_back(set[diff]);
                result.push_back(i);
                break;
            }
        }
        return result;
    }
};