/*

https://leetcode.com/problems/sort-colors/

Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        //sort(nums.begin(), nums.end());
        
        int p1   = 0;
        int p2   = nums.size() - 1;
        int curr = 0;
        
        while(curr <= p2){
            if(nums.at(curr) == 0)
                swap(nums.at(curr++), nums.at(p1++));
            
            else if(nums.at(curr) == 2)
                swap(nums.at(curr), nums.at(p2--));
            
            else 
                curr++;
        }
    }
};