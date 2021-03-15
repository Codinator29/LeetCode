/*

https://leetcode.com/problems/contains-duplicate/

Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        
        for(auto &i: nums)
        {
            if(set.find(i) != set.end())
            {
                return true;
            }
            else{
                set.insert(i);
            }
        }
        
        return false;
    }
};